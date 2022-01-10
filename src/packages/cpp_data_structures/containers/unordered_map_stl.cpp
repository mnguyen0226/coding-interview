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
    unordered_map<int, string> mymap = {{1, "minh"}, {5, "123minh"}, {2, "nguyen"}, {3, "tran"}, {4, "binh"}};
    cout << "Test emplace(): " << endl;
    mymap.emplace(6, "bruh");

    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = mymap.cbegin(i); iter != mymap.cend(i); iter++)
        {
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }
        cout << endl;
    }

    // can insert a multimap to another multimap
    cout << "Test insert(): " << endl;
    mymap.insert({{7, "min"}, {8, "456"}});

    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = mymap.cbegin(i); iter != mymap.cend(i); iter++)
        {
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }
        cout << endl;
    }

    cout << "Test erase(): " << endl;
    mymap.erase(1);
    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = mymap.cbegin(i); iter != mymap.cend(i); iter++)
        {
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }
        cout << endl;
    }

    cout << "Test clear(): " << endl;
    mymap.clear();
    if (mymap.empty())
        cout << "mymap has been erase." << endl;
    else
        cout << "mymap has not been erase." << endl;

    cout << "Test swap(): " << endl;
    unordered_map<int, int> map1 = {{1, 123}, {2, 234}};
    unordered_map<int, int> map2 = {{3, 345}, {4, 456}};
    map1.swap(map2);

    for (int i = 0; i < map1.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = map1.cbegin(i); iter != map1.cend(i); iter++)
        {
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }

        cout << endl;
    }

    for (int i = 0; i < map2.bucket_count(); i++)
    {
        cout << "The bucket #: " << i << " stores: ";
        for (auto iter = map2.cbegin(i); iter != map2.cend(i); iter++)
        {
            cout << "( " << iter->first << ", " << iter->second << "); ";
        }
        cout << endl;
    }
}

/**
 * @brief Runs buckets functions for unordered_map
 *
 */
void run_buckets()
{
    unordered_map<int, string> mymap = {{1, "minh"}, {5, "123minh"}, {2, "nguyen"}, {3, "tran"}, {4, "binh"}};
    cout << "Bucket counts:  " << mymap.bucket_count() << endl
         << endl;
    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "Bucket #" << i << " has size: " << mymap.bucket_size(i) << endl;
    }
    cout << endl;

    cout << "Max bucket count: " << mymap.max_bucket_count() << endl;

    cout << "Element key 1 is located at bucket: " << mymap.bucket(1) << endl;
}

/**
 * @brief Runs hash policy funcotion for unordered_map
 *
 */
void run_hash_policy()
{
    cout << "Test loading factor: " << endl;
    unordered_multimap<int, string> mymap;
    cout << "Loading Factor: " << mymap.load_factor() << endl;
    cout << "Max Loading Factor: " << mymap.max_load_factor() << endl;

    cout << "Test rehash(): " << endl;
    cout << "Current bucket_count: " << mymap.bucket_count() << endl;
    mymap.rehash(11);
    mymap.insert({1, "minh"});
    mymap.insert({2, "nguyen"});
    mymap.insert({100, "tran"});
    cout << "After rehash() current bucket bucket_count: " << mymap.bucket_count() << endl;

    // reserve() sets the number of buckets in the container (bucket_count) to the most approprate to contain at least n elements.
    mymap.reserve(6);

    cout << "mymap contains: ";
    for (auto iter = mymap.begin(); iter != mymap.end(); iter++)
    {
        cout << "( " << iter->first << ", " << iter->second << "); ";
    }
    cout << endl;
    cout << "Number of buckets: " << mymap.bucket_count() << endl;

    for (int i = 0; i < mymap.bucket_count(); i++)
    {
        cout << "Bucket # " << i << " has a size: " << mymap.bucket_size(i) << " contains: ";
        for (auto local_iter = mymap.begin(i); local_iter != mymap.end(i); local_iter++)
        {
            cout << "( " << local_iter->first << ", " << local_iter->second << "); ";
        }
        cout << endl;
    }
}

/**/
int main()
{
    // run_capacity();
    // run_iterators();
    // run_element_access();
    // run_element_lookup_find();
    // run_element_lookup_count();
    // run_modifiers();
    // run_buckets0();
    run_hash_policy();
    return 0;
}