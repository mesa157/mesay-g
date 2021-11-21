

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Complex_number
{
public:
    int real;
    int imaginary;

    Complex_number()
    {

    }
    Complex_number(int x, int y)
    {
        this->real = x;
        this->imaginary = y;
    }
    void get_complex(int x, int y) {
        real = x;
        imaginary = y;

        cout << "z=" << real << "+i" << imaginary << endl;
        cin >> real;
        cin >> imaginary;
    }
    ~Complex_number()
    {
    }
    ostream& operator<<(ostream& output)
    {
        output << "z= " << real << "+i" << imaginary << endl;
        return output;
    }
    bool reading_from_Myfile()
    {
        ifstream file("Complex.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                stringstream qp(line);
                string real_string;
                string imaginary_string;
                getline(qp, real_string, '#');
                real = stoi(real_string);
                getline(qp, imaginary_string, '#');
                imaginary = stoi(imaginary_string);
                break;
            }
        }
        else
        {
            cout << "Problem occured when opening file" << endl;
            return 1;
        }
        file.close();
        return 0;
    }
};

int main()
{
    Complex_number z;
    z.reading_from_Myfile();
    z.get_complex(15, 20);
    z << cout;
    return 0;
}
