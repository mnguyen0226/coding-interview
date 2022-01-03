/*Illustration of deque-double ended queue container stl*/

#include <iostream>
#include <deque>

using namespace std;

/**
 * @brief Illustrates the iterator operator of deque
 *
 */
void run_iterators()
{
    // initializes and populate the deque
    deque<int> d;
    for (int i = 1; i <= 5; i++)
    {
        d.push_back(i);
    }

    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints reversely all elements in deque
    for (auto r_iter = d.rbegin(); r_iter != d.rend(); ++r_iter)
    {
        cout << *r_iter << " ";
    }
    cout << endl;

    // prints all elements in deque
    for (auto iter = d.cbegin(); iter != d.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints reversely all elements in deque
    for (auto r_iter = d.crbegin(); r_iter != d.crend(); ++r_iter)
    {
        cout << *r_iter << " ";
    }
    cout << endl;
}

void run_capacity()
{
    deque<int> d;
    for (int i = 1; i <= 5; i++)
    {
        d.push_back()
    }
}

void run_element_access()
{
}

void run_modifiers()
{
}

/*User Interface*/
int main()
{
    // run_iterators();
    void run_capacity();
    return 0;
}