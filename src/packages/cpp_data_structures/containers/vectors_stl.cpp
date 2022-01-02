/* Illustration of Vector in C++ */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Illustrates the iterating functions of vector.
 *
 */
void run_iterator()
{
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

/**
 * @brief Illustrates the capacity functions of vector.
 *
 */
void run_capacity()
{
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

    // fits the capacity to save space
    v1.shrink_to_fit();
    for (auto iter = v1.begin(); iter != v1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Illustrates the run access element of vector
 *
 */
void run_access_elements()
{
    vector<int> v1;

    // populates the vector
    for (int i = 1; i <= 5; i++)
    {
        v1.push_back(i);
    }
    cout << "Size: " << v1.size() << endl;
    cout << "Reference operator: " << v1[2] << endl;
    cout << "At: " << v1.at(2) << endl;
    cout << "Front: " << v1.front() << endl;
    cout << "Back: " << v1.back() << endl;

    // gets the pointer to the first position of the vector
    int *pos = v1.data();
    while (*pos <= v1.size() && *pos != 0)
    {
        cout << *pos << " ";
        pos++; // move address to the next element
    }
}

/**
 * @brief Illustrates the modifiers of vector
 *
 */
void run_modifiers()
{
    vector<int> v1;

    // fills the array with 10 five times
    v1.assign(5, 10);

    cout << "The elements are: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    // inserts 15
    v1.push_back(15);
    cout << "Last element: " << v1.back() << endl;

    // removes the last element
    v1.pop_back();

    // inserts 5 at begin
    v1.insert(v1.begin(), 5);
    cout << "Front element: " << v1.front() << endl;

    // removes the front element
    v1.erase(v1.begin());
    cout << "Front element: " << v1.front() << endl;

    // inserts at the beginning
    v1.emplace(v1.begin(), 5);
    cout << "Front element: " << v1.front() << endl;

    // inserts 20 at the end
    v1.emplace_back(20);
    cout << "Last element: " << v1.back() << endl;

    // swaps content of two vector test
    vector<int> v2, v3;

    v2.push_back(1);
    v2.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);

    // prints out two vectors
    cout << "Vector 2: ";
    for (auto iter = v2.begin(); iter != v2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "Vector 3: ";
    for (auto iter = v3.begin(); iter != v3.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    v2.swap(v3);

    // prints out two vectors
    cout << "Swaped Vector 2: ";
    for (auto iter = v2.begin(); iter != v2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "Swaped Vector 3: ";
    for (auto iter = v3.begin(); iter != v3.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

/*User Interface*/
int main()
{
    // run_iterator();
    // run_capacity();
    // run_access_elements();
    run_modifiers();
    return 0;
}