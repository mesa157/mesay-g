#include <iostream>


int min(int a, int b, int c) {
	if (a < b) {
		if (a < c) {
			return (a);
		}
		else {
			return c;
		}
	}
	else if (b < c) {
		return b;
	}
	else return c;
}
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
	int D1[3][3] = {
	{ 2,3,4 },
	{ 6,2,8 },
	{ 10,5,12 }
	};

	int D2[3][3] = {
	{ 1,4,1 },
	{ 5,8,3 },
	{ 2,6,7 }
	};

	/*int D1[3][3] = {
		{ 5,3,-1 },{ -3,-5,8 },{ 1,2,-2 }
	};
	int D2[3][3] = {
		{ -1,4,1 },{ 1,-8,3 },{ 4,6,-7 }
	};*/
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

	int cMin1, cMin2, cMin3, rMin1, rMin2, rMin3;
	int row = 0;
	int col = 0;
	int a = 0, b = 0, c = 0;
	bool end = false;

	while (!end) {
		while (row <= 2) {
			a = D1[row][col++];
			b = D1[row][col++];
			c = D1[row][col];
			int i, j;
			if (row == 0) {
				i = 0;
				rMin1 = min(a, b, c);
				if (rMin1 == a) {
					j = 0;
					d1[i][j] = 1;
				}
				if (rMin1 == b) {
					j = 1;
					d1[i][j] = 1;
				}
				if (rMin1 == c) {
					j = 2;
					d1[i][j] = 1;
				}
			}
			if (row == 1) {
				i = 1;
				rMin2 = min(a, b, c);
				if (rMin2 == a) {
					j = 0;
					d1[i][j] = 1;
				}
				if (rMin2 == b) {
					j = 1;
					d1[i][j] = 1;
				}
				if (rMin2 == c) {
					j = 2;
					d1[i][j] = 1;
				}

			}
			if (row == 2) {
				i = 2;
				rMin3 = min(a, b, c);
				if (rMin3 == a) {
					j = 0;
					d1[i][j] = 1;
				}
				if (rMin3 == b) {
					j = 1;
					d1[i][j] = 1;
				}
				if (rMin3 == c) {
					j = 2;
					d1[i][j] = 1;
				}
			}
			row++;
			col = 0;
		}
		while (col <= 2) {
			row = 0;
			a = D2[row++][col];
			b = D2[row++][col];
			c = D2[row][col];
			int i, j;
			if (col == 0) {					// if column is 1 then we put maximum in first var cMax1 
				j = 0;
				cMin1 = min(a, b, c);
				//we get number of row where the maximum is
				if (cMin1 == a) {
					i = 0;
					d2[i][j] = 1;
				}
				if (cMin1 == b) {
					i = 1;
					d2[i][j] = 1;
				}
				if (cMin1 == c) {
					i = 2;
					d2[i][j] = 1;
				}
			}
			if (col == 1) {					// column = 2
				j = 1;
				cMin2 = min(a, b, c);

				if (cMin2 == a) {
					i = 0;
					d2[i][j] = 1;
				}
				if (cMin2 == b) {
					i = 1;
					d2[i][j] = 1;
				}
				if (cMin2 == c) {
					i = 2;
					d2[i][j] = 1;
				}
			}
			if (col == 2) {					// column = 3
				j = 2;
				cMin3 = min(a, b, c);
				if (cMin3 == a) {
					i = 0;
					d2[i][j] = 1;
				}
				if (cMin3 == b) {
					i = 1;
					d2[i][j] = 1;
				}
				if (cMin3 == c) {
					i = 2;
					d2[i][j] = 1;
				}

			}
			col++;
			row = 0;
		}
		end = true;

	}
	///
	int i, j;
	int rMax;
	rMax = max(rMin1, rMin2, rMin3);
	if (rMax == rMin1) {
		i = 1;
	}
	else if (rMax == rMin2) {
		i = 2;
	}
	else if (rMax == rMin3) {
		i = 3;
	}
	int cMax;
	cMax = max(cMin1, cMin2, cMin3);
	if (cMax == cMin1) {
		j = 1;
	}
	else if (cMax == cMin2) {
		j = 2;
	}
	else if (cMax == cMin3) {
		j = 3;
	}
	std::cout << "i = " << i << ", j = " << j << " (" << rMax << "," << cMax << ")" << std::endl;

	system("PAUSE");
}
