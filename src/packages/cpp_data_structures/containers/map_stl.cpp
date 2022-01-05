/*Illustration of map stl*/

#include <iostream>
#include <map>

using namespace std;

/**
 * @brief Traverses through
 *
 * @param m
 */
void traversal_bst(map<string, int> m)
{
    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        cout << '[' << iter->first << "," << iter->second << ']' << "; ";
    }
    cout << endl;
}

/**
 * @brief Runs iterator functions for map
 *
 */
void run_iterators()
{
    map<string, int> mymap;

    mymap["minh"] = 100;
    mymap["nguyen"] = 200;
    mymap["tran"] = 300;
    mymap["aaron"] = 400;

    cout << "In-order traversal: " << endl;
    for (auto iter = mymap.begin(); iter != mymap.end(); ++iter)
    {
        cout << '[' << iter->first << "," << iter->second << ']' << "; ";
    }
    cout << endl;

    cout << "In-order traversal: " << endl;
    for (auto iter = mymap.cbegin(); iter != mymap.cend(); ++iter)
    {
        cout << '[' << iter->first << "," << iter->second << ']' << "; ";
    }
    cout << endl;

    cout << "In-order reverse traversal: " << endl;
    for (auto iter = mymap.rbegin(); iter != mymap.rend(); ++iter)
    {
        cout << '[' << iter->first << "," << iter->second << ']' << "; ";
    }
    cout << endl;

    cout << "In-order reverse traversal: " << endl;
    for (auto iter = mymap.crbegin(); iter != mymap.crend(); ++iter)
    {
        cout << '[' << iter->first << "," << iter->second << ']' << "; ";
    }
    cout << endl;
}

/**
 * @brief Runs capacity functions for map
 *
 */
void run_capacity()
{
    map<string, int> mymap;

    mymap["minh"] = 100;
    mymap["nguyen"] = 200;
    mymap["tran"] = 300;
    mymap["aaron"] = 400;

    if (mymap.empty())
    {
        cout << "Map is empty." << endl;
    }
    else
    {
        cout << "Map is not empty." << endl;
    }

    cout << "Size: " << mymap.size() << endl;
    cout << "Max Size: " << mymap.max_size() << endl;
}

/**
 * @brief Runs element access functions for map
 *
 */
void run_element_access()
{
    map<string, int> mymap;

    mymap["minh"] = 100;
    mymap["nguyen"] = 200;
    mymap["tran"] = 300;
    mymap["aaron"] = 400;

    cout << "Element of 'minh' is: " << mymap["minh"] << endl;
    cout << "Element of 'minh' is: " << mymap.at("minh") << endl;
}

/**
 * @brief Runs modifiers functions for map
 *
 */
void run_modifiers()
{
    map<string, int> mymap;

    mymap["minh"] = 100;
    mymap["nguyen"] = 200;
    mymap["tran"] = 300;
    mymap["aaron"] = 400;

    cout << "Insert: " << endl;
    mymap.insert(pair<string, int>("bi", 123));
    traversal_bst(mymap);

    cout << "Erase: " << endl;
    mymap.erase("aaron");
    traversal_bst(mymap);

    map<string, int> mymap2;
    mymap2["minh"] = 456;
    mymap2["nguyen"] = 789;
    mymap.swap(mymap2);
    cout << "Swap: " << endl;
    traversal_bst(mymap);
    traversal_bst(mymap2);

    cout << "Emplace: " << endl;
    mymap.emplace(pair<string, int>("bruh", 1111));
    traversal_bst(mymap);
}

/**
 * @brief Runs operation functions for map
 *
 */
void run_operation()
{
    map<string, int> mymap;

    mymap["minh"] = 100;
    mymap["nguyen"] = 200;
    mymap["tran"] = 300;
    mymap["aaron"] = 400;

    cout << "Find: " << mymap.find("minh")->second << endl;
    cout << "Count: " << mymap.count("minh") << endl;

    cout << "Bound: " << endl;
    // must get the right lower and upper bound
    auto iter_lower = mymap.lower_bound("nguyen");
    auto iter_upper = mymap.upper_bound("tran");
    mymap.erase(iter_lower, iter_upper);
    traversal_bst(mymap);
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