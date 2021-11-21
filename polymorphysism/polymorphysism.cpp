// polymorphysism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
class square {

public :
    double langth;
    double width;
    square(){}
    square(double l, double w ) {
        langth = l;
        width = w;
        cout << "call class consturctor" << endl;
    }
    virtual void get_area( double l ,double w) {
        cout << "area =\n" << l * w << endl;
    }
    ~square() {
        cout << "class distructor being called" << endl;
    }
};

class triangle : public square {
public:
    double  w;
    double l;
    triangle(double w, double l)
    {
        cout << "call class constructor" << endl;
    }
    void get_area(double w, double l) {
        cout << "area triangle =\n" << 0.5 * l * w << endl;

    }
    ~triangle(){
        }


};

    

   


int main()
{
    triangle squar();
    squar().get_area(35.4, 32.5);
    cout << "area " << squar().get_area(35.4,32.5);
}

