/*Illustration of set stl*/

#include <iostream>
#include <set>

using namespace std;

/**
 * @brief Runs iterator function for bst
 *
 */
void run_iterators()
{
    set<int> bst = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // prints out all elements in bst
    for (auto iter = bst.begin(); iter != bst.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints out reverse elements in bst
    for (auto iter = bst.rbegin(); iter != bst.rend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints out all elements in bst
    for (auto iter = bst.cbegin(); iter != bst.cend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // prints out reverse elements in bst
    for (auto iter = bst.crbegin(); iter != bst.crend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs capacity function for bst
 *
 */
void run_capacity()
{
    set<int> bst = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // check emptyness
    if (bst.empty())
        cout << "BST is empty." << endl;
    else
        cout << "BST is not empty." << endl;

    cout << "Size: " << bst.size() << endl;
    cout << "Max Size: " << bst.max_size() << endl;
}

/*Inorder traversal*/
void traversal(set<int> bst)
{
    for (auto iter = bst.begin(); iter != bst.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs modifiers function for bst
 *
 */
void run_modifiers()
{
    set<int> bst = {1, 2, 3, 4, 6, 7, 8, 9};
    cout << "Insert: " << endl;
    bst.insert(5); // auto sort in bst
    traversal(bst);

    cout << "Erase: " << endl;
    bst.erase(7);
    traversal(bst);

    cout << "Swap: " << endl;
    set<int> bst2 = {123, 456, 789};
    bst.swap(bst2);
    traversal(bst);
    traversal(bst2);

    cout << "Clear: " << endl;
    bst2.clear();
    if (bst2.empty())
    {
        cout << "BST is empty." << endl;
    }
    else
    {
        cout << "BST is not empty." << endl;
    }

    cout << "Emplace: " << endl;
    bst.emplace(-1);
    traversal(bst);

    cout << "Emplace Hint: " << endl;
    bst.emplace_hint(bst.end(), -3);
    traversal(bst);
}

/**
 * @brief Runs operations function for bst
 *
 */
void run_operations()
{
    set<int> s;

    // populate the bst
    for (int i = 1; i <= 5; i++)
        s.insert(i);

    auto iter = s.find(2);
    s.erase(iter);

    traversal(s);

    // count elements with specific value
    cout << "Number of 1 is, whether there is a 1: " << s.count(1) << endl;

    set<int> bst;
    for (int i = 1; i < 10; i++)
        bst.insert(i * 10);

    auto iter_low = bst.lower_bound(30);
    auto iter_high = bst.upper_bound(60);

    bst.erase(iter_low, iter_high);
    traversal(bst);
}

/*User Interface*/
int main()
{
    // run_iterators();
    // run_capacity();
    // run_modifiers();
    run_operations();
    return 0;
}