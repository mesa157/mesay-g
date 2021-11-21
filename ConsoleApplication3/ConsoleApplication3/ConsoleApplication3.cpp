#include <iostream>
using namespace std;
class row
{
private:
		char* t;
public :
	row();
	friend istream& operator>>(istream& is, row& some);
	row& operator+=(const row&);
	friend ostream& operator<<(ostream& is, row& some);
	int length();
	const char* getText();
	row(const row&);
	row(const char*);

	
};