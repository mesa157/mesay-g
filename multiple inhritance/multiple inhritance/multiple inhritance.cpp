#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person()
    {
        cout << "Constructor of class Person is being called.." << endl;
        name = "Ms Smith";
        address = "New York";
    }
    ~Person()
    {
        cout << "Destructor of Person is being called.." << endl;
    }
protected:
    string name;
    string address;

};

class Employee {
public:
    Employee()
    {
        cout << "Constructor of class Employee is being called.." << endl;
        firm = "Lakeview High School";
        tenure = "permanent";
    }
    ~Employee()
    {
        cout << "Destructor of Employee is being called.." << endl;
    }
protected:
    string firm;
    string tenure;
};

class Teacher : public Person, public Employee {
public:
    Teacher()
    {
        cout << "Constructor of class Teacher is being called" << endl;
    }
    void description()
    {
        cout << name << " is from " << address << ". She has a " << tenure << " tenure at " << firm << endl;
    }
    ~Teacher()
    {
        cout << "Destructor of Teacher is being called.." << endl;
    }

};

int main()
{
    Teacher obj;
    obj.description();
    return 0;
}