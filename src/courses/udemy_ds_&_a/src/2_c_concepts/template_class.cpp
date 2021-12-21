#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

// User interface
int main()
{
    Arithmetic<int> ar(10, 5);
    Arithmetic<float> ar2(15.5, 7.7);

    cout << "Add " << ar.add() << endl;
    cout << "Add " << ar2.add() << endl;

    return 0;
}