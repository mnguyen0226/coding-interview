#include <iostream>
using namespace std;

class Employee
{
private:
    int salary;
    int hour;

public:
    Employee()
    {
        salary = 0;
        hour = 0;
    };
    Employee(int s, int h)
    {
        this->salary = s;
        this->hour = h;
    }
    void getInfo(int *s, int *h) // return multiple values
    {
        *s = this->salary;
        *h = this->hour;
    }
    void AddSal()
    {
        if (this->salary < 500)
        {
            this->salary += 10;
        }
    }
    void AddWork()
    {
        if (this->hour > 6)
        {
            this->salary += 5;
        }
    }
};

int main()
{
    Employee e(1, 7);
    int s, h;
    e.getInfo(&s, &h);
    cout << s << " " << h << endl;

    e.AddSal();
    e.AddWork();
    e.getInfo(&s, &h);
    cout << s << " " << h << endl;
}