/*Illustration of forward-list container stl*/

#include <iostream>
#include <forward_list>

using namespace std;

/**
 * @brief Runs operators of iterator for singly linked list
 *
 */
void run_iterator()
{
    // initializes linked list
    forward_list<int> mylist = {1, 2, 3, 4, 5};

    // insert 100 at the front of linked list
    mylist.insert_after(mylist.before_begin(), 100);

    // prints out all elements of linked list
    for (auto iter = mylist.begin(); iter != mylist.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    mylist.insert_after(mylist.cbefore_begin(), 200);
    // prints out all elements of linked list
    for (auto iter = mylist.cbegin(); iter != mylist.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // try linked list with string
    forward_list<string> mystringlist;
    mystringlist.insert_after(mystringlist.before_begin(), "hello");
    mystringlist.insert_after(mystringlist.before_begin(), "bruh");

    // prints out all elements of linked list, can use constrant
    for (auto iter = mystringlist.cbegin(); iter != mystringlist.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs operators of capacity for singly linked list
 *
 */
void run_capacity()
{
    forward_list<int> mylist = {1, 2, 3, 4, 5, 6};

    // checks emptyness
    if (mylist.empty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty" << endl;

    // check max size
    cout << "Max Size: " << mylist.max_size() << endl;
}

/**
 * @brief Runs operators of element access for singly linked list
 *
 */
void run_element_access()
{
    forward_list<int> mylist = {1, 2, 3};

    // checks the first element
    cout << "The first element is: " << mylist.front() << endl;
}

/**
 * @brief Runs operators of modifier for singly linked list
 *
 */
void run_modifiers()
{
    // test assign() - assign x number of element e
    cout << "\nTest assign() -----" << endl;
    forward_list<int> first, second;

    first.assign(4, 111);
    second.assign(first.begin(), first.end());

    first.assign({1, 2, 3, 4, 5, 6});

    cout << "First linked list: ";
    for (int x : first)
        cout << x << " ";
    cout << endl;

    cout << "Second linked list: ";
    for (auto x : second)
        cout << x << " ";
    cout << endl;

    // tests emplace_front()
    cout << "\nTest emplace_front() -----" << endl;
    forward_list<pair<int, char>> mypairlist;

    // inserts element in the front of linked list
    mypairlist.emplace_front(10, 'c');
    mypairlist.emplace_front(10, 'd');

    for (auto x : mypairlist)
        cout << '(' << x.first << ',' << x.second << ") ";
    cout << endl;

    // tests push_front()
    cout << "\nTest push_front() -----" << endl;
    forward_list<int> mylist;
    mylist.push_front(10);
    mylist.push_front(20);
    mylist.push_front(30);

    for (auto x : mylist)
        cout << x << " ";
    cout << endl;

    // tests pop_front()
    cout << "\nTest pop_front() -----" << endl;
    mylist.pop_front();
    for (auto x : mylist)
        cout << x << " ";
    cout << endl;

    // tests emplace_after()
    cout << "\nTest emplace_after() -----" << endl;
    forward_list<pair<int, string>> mynewlist;
    auto iter = mynewlist.before_begin();

    iter = mynewlist.emplace_after(iter, 10, "Minh");
    iter = mynewlist.emplace_after(iter, 20, "Nguyen");
    iter = mynewlist.emplace_after(iter, 30, "Yes");

    for (auto x : mynewlist)
        cout << '(' << x.first << ',' << x.second << ") ";
    cout << endl;

    // tests insert_after()
    cout << "\nTest insert_after() -----" << endl;
    forward_list<int> myintlist;
    myintlist.insert_after(myintlist.before_begin(), 10);
    myintlist.insert_after(myintlist.before_begin(), 20);
    myintlist.insert_after(myintlist.before_begin(), 30);

    for (auto iter = myintlist.begin(); iter != myintlist.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // tests erase_after()
    cout << "\nTest erase_after() -----" << endl;
    forward_list<int> myeraselist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    myeraselist.erase_after(myeraselist.before_begin());
    for (auto x : myeraselist)
        cout << x << " ";
    cout << endl;

    // shows position 3: 5
    auto new_iter = myeraselist.begin();
    new_iter++;
    new_iter++;
    new_iter++;
    cout << "\nPosition 3: " << *new_iter << endl;

    // delete 5
    myeraselist.erase_after(new_iter);
    for (auto x : myeraselist)
        cout << x << " ";
    cout << endl;

    // delete fron position 3 to end
    myeraselist.erase_after(new_iter, myeraselist.end());
    for (auto x : myeraselist)
        cout << x << " ";
    cout << endl;

    // tests swap()
    cout << "\nTests swap: -----" << endl;
    forward_list<int> list1, list2;
    list1.push_front(1);
    list1.push_front(2);
    list2.push_front(3);
    list2.push_front(4);
    list2.push_front(5);
    list1.swap(list2);

    cout << "List 1: ";
    for (auto x : list1)
        cout << x << " ";
    cout << endl
         << "List 2:";
    for (auto x : list2)
        cout << x << " ";
    cout << endl;

    // tests clear()
    cout << "\nTests clear: -----" << endl;
    list1.clear();
    if (list1.empty())
        cout << "List 1 is empty." << endl;

    // tests resize()
    cout << "\nTests resize: -----" << endl;
    forward_list<int> new_linked_list = {1, 2, 3, 4, 5, 6};
    new_linked_list.resize(3);
    new_linked_list.resize(10, 1000);
    for (auto x : new_linked_list)
        cout << x << " ";
    cout << endl;
}

int main()
{
    // run_iterator();
    // run_capacity();
    // run_element_access();
    run_modifiers();
    return 0;
}