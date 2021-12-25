#include <iostream>

using namespace std;

class Member
{
public:
    string name;
    int age;
    int phone;
    string address;
    int salary;

    // default constructor
    Member(){};

    // parameterized constructor
    Member(string n, int a, int p, string ad, int s)
    {
        this->name = n;
        this->age = a;
        this->phone = p;
        this->address = ad;
        this->salary = s;
    }

    void printSalary()
    {
        cout << "Salary: " << this->salary << endl;
    }
};

class Employee : public Member
{
private:
    string specialization;
    string department;

public:
    Employee(string n, int a, int p, string ad, int s)
    {
        this->name = n;
        this->age = a;
        this->phone = p;
        this->address = ad;
        this->salary = s;
    };
};

class Manager : public Member
{
private:
    string specialization;
    string department;

public:
    Manager(string n, int a, int p, string ad, int s)
    {
        this->name = n;
        this->age = a;
        this->phone = p;
        this->address = ad;
        this->salary = s;
    };
};

int main()
{
    Employee e("A", 1, 2, "asd", 4);
    Manager m("A", 1, 2, "asd", 5);
    e.printSalary();
    m.printSalary();
    return 0;
}