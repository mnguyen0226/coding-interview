/*Illustration of doubly linked list*/
#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Runs iterators functions for doubly linked list
 *
 */
void run_iterators()
{
    list<int> mylist = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Normal traversal: " << endl;
    // prints all elements in the doubly linked list
    for (auto iter = mylist.begin(); iter != mylist.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints all elements reversely
    for (auto iter = mylist.cbegin(); iter != mylist.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Reverse traversal: " << endl;
    // prints reverse of a linked list
    for (auto iter = mylist.rbegin(); iter != mylist.rend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    for (auto iter = mylist.crbegin(); iter != mylist.crend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs capacity functions for doubly linked list
 *
 */
void run_capacity()
{
}

/**
 * @brief Runs element access functions for doubly linked list
 *
 */
void run_element_access()
{
}

/**
 * @brief Runs modifiers functions for doubly linked list
 *
 */
void run_modifiers()
{
}

/**
 * @brief Runs operations functions for doubly linked list
 *
 */
void run_operation()
{
}

/*User Interface*/
int main()
{
    run_iterators();
    // run_capacity();
    // run_element_access();
    // run_modifiers();
    // run_operation();
    return 0;
}