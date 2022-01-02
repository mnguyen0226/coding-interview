/* Illustration of Vector in C++ */

#include <iostream>
#include <vector>
using namespace std;

void run_iterator()
{
    // Functions:
    // begin() - returns an iterator pointing to  the first element in the vector.
    // end() - returns an iterator pointing to the theoretical element that follows the last element in the vector.
    // rbegin() - returnsa reverse iterator pointing to the last element in the vector (reverse beginning).
    // rend() - returns a reverse iterator pointing to the last element preceding the first elelemt in the vector (considered as reverse end).
    // cbegin() - returns a constant iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
    // cend() - returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
    // crbegin() - return the constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
    // crend() - returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reversed end).

    vector<int> v1;

    // inserts items into vector
    for (int i = 1; i <= 5; i++)
    {
        v1.push_back(i);
    }

    cout << "Output of begin and end: ";
    for (auto iter = v1.begin(); iter != v1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Output of cbegin and cend: ";
    for (auto iter = v1.cbegin(); iter != v1.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Output REVERSE of rbegin and rend: ";
    for (auto iter = v1.rbegin(); iter != v1.rend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Output REVERSE of crbegin and crend: ";
    for (auto iter = v1.crbegin(); iter != v1.rend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void run_capacity

/*User Interface*/
int main()
{
    run_iterator();
    return 0;
}