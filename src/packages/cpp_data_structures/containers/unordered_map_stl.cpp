/*Illustration of unordered_map stl*/

// Note: the different between maps and sets is that maps allows the data type to be pair
// both containers hash data into buckets.
// Note: the key in the map is distinct regardless of the value. If there is duplication in key, then one of them will be deleted.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * @brief Runs capacity functions for unordered_map
 *
 */
void run_capacity()
{
    cout << "Test empty(): ";
    unordered_map<int, string> mymap = {{1, "Minh"}, {2, "Nguyen"}, {3, "Tran"}};

    if (mymap.empty())
        cout << "Map is empty." << endl;
    else
        cout << "Map is not empty." << endl;

    cout << "Size: " << mymap.size() << endl;
    cout << "Max Size: " << mymap.max_size() << endl;
}

/**
 * @brief Runs iterators functions for unordered_map
 *
 */
void run_iterators()
{
    unordered_map<int, string> mymap = {{1, "minh"}, {2, "nguyen"}, {3, "tran"}, {4, "binh"}};

    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = mymap.begin(i); iter != mymap.end(i); iter++)
        {
            // note that you can't change first (key) because it is the value used input to the hashing table which is needed to be constant for constant retrieval
            iter->second = "123";
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }
        cout << endl;
    }

    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = mymap.cbegin(i); iter != mymap.cend(i); iter++)
        {
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }
        cout << endl;
    }
}

/**
 * @brief Runs elements access functions for unordered_map
 *
 */
void run_element_access()
{
    unordered_map<int, string> mymap = {{1, "minh"}, {2, "nguyen"}, {3, "tran"}, {4, "binh"}};
    cout << mymap[1] << endl;
    cout << mymap.at(3) << endl;
}

/**
 * @brief Runs elements lookup functions find() for unordered_map
 *
 */
void run_element_lookup_find()
{
    unordered_map<int, string> mymap = {{1, "minh"}, {2, "nguyen"}, {3, "tran"}, {4, "binh"}};
    cout << "test find(): " << endl;
    int key;
    cout << "Please enter the elements that you want to find: ";
    cin >> key;

    auto iter = mymap.find(key);
    if (iter == mymap.end())
    { // if have traverse till the end of the database
        cout << "Not found." << endl;
    }
    else
    {
        cout << "Found: " << iter->first << ", " << iter->second << endl;
    }
}

/**
 * @brief Runs elements lookup functions count() for unordered_map
 *
 */
void run_element_lookup_count()
{
    unordered_map<int, string> mymap = {{1, "minh"}, {5, "123minh"}, {2, "nguyen"}, {3, "tran"}, {4, "binh"}};
    if (mymap.count(1) > 0)
        cout << "mymap has key 1." << endl;
    else
        cout << "mymap does not have key 1." << endl;
}

/**
 * @brief Runs modifiers functions for unordered_map
 *
 */
void run_modifiers()
{
}

/**
 * @brief Runs buckets functions for unordered_map
 *
 */
void run_buckets()
{
}

/**
 * @brief Runs hash policy funcotion for unordered_map
 *
 */
void run_hash_policy()
{
}

/**/
int main()
{
    // run_capacity();
    // run_iterators();
    // run_element_access();
    // run_element_lookup_find();
    run_element_lookup_count();
    return 0;
}