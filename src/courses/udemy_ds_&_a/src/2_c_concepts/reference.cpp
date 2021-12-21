// Reference = name a variable a different name.
// This is useful for param passing
// Reference has to be initialized when declareds

#include <iostream>

using namespace std;

int main()
{
    cout << "Reference" << endl;
    int a = 10; // stack
    int &r = a; // reference, another name of a
    cout << r << " and " << a << endl;

    r = 11;
    cout << r << " and " << a << endl;

    int b = 30;
    r = b;
    cout << r << " and " << a << endl;

    return 0;
}