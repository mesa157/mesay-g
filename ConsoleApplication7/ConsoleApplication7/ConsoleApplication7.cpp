#include<iostream>
#include<math.h>


using namespace std;
int choice(int number, int f[9][2]);
int max(int tab[45][6], int number);


int choice(int number, int f[9][2])
{
	int column = 0;
	while (column <= 6)
	{
		if (f[column][1] == number)
		{
			return(f[column][0]);
		}
		column++;
	}
}

int max(int tab[45][6], int number)
{
	int row = 0;
	int greatest = 0;
	while (row <= 45)
	{
		if (tab[row][2] == number)
		{
			if (tab[row][5] >= greatest)
			{
				greatest = tab[row][5];
			}
		}
		row++;
	}
	return(greatest);
}

int main()
{
	int tab3[9][3];
	int tab2[45][6];
	int tab1[45][6];
	int tab0[9][6];

	// *********** ***********

	int f1[9][2] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 2 },
		{ 4, 3 },
		{ 6, 4},
		{ 8, 5 },
		{ 10, 6 },
		{ 12,7},
		{13, 8},

	};
	int f2[9][2] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 5, 2 },
		{ 6, 3 },
		{ 8, 4 },
		{ 10, 5 },
		{ 25, 6 },
		{25 ,7},
		{25 , 8},
	};
	int f3[9][2] = {
		{ 0, 0 },
		{ 2, 1 },
		{ 3, 2 },
		{ 6, 3 },
		{ 10, 4 },
		{ 12, 5},
		{ 14, 6},
		{ 14,7},
		{16,8},

	};
	int f4[9][2] = {
		{ 0, 0 },
		{ 4, 1},
		{ 5, 2 },
		{ 10, 3},
		{ 15, 4 },
		{ 16, 5 },
		{ 17, 6 },
		{18,7},
		{ 19,8},
	};

	// ***************** TABELI 1 ****************

	int row = 0;
	int column = 0;
	while (row <= 8)
	{
		tab3[row][column + 1] = f4[row][1];
		tab3[row][column] = 8 - tab3[row][column + 1];
		tab3[row][column + 2] = choice(tab3[row][column], f4);
		row++;
	}

	// ************** TABELI 1 ******************

	cout << "  TABLE 1\n" << endl;
	cout << "U3   X3   S3\n" << endl;

	row = 0;
	while (row <= 8)
	{
		cout << tab3[row][column] << "  ";
		if (tab3[row][column] < 1)
			cout << " ";
		if (tab3[row][column] < 2)
			cout << " ";

		cout << tab3[row][column + 1] << "  ";
		if (tab3[row][column + 1] < 1)
			cout << " ";
		if (tab3[row][column + 1] < 3)
			cout << " ";

		cout << tab3[row][column + 2];
		cout << endl;
		row++;
	}
	if (tab3[row - 1][1] == 8)
	{
		cout << "------------" << endl;
	}

	//  ****** TWORZENIE TABELI 2 **************

	row = 0;
	int rowf = 0;
	int rowu = 0;
	column = 2;
	int count = 0;

	while (row <= 44)
	{
		tab2[row][column] = f3[rowf][1];
		tab2[row][column - 1] = f3[rowu][1];
		tab2[row][column - 2] = tab2[row][column - 1] - tab2[row][column];
		tab2[row][column + 1] = tab3[rowu][2];
		tab2[row][column + 2] = choice(tab2[row][column - 2], f3);
		tab2[row][column + 3] = tab2[row][column + 2] + tab2[row][column + 1];

		row++;
		rowu++;
		if (tab2[row - 1][1] == 8)
		{
			count++;
			rowu = count;
			rowf++;
		}
	}

	//********** DRUKOWANIE TABELI 2  ********

	cout << "\n  TABLE 2\n" << endl;
	cout << "U2   X3   X2   S3   f3   S2\n" << endl;
	row = 0;
	while (row <= 27)
	{
		cout << tab2[row][column - 2] << "  ";
		if (tab2[row][column - 2] < 1)
			cout << " ";
		if (tab2[row][column - 2] < 3)
			cout << " ";

		cout << tab2[row][column - 1] << "  ";
		if (tab2[row][column - 1] < 1)
			cout << " ";
		if (tab2[row][column - 1] < 3)
			cout << " ";

		cout << tab2[row][column] << "  ";
		if (tab2[row][column] < 1)
			cout << " ";
		if (tab2[row][column] < 3)
			cout << " ";

		cout << tab2[row][column + 1] << "  ";
		if (tab2[row][column + 1] < 1)
			cout << " ";
		if (tab2[row][column + 1] < 3)
			cout << " ";

		cout << tab2[row][column + 2] << "  ";
		if (tab2[row][column + 2] < 1)
			cout << " ";
		if (tab2[row][column + 2] < 3)
			cout << " ";

		cout << tab2[row][column + 3] << endl;
		row++;

		if (tab2[row - 1][1] == 8)
		{
			cout << "----------------------------" << endl;
		}

	}


	//*************TABELI 3 ****************

	row = 0;
	rowf = 0;
	rowu = 0;
	column = 2;
	count = 0;

	while (row <= 44)
	{
		tab1[row][column] = f2[rowf][1];
		tab1[row][column - 1] = f2[rowu][1];
		tab1[row][column - 2] = tab1[row][column - 1] - tab1[row][column];
		tab1[row][column + 1] = max(tab2, tab1[row][column - 1]);
		tab1[row][column + 2] = choice(tab1[row][column - 2], f2);
		tab1[row][column + 3] = tab1[row][column + 2] + tab1[row][column + 1];

		row++;
		rowu++;
		if (tab1[row - 1][1] == 8)
		{
			count++;
			rowu = count;
			rowf++;
		}
	}

	//********** TABELI 3  ********

	cout << "\n  TABLE 3\n" << endl;
	cout << "U1   X2   X1   S2   f2   S1\n" << endl;
	row = 0;
	while (row <= 27)
	{
		cout << tab1[row][column - 2] << "  ";
		if (tab1[row][column - 2] < 1)
			cout << " ";
		if (tab1[row][column - 2] < 3)
			cout << " ";

		cout << tab1[row][column - 1] << "  ";
		if (tab1[row][column - 1] < 1)
			cout << " ";
		if (tab1[row][column - 1] < 3)
			cout << " ";

		cout << tab1[row][column] << "  ";
		if (tab1[row][column] < 1)
			cout << " ";
		if (tab1[row][column] < 8)
			cout << " ";

		cout << tab1[row][column + 1] << "  ";
		if (tab1[row][column + 1] < 1)
			cout << " ";
		if (tab1[row][column + 1] < 3)
			cout << " ";

		cout << tab1[row][column + 2] << "  ";
		if (tab1[row][column + 2] < 1)
			cout << " ";
		if (tab1[row][column + 2] < 8)
			cout << " ";

		cout << tab1[row][column + 3] << endl;
		row++;

		if (tab1[row - 1][1] == 8)
		{
			cout << "----------------------------" << endl;
		}
	}

	// *********** TABELI 4 ************

	row = 0;
	rowf = 0;
	rowu = 0;
	column = 2;
	count = 0;

	while (row <= 6)
	{
		tab0[row][column] = f1[rowf][1];
		tab0[row][column - 1] = f1[rowu][1];
		tab0[row][column - 2] = tab0[row][column - 1] - tab0[row][column];
		tab0[row][column + 1] = max(tab1, tab0[row][column - 1]);
		tab0[row][column + 2] = choice(tab0[row][column - 2], f1);
		tab0[row][column + 3] = tab0[row][column + 2] + tab0[row][column + 1];

		row++;
		rowu++;
		if (tab0[row - 1][1] == 300)
		{
			count++;
			rowu = count;
			rowf++;
		}
	}

	//**********  TABELI 4  ********

	cout << "\n  TABLE 4\n" << endl;
	cout << "U0   X1   X0   S1   f1   S0\n" << endl;
	row = 0;
	while (row <= 8)
	{
		cout << tab0[row][column - 2] << "  ";
		if (tab0[row][column - 2] < 1)
			cout << " ";
		if (tab0[row][column - 2] < 3)
			cout << " ";

		cout << tab0[row][column - 1] << "  ";
		if (tab0[row][column - 1] < 1)
			cout << " ";
		if (tab0[row][column - 1] < 8)
			cout << " ";

		cout << tab0[row][column] << "  ";
		if (tab0[row][column] < 1)
			cout << " ";
		if (tab0[row][column] < 8)
			cout << " ";

		cout << tab0[row][column + 1] << "  ";
		if (tab0[row][column + 1] < 1)
			cout << " ";
		if (tab0[row][column + 1] < 3)
			cout << " ";

		cout << tab0[row][column + 2] << "  ";
		if (tab0[row][column + 2] < 1)
			cout << " ";
		if (tab0[row][column + 2] < 3)
			cout << " ";

		cout << tab0[row][column + 3] << endl;
		row++;

		if (tab0[row - 1][1] == 8)
		{
			cout << "----------------------------\n\n" << endl;
		}
	}

	// **************  **********************

	int u0, row0, u1, row1, u2, row2, u3, row3;
	row0 = 0;
	row1 = 0;
	row2 = 0;
	row3 = 0;

	while (row0 <= 8)
	{
		if (tab0[row0][7] == max(tab0, 0))
		{
			u0 = tab0[row0][0];
			while (row1 <= 44)
			{
				if (tab1[row1][2] == tab0[row0][1])
				{
					if (tab1[row1][8] == max(tab1, tab1[row1][2]))
					{
						u1 = tab1[row1][0];
						while (row2 <= 44)
						{
							if (tab2[row2][2] == tab1[row1][1])
							{
								if (tab2[row2][7] == max(tab2, tab2[row2][2]))
								{
									u2 = tab2[row2][0];
									while (row3 <= 8)
									{
										if (tab3[row3][1] == tab2[row2][1])
										{
											u3 = tab3[row3][0];
											cout << "SOLUTION :   U0 = " << u0 << " , U1 = " << u1 << " , U2 = " << u2 << " , U3 = " << u3 << endl << endl;
										}
										row3++;
									}
								}
							}
							row3 = 0;
							row2++;
						}

					}
				}
				row2 = 0;
				row1++;
			}
		}
		row1 = 0;
		row0++;
	}

	getchar();
	return(0);
}