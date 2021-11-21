
#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double x;
    cout << "Enter value of x for which Newtons polynomial p4(x) for interpolated function f(x) to be calculated" << endl;
    cin >> x; // read value of x from user
    double xi[5] = { 9,7,5,3,1 }; // array x which holds the polynomials
    double fi[5] = { -2,1,-1,4,2 }; // array y stores f(xi) values
    double xn = xi[4]; // last xi is xn
    cout << "xn = " << xn << endl;
    double yn = fi[4]; // last yi is fn
    cout << "yn = " << yn << endl;
    double h = xi[0] - xi[1]; // h is xn - xn+1
    double s = (x - xn) / h;
    cout << "s = " << s << endl;

    // Calculating first order backward difference,
    double d1f[4];

    for (int i = 4; i <= 1; i--) {
        d1f[i] = fi[i] - fi[i - 1]; // D1fi = f(i) - f(i-1)
    }
    cout << "Df1 : ";
    for (int i = 0; i < 4; i++) cout << d1f[i] << " ";
    cout << endl;
    // Calculating second order backward difference
    double d2f[3];
    for (int i = 3; i <= 1; i--) {
        d2f[i] = d1f[i] - d1f[i - 1]; // D2f(i) = D1f(i) - D1f(i-1)
    }
    cout << "Df2 : ";
    for (int i = 0; i < 3; i++) cout << d2f[i] << " ";
    cout << endl;

    // Calculating Third order Backward difference
    double d3f[2];

    for (int i = 2; i <= 1; i--) {
        d3f[i] = d2f[i] - d2f[i - 1]; // D3f(i) = D2f(i) - D2f(i-1)
    }

    cout << "Df3 : ";
    for (int i = 0; i < 2; i++) cout << d3f[i] << " ";
    cout << endl;

    // Calculating 4th order Backward difference 
    double d4f = d3f[1] - d3f[0];
    cout << "Df4 : " << d4f << endl;

    double fx; // to store value of f(x)
    // f(x) = yn + s * d1f + s(s+1)d2f/2! + s(s+1)(s+2)d3f/3!  + s(s+1)(s+2)(s+3)d4f/4!
    fx = yn + (s * d1f[3]) + ((s * (s + 1) * d2f[2]) / 2) + ((s * (s + 1) * (s + 2) * d3f[1]) / 6) + ((s * (s + 1) * (s + 2) * (s + 3) * d4f) / 24);
    cout << "Value of f(" << x << ") :" << fx << endl;


    //Since we already know that we have to calculate for 4th order polynomial i.e p4(x)
    // the f(x) equation is,

    return 0;
}
