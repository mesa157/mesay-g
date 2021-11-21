#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <sstream>
#include <vector>
#include <string>

// This is base car with virtual abstract function type

const char defaultCars[] =
"Sedan,Nissan Versa,NV12345,120,2014 year almost new\n"
"Hatchback,Kia Rio,KR12345,150,2017 year\n"
"Coupe,Ford Mustang,FM12345,300,2019 year\n"
"Minivan,Honda Odyssey,HO12345,250,2013 year";

void makeDefaultFile(const char* file) {
    std::ofstream out(file);
    out << defaultCars;
}

class Car {
public:
    // constructor
    Car(std::string model, std::string number, double cost, std::string description)
        : m_model(std::move(model))
        , m_number(std::move(number))
        , m_cost(cost)
        , m_description(std::move(description))
    { }

    virtual ~Car() {} // virtual destructor
    virtual std::string type() const = 0;

    double cost() const { // car cost
        return m_cost;
    }

    std::string model() const { // car model name
        return m_model;
    }
    std::string number() const { // car number
        return m_number;
    }
    std::string description() const { // car description
        return m_description;
    }

private:
    std::string m_model;
    std::string m_number;
    double m_cost;
    std::string m_description;
};

class Hatchback : public Car {
public:
    Hatchback(std::string model, std::string number, double cost, std::string description)
        : Car(model, number, cost, description)
    {}
    // override type function
    virtual std::string type() const override {
        return "Hatchback";
    }
};

class Minivan : public Car {
public:
    Minivan(std::string model, std::string number, double cost, std::string description)
        : Car(model, number, cost, description)
    {}
    // override type function
    virtual std::string type() const override {
        return "Minivan";
    }
};

class Sedan : public Car {
public:
    Sedan(std::string model, std::string number, double cost, std::string description)
        : Car(model, number, cost, description)
    {}
    // override type function
    virtual std::string type() const override {
        return "Sedan";
    }
};

class Coupe : public Car {
public:
    Coupe(std::string model, std::string number, double cost, std::string description)
        : Car(model, number, cost, description)
    {}
    // override type function
    virtual std::string type() const override {
        return "Coupe";
    }
};

// Customer class
class Customer
{
public:
    Customer(std::string name); // create customer

    void setTotal(double total); // set total amount of money
    double total() const; // get total amount
    std::string name() const; // get customer name
    Car* car() const; // get rented car

    bool rentCar(Car* car, int days); // rent the car


private:
    std::string m_name; // name of customer
    double m_total{ 0 }; // total money
    Car* m_car{ nullptr }; // rented car
    int m_days{ 0 }; // rented car days
};

Customer::Customer(std::string name) : m_name(std::move(name)) {}

void Customer::setTotal(double total) {
    m_total = total;
}

double Customer::total() const {
    return m_total;
}

std::string Customer::name() const {
    return m_name;
}

Car* Customer::car() const {
    return m_car;
}

bool Customer::rentCar(Car* car, int days) {
    // check for already rented cars
    if (m_car != nullptr) {
        std::cout << "You have already rented car: " << m_car->model() << std::endl;
        return false;
    }

    double cost = car->cost() * days; // calculate a cost
    if (m_total < cost) { // check deposit
        std::cout << "You have not enough money to rent the car: " << car->model() << std::endl;
        return false;
    }
    m_total -= cost; // decrese a deposit
    m_car = car;
    return true;
}

// Main class to run system
class RentalSystem {
public:
    RentalSystem() = default;
    ~RentalSystem();

    void loadCars(const std::string& filename); // loading cars from the file
    void printMenu() const; // print menu
    void printCars() const; // print available cars info
    bool rentCar(Customer& customer, std::size_t i); // do rent the car

private:
    std::vector<Car*> m_cars; // available cars
};

double fromString(const std::string& value) {
    std::stringstream ss(value);
    double result;
    ss >> result;
    return result;
}

Car* makeCar(const std::vector<std::string>& tokens) {
    // check tokens size
    if (tokens.size() != 5) {
        throw std::logic_error("Wrong file format: expected Type,Name,Number,Cost,Description");
    }

    double cost = fromString(tokens[3]); // get cost from string
    // create car by type
    if (tokens[0] == "Coupe") {
        return new Coupe(tokens[1], tokens[2], cost, tokens[4]);
    }
    if (tokens[0] == "Hatchback") {
        return new Hatchback(tokens[1], tokens[2], cost, tokens[4]);
    }
    if (tokens[0] == "Minivan") {
        return new Minivan(tokens[1], tokens[2], cost, tokens[4]);
    }
    if (tokens[0] == "Sedan") {
        return new Sedan(tokens[1], tokens[2], cost, tokens[4]);
    }
    // invalid type
    throw std::logic_error("Wrong type of car: " + tokens[0]);
}

// Type,Name,Number,Cost,Description
void RentalSystem::loadCars(const std::string& filename)
{
    // open file
    std::ifstream in(filename);
    if (!in.good()) {
        throw std::logic_error("File not found: " + filename);
    }

    while (1) {
        std::string line;
        std::getline(in, line); // read line from the file
        if (!in) {
            break;
        }
        if (line.empty()) {
            continue;
        }
        // parse line on topics
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ',')) {
            tokens.push_back(std::move(token));
        }
        // make car from tokens and push back into vector
        m_cars.push_back(makeCar(tokens));
    }
    // print out info
    std::cout << m_cars.size() << " cars was successfully loaded" << std::endl;
}

void RentalSystem::printMenu() const
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Rent a car" << std::endl;
    std::cout << "2. Rest of money" << std::endl;
    std::cout << "3. List of cars" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void RentalSystem::printCars() const
{
    std::cout << "Rental cars: " << std::endl;
    for (std::size_t i = 0; i < m_cars.size(); ++i) {
        std::cout << std::left << std::setw(5) << i + 1 << std::setw(15) << m_cars[i]->type();
        std::cout << std::left << std::setw(15) << m_cars[i]->model();
        std::cout << std::left << std::setw(10) << m_cars[i]->number();
        std::cout << std::left << "$" << std::fixed << std::setprecision(2) << m_cars[i]->cost();
        std::cout << "\t" << m_cars[i]->description() << std::endl;
    }
}

bool RentalSystem::rentCar(Customer& customer, std::size_t i) {
    // validate index
    if (i > m_cars.size() || i == 0) {
        std::cout << "Invalid index: " << i << std::endl;
        return false;
    }
    int days;
    std::cout << "Days of rent: "; // prompt the days count
    std::cin >> days;
    // call rent car from customer
    return customer.rentCar(m_cars[i - 1], days);
}

RentalSystem::~RentalSystem() // release memory
{
    for (const auto& car : m_cars) {
        delete car;
    }
}

int main() {
    const char carsFile[] = "cars.csv";
    makeDefaultFile(carsFile);
    try
    {
        RentalSystem rentalSystem;
        std::cout << "Loading rental cars..." << std::endl;
        rentalSystem.loadCars(carsFile);

        std::cout << "Welcome to the Rental Car System!" << std::endl;
        int cmd;
        bool finished = false;
        std::string name;
        std::cout << "Enter your name: ";
        std::cin >> name;
        Customer customer(name);

        std::cout << "Enter money amount: $";
        double money;
        std::cin >> money;
        customer.setTotal(money);

        while (!finished) {
            rentalSystem.printMenu();
            std::cout << "Your choice: ";
            std::cin >> cmd;
            switch (cmd) {
            case 1: // Rent a car
            {
                std::size_t num;
                rentalSystem.printCars();
                std::cout << "Car #: ";
                std::cin >> num;
                if (rentalSystem.rentCar(customer, num)) {
                    std::cout << "You're successfully rented the car!" << std::endl;
                }
                else {
                    std::cout << "You're not rent the car!" << std::endl;
                }
                break;
            }
            case 2: // Rest of money
            {
                std::cout << "Rest of money: $" << std::fixed << std::setprecision(2) <<
                    customer.total() << std::endl;
                break;
            }
            case 3: // List of cars
            {
                rentalSystem.printCars();
                break;
            }
            case 4: // Exit
            {
                finished = true;
                break;
            }
            }
        }
        std::cout << "Bue" << std::endl;


    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}