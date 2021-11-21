#include<iostream>
#include "Header.h"

int choice(int number, int f[7][2])            //Algorytm wyszukuj¹cy odpowiedni¹ liczbe  z f(i)
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

int max(int tab[28][6], int number)               //Algorytm wyszukuj¹cy najwy¿szy wzrost.
{
	int row = 0;
	int greatest = 0;
	while (row <= 27)
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