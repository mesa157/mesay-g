#include <iostream>
using namespace std;

// Declaring template class for calculator
template <class Z>

class Calculator
{
    // Declaring two private variables
private:
    Z number1, number2;

public:
    Calculator(Z n1, Z n2)
    {
        number1 = n1;
        number2 = n2;
    }

    // Function for displaying output
    void displayResult()
    {
        cout << "Numbers are: " << number1 << " and " << number2 << "." << endl;
        cout << "Addition of the numbers is: " << add() << endl;
        cout << "Subtraction of the numbers is: " << subtract() << endl;
        cout << "Product of the numbers is: " << multiply() << endl;
        cout << "Division of the numbers is: " << divide() << endl;
    }

    // Decalring calculation functions


    Z add()
    {
        return number1 + number2;
    }

    Z subtract()
    {
        return number1 - number2;
    }

    Z multiply()
    {
        return number1 * number2;
    }

    Z divide()
    {
        return number1 / number2;
    }
};

int main()
{
    Calculator<int> intCalc(3, 2);
    Calculator<float> floatCalc(3, 2);

    cout << "Int results are:" << endl;
    intCalc.displayResult();

    cout << endl << "Float results are:" << endl;
    floatCalc.displayResult();

    return 0;
}
