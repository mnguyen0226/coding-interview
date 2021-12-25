#include <iostream>
#define interest(p, r, t) ((p * r * t) / 100.0)
using namespace std;
int main()
{
    double d = interest(1.0, 2.0, 3.0);
    cout << d << endl;
    return 0;
}