#include <iostream>
using namespace std;

int tab[2][2];

void optimize() {
	double p = tab[0][0] - tab[1][0] + 1;
	double p2;
	double i = (tab[1][0] - tab[0][1] - tab[1][1]) * (-1);
	p = i / p;
	p2 = 1 - p;

	cout << "Optimal row strategies: P1 = " << p << ", P2 = " << p2 << "\n";

	double q = tab[0][0] - tab[0][1] - tab[1][0] + tab[1][1];
	double q2;
	double j = (tab[0][1] - tab[1][1]) * (-1);
	q = j / q;
	q2 = 1 - q;

	cout << "Optimal column strategies: Q1 = " << q << ", Q2 = " << q2 << "\n";

	double result = p * q * tab[0][0] + p * q2 * tab[0][1] + p2 * q * tab[1][0] + p2 * q2 * tab[1][1];
	cout << "Value for this game: " << result << "\n";
}

int main() {

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "Enter matrix[" << i << "][" << j << "] element: ";
			cin >> tab[i][j];
		}
	}

	/*tab[0][0] = 2;
	tab[0][1] = 8;
	tab[1][0] = 10;
	tab[1][1] = 1;*/

	cout << "\nGame: \n"
		<< "+----+----+\n";
	cout << "+ " << tab[0][0];
	if (tab[0][0] < 10) cout << " ";
	cout << " | " << tab[0][1];
	if (tab[0][1] < 10) cout << " ";
	cout << " |\n+----+----+\n";
	cout << "| " << tab[1][0] << " ";
	if (tab[1][0] < 10) cout << " ";
	cout << "| " << tab[1][1] << " ";
	if (tab[1][1] < 10) cout << " ";
	cout << "|\n+----+----+\n\n";
}