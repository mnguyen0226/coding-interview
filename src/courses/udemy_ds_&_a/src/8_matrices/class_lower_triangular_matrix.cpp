// Class for lower triangular matrix.
// For Upper triangular matrix, just swap i to j

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Class for lower triangular matrix */
class LowerTriangular
{
private:
    int n;  // dimension
    int *A; // create array in the heap

public:
    // default constructor
    LowerTriangular()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }

    // parameterized constructor
    LowerTriangular(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDim() { return n; }
    ~LowerTriangular();
};

/* Function that sets the value in the lower triangular Matrix */
void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

/* Function that gets the value in the LowerTriangular Matrix */
int LowerTriangular::Get(int i, int j)
{
    if (i >= j)
    {
        return A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

/* Function that displays the entire LowerTriangular matrix */
void LowerTriangular::Display()
{
    int i, j;
    for (i = 1; i <= n; i++) // rows
    {
        for (j = 1; j <= n; j++) // cols
        {
            if (i >= j)
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

/* Destructor for the class LowerTriangular */
LowerTriangular::~LowerTriangular()
{
    delete[] A;
}

/* User Interface */
int main()
{
    int dim;
    cout << "Enter Dimension: ";
    cin >> dim;
    LowerTriangular lt(dim);

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
