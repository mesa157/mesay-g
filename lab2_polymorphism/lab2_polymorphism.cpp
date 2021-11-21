// lab2_polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Animal  {
public:
    
    Animal( ) {
        

    }
    virtual void givevoice() = 0;
        
       

        virtual void eat() = 0;
        virtual void drink() = 0;
        ~Animal() {
            cout << "class distructor delated" << endl;
        }


};


class dog : public Animal {
public :

    void eat() { cout << " dog eat meat" << endl; }
    void givevoice() {
        cout << "dog sound woof woof" << endl;
    }
    void drink() {
        cout << "  dog drinks water" << endl;
    }
    ~dog(){
        cout << "class distructor delated" << endl;
    }



};
class monkey : public Animal{
    void eat() { cout << " monkey eat corn" << endl; }
    void givevoice() {
        cout << " money voice whoop" << endl;
    }
    void drink() {
        cout << "monkey drink orange juice" << endl;
    }
    ~monkey() {
        cout << "class distructor delated" << endl;
    }


};
class cat : public Animal {
    void eat() { cout << "cat eat  pork" << endl; }
    void givevoice() {
        cout << "cat make voice meeeyaw" << endl;
    }
    void drink() {
        cout << "cat drinks milk" << endl;
    }
    ~cat() {
        cout << "class distructor delated" << endl;
    }

};

void readData(vector<Animal*> ptr)
{
    for (int i = 0; i < ptr.size(); i++) {
        ptr[i]->givevoice();
        ptr[i]->eat();
        ptr[i]->drink();
    }
}

int main()
{
    vector<Animal*> v;
    v.push_back(new dog);
    v.push_back(new cat);
    v.push_back(new monkey);

    readData(v);

    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }

    return 0;

}