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
    list<int> mylist = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // check empty
    if (mylist.empty())
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;

    // check size
    cout << "Size: " << mylist.size() << endl;

    // check max size
    cout << "Max Size: " << mylist.max_size() << endl;
}

/**
 * @brief Runs element access functions for doubly linked list
 *
 */
void run_element_access()
{
    list<int> mylist = {1, 2, 3, 4, 5};

    cout << "Front element: " << mylist.front() << endl;
    cout << "Back element: " << mylist.back() << endl;
}

/**
 * @brief forward traverse the linked list
 *
 * @param l
 */
void traverse_print(list<int> l)
{
    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs modifiers functions for doubly linked list
 *
 */
void run_modifiers()
{
    list<int> mylist;
    // tests assign, 1x100
    mylist.assign(1, 100);
    traverse_print(mylist);

    // tests emplace_front
    mylist.emplace_front(10);
    mylist.emplace_front(20);
    traverse_print(mylist);

    // tests emplace_back
    mylist.emplace_back(-1);
    mylist.emplace_back(-2);
    traverse_print(mylist);

    // tests push_front
    mylist.push_front(30);
    mylist.push_front(40);
    traverse_print(mylist);

    // tests pop_front
    mylist.pop_front();
    traverse_print(mylist);

    // tests push_back
    mylist.push_back(-3);
    mylist.push_back(-4);
    traverse_print(mylist);

    // tests pop_back
    mylist.pop_back();
    traverse_print(mylist);

    // tests emplace
    auto iter = mylist.begin();
    iter++;
    mylist.emplace(iter, 55555);
    traverse_print(mylist);

    // tests erase (at a position)
    iter++;
    mylist.erase(iter);
    traverse_print(mylist);

    // tests swap
    list<int> list2;
    list2.assign(5, 123);
    list2.swap(mylist);
    traverse_print(mylist);

    // tests resize
    mylist.resize(3);
    traverse_print(mylist);

    // tests clear
    mylist.clear();
    if (mylist.empty())
        cout << "List is empty" << endl;
}

/*Determines negative numbers*/
bool negative(int &value)
{
    return value < 0;
}

/**
 * @brief Runs operations functions for doubly linked list
 *
 */
void run_operation()
{
    list<int> mylist1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> mylist2 = {-1, -2, 100};

    // add mylist2 to begin of list 1 (similar to merge)
    mylist1.splice(mylist1.begin(), mylist2);
    cout << "Splice: " << endl;
    traverse_print(mylist1);
    traverse_print(mylist2);

    mylist1.remove(100); // delete element with specific value
    cout << "Remove: " << endl;
    traverse_print(mylist1);

    mylist1.remove_if(negative);
    cout << "Remove if: " << endl;
    traverse_print(mylist1);

    mylist2 = {1, 1, 1, 1, 1};
    mylist2.merge(mylist1);
    cout << "Merge: " << endl;
    traverse_print(mylist1);
    traverse_print(mylist2);

    mylist2.push_front(1000);
    mylist2.sort();
    cout << "Sort: " << endl;
    traverse_print(mylist2);

    mylist2.reverse();
    cout << "Reverse: " << endl;
    traverse_print(mylist2);
}

/*User Interface*/
int main()
{
    // run_iterators();
    // run_capacity();
    // run_element_access();
    // run_modifiers();
    run_operation();
    return 0;
}