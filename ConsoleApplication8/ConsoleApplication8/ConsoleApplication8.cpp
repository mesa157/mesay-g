#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main(void)
{
    double x0, y0, x1, y1, e, dx0, dy0, detx0, dety0, dx1, dy1, k;
    e = 0.001;
    //double a= pow((sin(x-0.7)),2);
    //double b= pow((sin(y-0.7)),2);
    cout << "enter the value initial value from the scope(x0,y0)" << endl;
    cin >> x0 >> y0;
    //first itreation
    dx0 = -2 * (sin(2 * (x0)-1.4));
    dy0 = -2 * (sin(2 * (y0)-1.4));
    detx0 = 2 * (cos(2 * (x0)-1.4));
    dety0 = 2 * (cos(2 * (y0)-1.4));
    cout << "d0 equals to(" << dx0 << "," << dy0 << ")" << endl;
    //calculating the min of f lamda0
    double lamda0 = (pow(dx0, 2) + pow(dy0, 2)) / ((detx0 * pow(dx0, 2)) + (dety0 * pow(dy0, 2)));
    x1 = -(x0 + (lamda0 * detx0));
    y1 = -(x0 + (lamda0 * dety0));
    if ((pow(x1, 2) + pow(y1, 2)) <= lamda0) {
        cout << "argument= (" << x1 << "," << y1 << ")" << endl;
    }
    else {
        // calculating second itriation
        k = ((pow(x1, 2) + pow(y1, 2)) / (pow(dx0, 2) + pow(dy0, 2)));
        dx1 = (x1 + (k * dx0));
        dy1 = (y1 + (k * dy0));
        cout << "argument= (" << dx1 << "," << dy1 << ")" << endl;
    }
    return 0;
}
