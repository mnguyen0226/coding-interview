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

    // fit the capacity to save space
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

    // get the pointer to the first position of the vector
    int *pos = v1.data();
    while (*pos <= v1.size() && *pos != 0)
    {
        cout << *pos << " ";
        pos++; // move address to the next element
    }
}

void run_modifiers(){

    
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