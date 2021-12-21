// Class for diagonal matrix. For operation, we are only interested in the diagonal array

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Class for diagonal matrix */
class Diagonal
{
private:
    int n; // dimension
    int *A; // create array in the heap

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal();
};

/* Function that sets the value in the Diagonal Matrix */
void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

/* Function that gets the value in the Diagonal Matrix */
int Diagonal::Get(int i, int j)
{
    if (i == j)
    {
        return A[i];
    }
    return 0;
}

/* Function that displays the entire diagonal matrix */
void Diagonal::Display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

/* Destructor for the class Diagonal */
Diagonal::~Diagonal()
{
    delete[] A;
}

/* User Interface */
int main()
{
    Diagonal d(3);
    d.Set(1, 1, 5);
    d.Set(2, 2, 5);
    d.Set(3, 3, 7);

    d.Display();

    return 0;
}
