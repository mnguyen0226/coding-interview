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

/**
 * @brief Illustrates the capacity operator of deque
 *
 */
void run_capacity()
{
    deque<int> d(100);
    for (int i = 1; i <= 5; i++)
    {
        d.push_back(i);
    }
    cout << "Size: " << d.size() << endl;
    cout << "Max Size: " << d.max_size() << endl;
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    d.resize(10);
    cout << "Size: " << d.size() << endl;
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    if (d.empty())
        cout << "Deque is empty." << endl;
    else
        cout << "Deque is not empty." << endl;

    d.shrink_to_fit();
    cout << "Size: " << d.size() << endl;
}

/**
 * @brief Illustrates the element access operator of deque
 *
 */
void run_element_access()
{
    deque<int> d;
    for (int i = 1; i <= 5; i++)
    {
        d.push_back(i);
    }
    cout << "Element []: " << d[1] << endl;
    cout << "Element at: " << d.at(1) << endl;
    cout << "Element Front: " << d.front() << endl;
    cout << "Element Back: " << d.back() << endl;
}

/**
 * @brief Illustrates the modifier operator of deque
 *
 */
void run_modifiers()
{
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

    d.push_front(0);

    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    d.pop_back();
    d.pop_front();

    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // inserts front
    d.insert(d.begin(), 100);

    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // deletes the last element
    d.erase(d.end());

    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // tests swap
    deque<int> d1, d2;
    d1.push_back(1);
    d1.push_back(2);
    d2.push_back(3);
    d2.push_back(4);
    d2.push_back(5);

    d1.swap(d2);

    // prints all elements in deque
    for (auto iter = d1.begin(); iter != d1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints all elements in deque
    for (auto iter = d2.begin(); iter != d2.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // // clear all item
    // d.clear();
    // cout << "After Clear: ";
    // // prints all elements in deque
    // for (auto iter = d.begin(); iter != d.end(); ++iter)
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;

    auto it = d.emplace(d.begin(), 101);
    d.emplace(it, 201);
    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    d.emplace_front(301);
    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    d.emplace_back(-100);
    // prints all elements in deque
    for (auto iter = d.begin(); iter != d.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/*User Interface*/
int main()
{
    // run_iterators();
    // run_capacity();
    // run_element_access();
    run_modifiers();
    return 0;
}