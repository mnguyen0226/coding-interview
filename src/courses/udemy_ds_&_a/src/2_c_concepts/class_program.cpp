#include <iostream>

using namespace std;

// Complete class Rectangle
class Rectangle
{
private:
    int length;
    int breadth;

public:
    // default constructor
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }

    // parameterized constructor
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    // area calculation
    int area()
    {
        return length * breadth;
    }

    // perimeter calculation
    int perimeter()
    {
        return 2 * (length + breadth);
    }

    // setter length - mutator function
    void setLength(int l)
    {
        length = l;
    }

    // setter breadth - mutator function
    void setBreadth(int b)
    {
        breadth = b;
    }

    // getter length
    int getLength()
    {
        return length;
    }

    // getter breadth
    int getBreadth()
    {
        return breadth;
    }

    // destructor
    ~Rectangle()
    {
        cout << "Destructor!";
    }
};

int main()
{
    Rectangle r(10, 5);

    cout << "Area " << r.area() << endl;

    cout << "Perimeter " << r.perimeter() << endl;

    return 0;
}