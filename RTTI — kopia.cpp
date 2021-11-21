#include <iostream>

using namespace std;
class Animal {
public:
    int weight;
    virtual void sound()
    {
        cout << "animal make sound" << endl;
    }
    virtual void sleeping()
    {
        cout << "a" << endl;
    }
    virtual void eating()
    {
        cout << "animal is eating" << endl;
    }
    virtual void play()
    {
        cout << "animal plays" << endl;
    }
    virtual void setweight(int x)
    {
        cout << "set the weight";
    }
};
class Tiger : public Animal {
    string scientific_name;
    string color;
public: void sound()
{
    cout << "Tiger growl" << endl;
}
public: void sleeping()
{
    cout << "Tiger sleeps" << endl;
}
public: void eating()
{
    cout << "Tiger eats meat" << endl;
}
public: void play()
{
    cout << "Tiger plays with cubs" << endl;
}
public: void set_scientificname(string n)
{
    scientific_name = n;
}
public: void setcolor(string color)
{
    this->color = color;
}
public: void setweight(int x)
{
    this->weight = x;
}
};

class Elephant : public Animal {
    int avg_weight;
    bool strips;
public: void sound()
{
    cout << "Elephant trumpet" << endl;
}
public: void sleeping()
{
    cout << "Elephant sleeps" << endl;
}
public: void eating()
{
    cout << "Elephant eats graass" << endl;
}
public: void play()
{
    cout << "Elephant plays with Calf" << endl;
}
public: void set_avgw(int w)
{
    avg_weight = w;
}
public: void isstrip(bool strips)
{
    this->strips = strips;
}
public: void setweight(int x)
{
    this->weight = x;
}
};

class Monkey : public Animal {
public:
    bool is_red;
    bool is_cute;
public: void sound()
{
    cout << "Monkey chatter" << endl;
}
public: void sleeping()
{
    cout << "Monkey sleeps" << endl;
}
public: void eating()
{
    cout << "Monkey eats banana" << endl;
}
public: void play()
{
    cout << "Monkey plays with infant" << endl;
}
public: void reddyred(bool is_red)
{
    this->is_red = is_red;
}
public: void cuteycute(bool is_cute)
{
    this->is_cute = is_cute;
}
public: void setweight(int x)
{
    this->weight = x;
}
};

class Zoo {
public:
    int size;
    Animal** arr;
public: Zoo(int s)
{
    size = s;
    arr = new Animal * [size];
}
};
int main()
{
    Zoo z(3);
    z.arr[1] = new Tiger;

    z.arr[0] = new Elephant;
    z.arr[2] = new Monkey;
    cout << "*******normal calls*******\n\n";
    z.arr[1]->eating();
    cout << "\n";
    z.arr[1]->play();
    cout << "\n";
    z.arr[1]->sleeping();
    cout << "\n";
    z.arr[1]->sound();
    z.arr[1]->setweight(34);
    cout << "\nTiger weight is " << z.arr[1]->weight << " kg\n";
    cout << "\n";
    z.arr[0]->eating();
    cout << "\n";
    z.arr[0]->play();
    cout << "\n";
    z.arr[0]->sleeping();
    cout << "\n";
    z.arr[0]->sound();

    Animal* base_ptr = new Monkey;
    Monkey* derived_ptr = dynamic_cast<Monkey*>(base_ptr);
    if (derived_ptr != NULL)
        cout << "\n\n*******Dynamic castIt is working*******\n\n";
    else
        cout << "cannot cast Base* to Derived*\n";

    derived_ptr->play();
    cout << "\n";
    derived_ptr->eating();
    cout << "\n";
    derived_ptr->sleeping();
    cout << "\n";
    derived_ptr->sound();

    derived_ptr->reddyred(false);
    derived_ptr->cuteycute(true);
    derived_ptr->setweight(12);
    cout << "\n is cute: " << derived_ptr->is_cute << "\n is red: " << derived_ptr->is_red << "\nweight is " << derived_ptr->weight << " kgs";


}