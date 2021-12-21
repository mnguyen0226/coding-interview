// constructor_in_inheritant.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a class for Employee that has name and id
// Derived Classes:
// Fulltime employee with saliary
// Partime employee with Daily Wages

#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    string name;
    int id;
public:
    //Constructor
    Employee(string name, int id) {
        this->name = name;
        this->id = id;
    }

    string getName() {
        return name;
    }

    int getID() {
        return id;
    }
};

class FulltimeEmployee :public Employee {
private:
    int salary;
public:
    FulltimeEmployee(string name, int id, int salary):Employee(name, id) { // make sure to inherit the constructor of base class
        this->salary = salary;

        // No need to mention name and id
    }

    int getSalary() {
        return salary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int wage;
public:
    PartTimeEmployee(string name, int id, int wage) : Employee(name, id) {
        this->wage = wage;

        // No need to mention name and id
    }

    int getWage() {
        return wage;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    FulltimeEmployee f("David", 12, 1);
    PartTimeEmployee p("Lin", 13, 2);

    cout << f.getSalary() << endl;
    cout << p.getWage() << endl;
    return 0;
}
