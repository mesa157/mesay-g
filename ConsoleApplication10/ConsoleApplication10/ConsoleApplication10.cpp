#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

struct Result
{
	std::vector<double> xs;
	double value;
};

std::ostream& operator<<(std::ostream& os, const Result& res)
{
	const char delim = res.xs.size() < 7 ? '\t' : '\n';
	for (std::size_t i = 0; i < res.xs.size(); ++i)
	{
		os << 'x' << i + 1 << ": " << res.xs[i] << delim;
	}
	return os << "value: " << res.value;
}

class SimplexSolver
{
private:
	std::vector<std::vector<double>> tableau;
	std::size_t rows;
	std::size_t columns;
	const std::size_t init_x;
	const bool neg_res_max; ///< The original problem was maximising, negate the result to show the result of maximisng the original expression, not the one of minimising the negated one
	bool solved = false;
	Result result;

	/**
	 * @brief Checks if all columns have the same number of rows and sets appropriate member variable
	 *
	 * @throw std::invalid_argument if the matrix is invalid
	 */
	void validate_matrix(const std::vector<double>& b, const std::vector<double>& c)
	{
		rows = tableau.at(0).size();
		const auto columns_n = tableau.size();
		for (std::size_t i = 1; i < columns_n; ++i)
		{
			if (tableau[i].size() != rows)
			{
				throw std::invalid_argument("All columns must have the same number of rows.");
			}
		}
		if (c.size() != columns_n)
		{
			throw std::invalid_argument("Vector c has a different number of elements than matrix A columns");
		}
		if (b.size() != rows)
		{
			throw std::invalid_argument("Vector b has a different number of elements than matrix A rows");
		}
	}

	/**
	 * @brief Calculates the position [m,n] of the pivot element
	 *
	 * @return The position [column, row] of the pivot element if it exists
	 */
	std::optional<std::pair<std::size_t, std::size_t>> find_pivot() const noexcept
	{
		// Find column (the greatest, positive number)
		std::size_t last_row_idx = rows - 1;
		std::size_t col_idx = 0;
		double col_val = tableau[0][last_row_idx];
		for (std::size_t i = 1; i < columns - 1; ++i)
		{
			const auto val = tableau[i][last_row_idx];
			if (val > 0.0 && val > col_val)
			{
				col_val = val;
				col_idx = i;
			}
		}
		if (col_val <= 0.0)
		{
			return std::nullopt;
		}
		// Find row (positive, smallest b/suggested_pivot ratio) in that column
		const auto& b_col = tableau.back();
		const auto& pivot_col = tableau[col_idx];
		std::size_t row_idx = 0;
		double div_res = pivot_col[0] > 0.0 ? b_col[0] / pivot_col[0] : INFINITY; // set INFINITY if the pivot is 0
		for (std::size_t i = 1; i < last_row_idx; ++i)
		{
			if (pivot_col[i] <= 0.0)
				continue;
			const auto c_div = b_col[i] / pivot_col[i];
			if (c_div < div_res)
			{
				div_res = c_div;
				row_idx = i;
			}
		}
		assert(tableau[col_idx][row_idx] > 0.0);
		// It's possible if all elements in the pivot column are 0 - div_res is initialised to inf
		// and in each iter the loop skips to the next element, leaving div_res == INFINITY
		if (div_res == INFINITY)
			return std::nullopt;
		assert(!(div_res == INFINITY || div_res == NAN || div_res == -INFINITY || div_res == -NAN));
		return std::make_pair<std::size_t, std::size_t>(std::move(col_idx), std::move(row_idx));
	}

	/**
	 * @brief Checks if this variable is a base variable, and which value is the value for it.
	 *
	 * @param col the column corresponding to this variable.
	 * @return The index of the result if it exists.
	 */
	static std::optional<std::size_t> is_base_idx(const std::vector<double>& col) noexcept
	{
		std::optional<std::size_t> one_pos = std::nullopt;
		for (std::size_t i = 0; i < col.size(); ++i)
		{
			const auto val = col[i];
			if (val == 0.0)
				continue;
			if (val == 1.0 && !one_pos.has_value())
			{
				one_pos = i;
				continue;
			}
			return one_pos;
		}
		return one_pos;
	}

	/**
	 * @brief Processes the final tableau and saves the result in the `result` member variable.
	 */
	void calculate_result() noexcept
	{
		std::vector<double> xs;
		xs.reserve(init_x);
		const auto& values = tableau.back();
		for (std::size_t i = 0; i < init_x; ++i)
		{
			auto idx_opt = SimplexSolver::is_base_idx(tableau[i]);
			if (idx_opt)
			{
				xs.push_back(values[idx_opt.value()]);
			}
			else
			{
				xs.push_back(0.0);
			}
		}
		result = { std::move(xs), values.back() };
		if (neg_res_max)
		{
			result.value *= -1;
		}
	}

public:
	friend std::ostream& operator<<(std::ostream&, const SimplexSolver&);
	/**
	 * @brief Construct a new Simplex Solver object.
	 *
	 * @param A The A MxN matrix. A[M-1][0] is the first value in the M-th column.
	 * @param b Vector b
	 * @param c Vector c
	 * @param max_org_c Indicates that the result should be negated, because the c vector is negated.
	 * Example: (Max ← 3*x_1 + 5*x_2) ⇒ (Min ← -3*x_1 - 5*x_2) and the passed vector c is [-3, -5],
	 * but the result should show the value of the original expression.
	 */
	SimplexSolver(const std::vector<std::vector<double>>& A, const std::vector<double>& b, const std::vector<double>& c, bool max_org_c = false, bool solve_now = true)
		: tableau(A), init_x(tableau.size()), neg_res_max(max_org_c)
	{
		validate_matrix(b, c);
		rows += 1;
		columns = tableau.size() + rows; // Extend the columns with additional ones
		tableau.resize(columns, std::vector<double>(rows, 0.0));
		for (std::size_t i = init_x; i < columns; ++i)
		{
			tableau[i][i - init_x] = 1; // Fill the additional elements with ones at appropriate place
		}
		tableau.back() = b;
		tableau.back().resize(rows, 0.0);
		for (std::size_t i = 0; i < c.size(); ++i)
		{
			tableau[i].resize(rows, -c[i]); // The last row is -cT
		}
		if (solve_now)
		{
			solve();
		}
	}

	/**
	 * @brief Get the result object. Solve it if the table has not yet been solved.
	 *
	 * @return The result of the optimisation.
	 */
	Result& get_result() noexcept
	{
		if (!solved)
			solve();
		return result;
	}

	/**
	 * @brief Solve the tableau
	 *
	 * @return A reference to SimplexSolver
	 */
	Result solve() noexcept
	{
		if (solved)
		{
			return get_result();
		}
#ifdef PRINT_TAB
		std::cout << "Initial table:\n"
			<< *this;
#endif
		// solve
		auto pivot_info = find_pivot();
		while (pivot_info.has_value())
		{
			auto [pivot_col, pivot_row] = pivot_info.value();
			auto pivot_val = tableau[pivot_col][pivot_row];
#ifdef PRINT_TAB
			std::cout << "Pivot column: " << pivot_col << " row: " << pivot_row << " value: " << pivot_val << '\n';
#endif
			assert(pivot_val > 0.0);
			auto tableau_copy = tableau;
			for (std::size_t i = 0; i < columns; ++i)
			{
				auto& column = tableau_copy[i];
				for (std::size_t j = 0; j < rows; ++j)
				{
					if (j == pivot_row)
					{
						column[j] /= pivot_val;
					}
					else
					{
						column[j] -= tableau[pivot_col][j] * tableau[i][pivot_row] / pivot_val;
						assert(column[j] != NAN && column[j] != -NAN);
					}
				}
			}
			tableau = std::move(tableau_copy);
			// Try to fix values being slightly off in pivot column - the result sholud be 1 for pivot and 0 everywhere else
			tableau[pivot_col] = std::vector<double>(rows, 0.0);
			tableau[pivot_col][pivot_row] = 1.0;
#ifdef PRINT_TAB
			std::cout << *this;
#endif
			pivot_info = find_pivot();
		}
		// END solve
		solved = true;
		calculate_result();
		return get_result();
	}
};

std::ostream& operator<<(std::ostream& os, const SimplexSolver& solver)
{
	for (std::size_t i = 0; i < solver.columns - 1; ++i)
		os << "\tx" << i + 1;
	os << "\tb\n";
	const auto flags = os.flags();
	// For a good formatting inside a table
	os << std::setw(6) << std::setprecision(3) << std::fixed;
	for (std::size_t r = 0; r < solver.rows - 1; ++r)
	{
		for (std::size_t c = 0; c < solver.columns; ++c)
			os << '\t' << solver.tableau[c][r];
		os << '\n';
	}
	os << "-c";
	for (std::size_t c = 0; c < solver.columns; ++c)
		os << '\t' << solver.tableau[c][solver.rows - 1];
	os << '\n';
	os.setf(flags); // Restore the original formatting
	return os;
}

/**
 * @brief Read a vector of values separated by `delim` char
 *
 * @param is input stream
 * @param delim delimeter used to separate values
 * @return std::vector<double>
 */
std::vector<double> read_vector(std::istream& is, char delim = '\n')
{
	std::vector<double> result;
	std::string num_buff;
	while (std::getline(is, num_buff, delim))
	{
		result.push_back(std::atof(num_buff.c_str()));
	}
	return result;
}

/**
 * @brief Reads a matrix from CSV input stream.
 *
 * @param is input stream containing values separated by ','
 * @return A [column][row] matrix
 */
std::vector<std::vector<double>> read_matrix(std::istream& is)
{
	std::string line_buff;
	std::getline(is, line_buff);
	std::istringstream iss(line_buff);
	const auto row = read_vector(iss, ',');
	const auto columns_n = row.size();
	std::vector<std::vector<double>> columns(columns_n);
	for (std::size_t i = 0; i < columns_n; ++i)
	{
		columns[i].push_back(row[i]);
	}
	while (std::getline(is, line_buff))
	{
		std::istringstream iss(line_buff);
		const auto row = read_vector(iss, ',');
		for (std::size_t i = 0; i < columns_n; ++i)
		{
			columns[i].push_back(row[i]);
		}
	}
	return columns;
}

int main()
{
	// min -x1-x2, 2x1+3x2<=12, 2x1+x2<=8
	// std::vector<std::vector<double>> A{{2.0, 2.0}, {3, 1}};
	// std::vector<double> b{12, 8.0};
	// std::vector<double> c{-1.0, -1.0};

	// SimplexSolver solver(A, b, c, true);

	std::ifstream Af("data/simplex/Set 4/A.csv");
	std::ifstream bf("data/simplex/Set 4/b.csv");
	std::ifstream cf("data/simplex/Set 4/c.csv");
	auto A = read_matrix(Af);
	auto b = read_vector(bf);
	auto c = read_vector(cf);

	SimplexSolver solver(A, b, c);

	std::cout << solver.get_result() << '\n';
	// Partially validate the solution.
#ifndef NDEBUG
	const auto res = solver.get_result();
	double sum = 0;
	for (std::size_t i = 0; i < res.xs.size(); ++i)
	{
		sum += res.xs[i] * c[i];
	}
	assert(std::abs(sum - res.value) < 0.0001); // This will fail if negating the result
#endif
	return 0;
}
