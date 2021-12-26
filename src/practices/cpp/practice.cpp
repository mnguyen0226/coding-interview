#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // default constructor
    Rectangle()
    {
        this->length = 0;
        this->breadth = 0;
    }

    // paramtereized constructor
    Rectangle(int l, int b)
    {
        this->length = l;
        this->breadth = b;
    }

    // customed constructor
    Rectangle(int i)
    {
        this->length = i;
        this->breadth = i;
    }

    int Area()
    {
        return this->breadth * this->length;
    }
};

int main()
{
    Rectangle r1, r2(1, 2), r3(1);
    cout << "Rectange 1: " << r1.Area() << endl;
    cout << "Rectange 2: " << r2.Area() << endl;
    cout << "Rectange 3: " << r3.Area() << endl;

    return 0;
}