#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#define MAX 10
using namespace std;


class DivideByZeroException : public exception
{
public:

	const char* what() const throw()
	{
		return " ERROR: Divide By Zero Exception\n";
	}
};


class OutOfRangeException : public exception
{
public:

	const char* what() const throw()
	{
		return " ERROR: Index Out Of Bounds Exception\n";
	}
};

class FileDoesnotExistException : public exception
{
public:
	const char* what() const throw()
	{
		return " ERROR: File Does Not Exist Exception\n ";
	}
};// End of class FileDoesnotExistException



void readFile(string fileName, int numbers[], int& index)
{
	// ifstream objects declared to read data from file
	ifstream readF;

	// try block begins
	try
	{
		// Opens the file for reading
		readF.open(fileName.c_str());

		// Checks if the file unable to open for reading display's error message and stop
		if (!readF)
		{
			// Throws an exception FileDoesnotExistException
			FileDoesnotExistException fe;
			throw fe;
		}// End of if condition

		// Otherwise read file contents
		else
		{
			// Loops till end of the file
			while (!readF.eof())
			{
				// Checks if current index equals to maximum index throws OutOfRangeException
				if (index == MAX)
				{
					OutOfRangeException ore;
					throw ore;
				}// End of if condition

				// Otherwise read numbers from file
				else
					// Reads a number and stores it at index position
					readF >> numbers[index++];
			}// End of while loop
		}// End of else
	}// End of try block

	// Catch block to handle FileDoesnotExistException
	catch (FileDoesnotExistException& fe)
	{
		cout << fe.what();
	}// End of catch block

	// Catch block to handle OutOfRangeException
	catch (OutOfRangeException& ore)
	{
		cout << ore.what();
	}// End of catch block
}// End of function

// Function to divide two consecutive numbers from the numbers array and displays the quotient
void showQuotient(int numbers[], int len)
{
	// try block begins
	try
	{
		// Loops till number of elements in the array minus one times
		for (int c = 0; c < len - 1; c++)
		{
			// Checks if denominator number is 0 then throws a DivideByZeroException exception
			if (numbers[c + 1] == 0)
			{
				cout << "\n " << numbers[c] << "/" << numbers[c + 1] << " = ";
				DivideByZeroException de;
				throw de;
			}// End of if condition

			// Otherwise divides the number and displays the quotient
			else
				cout << "\n " << numbers[c] << "/" << numbers[c + 1] << " = " << (numbers[c] / numbers[c + 1]) << endl;
		}// End of for loop
	}// End of try block

	// Catch block to handle DivideByZeroException
	catch (DivideByZeroException& de)
	{
		cout << de.what();
	}// End of catch block
}// End of function

// main function definition
int main()
{
	// Declares an integer array of size MAX
	int numbers[MAX];
	// To store number of elements in the array
	int index = 0;

	// Calls the function to read file
	readFile("exception1.txt", numbers, index);
	// Calls the function to display quotients
	showQuotient(numbers, index);

	// Calls the function to read file
	readFile("exception2.txt", numbers, index);
	return 0;
}// End if main function