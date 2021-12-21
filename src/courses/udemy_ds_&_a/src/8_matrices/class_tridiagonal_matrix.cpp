// Class for tridiagonal matrix.

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

/* Class for tridiagonal matrix */
class Tridiagonal
{
private:
    int n;  // dimension
    int *A; // create array in the heap

public:
    // default constructor
    Tridiagonal()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }

    // parameterized constructor
    Tridiagonal(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDim() { return n; }
    ~Tridiagonal();
};

/* Function that sets the value in the tridiagonal Matrix */
void Tridiagonal::Set(int i, int j, int x)
{
    if (abs(i - j) <= 1)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

/* Function that gets the value in the Tridiagonal Matrix */
int Tridiagonal::Get(int i, int j)
{
    if (abs(i - j) <= 1)
    {
        return A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

/* Function that displays the entire Tridiagonal matrix */
void Tridiagonal::Display()
{
    int i, j;
    for (i = 1; i <= n; i++) // rows
    {
        for (j = 1; j <= n; j++) // cols
        {
            if (abs(i - j) <= 1)
            {
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

/* Destructor for the class Tridiagonal */
Tridiagonal::~Tridiagonal()
{
    delete[] A;
}

/* User Interface */
int main()
{
    int dim;
    cout << "Enter Dimension: ";
    cin >> dim;
    Tridiagonal lt(dim);

    int x;
    cout << "Enter All Elements: \n";
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cin >> x;
            lt.Set(i, j, x);
        }
    }
    cout << endl;
    lt.Display();

    return 0;
}
