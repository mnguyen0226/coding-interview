/* Illustration of Vector in C++ */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Illustrates the iterating functions of vector
 *
 */
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

void run_capacity()
{
    // Functions:
    // size() - Returns the number of elements in the vector.
    // max_size() - Returns the max number of elements that the vector can hold.
    // capacity() - Returns the size of the of the storage space currently allocated to the vector expressed as number of elements.
    // resize(n) - Resizes the container so that it contains "n" elements.
    // empty() - Returns whether the container is empty.
    // shrink_to_fit() - Reduces the capacity of the container to fit its size and destroys all elements beyong the capacity.
    // reverse() - Requests that the vector capacity be at least enough to contain n elements.

    vector<int> v1;
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

    cout << "Size: " << v1.size();
    cout << "\nCapacity: " << v1.capacity();
    cout << "\nMax_size: " << v1.max_size();

    // resizes the vector size to 4, automatically delete the last number
    v1.resize(4);
    cout << "\nSize: " << v1.size();

    cout << "\nOutput of begin and end: ";
    for (auto iter = v1.begin(); iter != v1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // checks if the vector is empty or not
    if (v1.empty() == true)
    {
        cout << "The vector is empty" << endl;
    }
    else
    {
        cout << "The vector is not empty" << endl;
    }

    // fit the capacity to save space
    v1.shrink_to_fit();
    for (auto iter = v1.begin(); iter != v1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void run_access_elements()
{
    // Functions:
    // reference operator [g] - Returns a reference to the element at position g in the vector.
    // at(g) - Returns a reference to the eleemnt at position 'g' in the vector.
    // front() - Return the first element in the vector.
    // back() - Returns a reference to the last element in the vector.
    // data() - Returns a direct pointer to the memory array used internally by the vector to store its own elements
    vector<int> v1;
}

/*User Interface*/
int main()
{
    // run_iterator();
    // run_capacity();
    return 0;
}