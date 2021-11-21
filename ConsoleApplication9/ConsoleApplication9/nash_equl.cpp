// OADM1.cpp : Defines the entry point for the console application.
//
#include <iostream>

int max(int a, int b, int c) {			//function to find maximum
	if (a > b) {
		if (a > c) {
			return (a);
		}
		else {
			return c;
		}
	}
	else if (b > c) {
		return b;
	}
	else return c;
}

int main()
{
	/*int D1[3][3] = {
		{ 10,3,1 },
		{ 4,0,-5 },
		{ -5,18,9 }
	};

	int D2[3][3] = {
		{ 23,3,0 },
		{ -3,56,2 },
		{ 1,-6,56 }
	}; */

	int D1[3][3] = {
		{ 2,3,4}, {6,2,8}, {10,5,12}
	};
	int D2[3][3] = {
		{1,4,1}, {5,8,3}, {2,6,7}
	};
	int d1[3][3] = {
		{
			0,0,0
		},
		{
			0,0,0
		},
		{
			0,0,0
		}
	};

	int d2[3][3] = {
		{
			0,0,0
		},
		{
			0,0,0
		},
		{
			0,0,0
		}
	};
	int cMax1, cMax2, cMax3, rMax1, rMax2, rMax3;
	//test of max function
	//int maxim;
	//maxim = max(5, 5, 3);
	//std::cout << "Maximum = " << maxim << std::endl;
	int row = 0;
	int col = 0;
	bool end = false;
	while (!end) {
		int a = 0, b = 0, c = 0;
		//D1
		//CHECK FOR MAXIMUMS IN THE COLUMNTS FOR D1
		while (col <= 2) {
			a = D1[row++][col];
			b = D1[row++][col];
			c = D1[row][col];
			int i, j;
			if (col == 0) {					// if column is 1 then we put maximum in first var cMax1 
				j = 0;
				cMax1 = max(a, b, c);
				//we get number of row where the maximum is
				if (cMax1 == a) {
					i = 0;
					d1[i][j] = 1;
				}
				if (cMax1 == b) {
					i = 1;
					d1[i][j] = 1;
				}
				if (cMax1 == c) {
					i = 2;
					d1[i][j] = 1;
				}
			}
			if (col == 1) {					// column = 2
				j = 1;
				cMax2 = max(a, b, c);

				if (cMax2 == a) {
					i = 0;
					d1[i][j] = 1;
				}
				if (cMax2 == b) {
					i = 1;
					d1[i][j] = 1;
				}
				if (cMax2 == c) {
					i = 2;
					d1[i][j] = 1;
				}
			}
			if (col == 2) {					// column = 3
				j = 2;
				cMax3 = max(a, b, c);
				if (cMax3 == a) {
					i = 0;
					d1[i][j] = 1;
				}
				if (cMax3 == b) {
					i = 1;
					d1[i][j] = 1;
				}
				if (cMax3 == c) {
					i = 2;
					d1[i][j] = 1;
				}

			}
			col++;
			row = 0;
		}
		row = 0;
		col = 0;
		//D2
		//CHECK FOR MAXIMUMS OF ROWS FOR D2
		while (row <= 2) {
			a = D2[row][col++];
			b = D2[row][col++];
			c = D2[row][col];
			int i, j;
			if (row == 0) {
				i = 0;
				rMax1 = max(a, b, c);
				if (rMax1 == a) {
					j = 0;
					d2[i][j] = 1;
				}
				if (rMax1 == b) {
					j = 1;
					d2[i][j] = 1;
				}
				if (rMax1 == c) {
					j = 2;
					d2[i][j] = 1;
				}
			}
			if (row == 1) {
				i = 1;
				rMax2 = max(a, b, c);
				if (rMax2 == a) {
					j = 0;
					d2[i][j] = 1;
				}
				if (rMax2 == b) {
					j = 1;
					d2[i][j] = 1;
				}
				if (rMax2 == c) {
					j = 2;
					d2[i][j] = 1;
				}

			}
			if (row == 2) {
				i = 2;
				rMax3 = max(a, b, c);
				if (rMax3 == a) {
					j = 0;
					d2[i][j] = 1;
				}
				if (rMax3 == b) {
					j = 1;
					d2[i][j] = 1;
				}
				if (rMax3 == c) {
					j = 2;
					d2[i][j] = 1;
				}
			}
			row++;
			col = 0;
		}

		end = true;
	}
	//MAXIMUM POINTS MARKED AS 1
/*	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			cout << d1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			cout << d2[i][j] << " ";
		}
		cout << endl;
	} */

	//TEST for equlibrium

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (d1[i][j] == 1 && d2[i][j] == 1) {
				int ab, ac;
				ab = i + 1;
				ac = j + 1;
				std:: cout << "Equlibrium at point i = " << ab << " j = " << ac << " ( " << D1[i][j] << "," << D2[i][j] << " ) " << std::endl;
			}
			else {

			}
		}
		std::cout << std::endl;
	}
	return 0;
}
