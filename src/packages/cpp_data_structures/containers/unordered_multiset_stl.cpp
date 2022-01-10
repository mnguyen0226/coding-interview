/*Illustration of Unordered-Set stl*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <array>

using namespace std;

/**
 * @brief Runs capacity functions of unordered_multiset
 *
 */
void run_capacity()
{
    cout << "Test empty: ";
    unordered_multiset<int> myset = {1, 2, 3, 4, 5, 6, 1, 1, 1, 1};
    if (myset.empty())
        cout << "myset is empty." << endl;
    else
        cout << "myset is not empty." << endl;

    cout << endl;

    cout << "Size: " << myset.size() << endl
         << endl;
    cout << "Max Size: " << myset.max_size();
}

/**
 * @brief Runs iterator functions of unordered_multiset
 *
 */
void run_iterators()
{
    unordered_multiset<string> myset = {"minh", "nguyen", "tran", "binh"};
    cout << "myset contains: ";
    for (auto iter = myset.begin(); iter != myset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    for (int i = 0; i < myset.bucket_count(); i++)
    {
        cout << "Bucket # " << i << " contains: ";
        for (auto local_iter = myset.begin(i); local_iter != myset.end(i); local_iter++)
        {
            cout << *local_iter << " ";
        }
        cout << endl;
    }

    cout << "myset contains: ";
    for (auto iter = myset.cbegin(); iter != myset.cend(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs element look up find() of unordered_multiset
 *
 */
void run_element_lookup_find()
{
    cout << "Tests for find() in unordered_set: " << endl;
    unordered_multiset<string> colorset = {"red", "red", "blue"};
    string input;
    cout << "Please enter the color: ";
    getline(cin, input);

    unordered_multiset<string>::const_iterator iter_found = colorset.find(input);
    if (iter_found == colorset.end())
        cout << "Not found." << endl;
    else
        cout << "Found " << *iter_found << endl;
}

/**
 * @brief Runs element look up count() of unordered_multiset
 *
 */
void run_element_lookup_count()
{
    cout << "Test count: " << endl;
    unordered_multiset<string> colorset = {"red", "red", "blue", "blue", "green"};
    for (auto &x : {"red", "blue", "green"})
    {
        cout << x << ": " << colorset.count(x) << endl;
    }
}

/**
 * @brief Function prints out string unordered set
 *
 * @param myset
 */
void print_set(unordered_multiset<string> myset)
{
    for (auto iter = myset.begin(); iter != myset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Function checks whether the set is empty or not
 *
 * @param myset
 */
void check_empty(unordered_multiset<string> myset)
{
    if (myset.empty())
    {
        cout << "Set is empty." << endl;
    }
    else
    {
        cout << "Set is not empty." << endl;
    }
}

/**
 * @brief Runs modifiers function of unordered_multiset
 *
 */
void run_modifiers()
{
    unordered_multiset<string> colorset;
    colorset.emplace("Red");
    colorset.emplace("Blue");
    colorset.emplace("Green");
    colorset.emplace("Red");

    print_set(colorset);

    colorset.insert("Minh");
    print_set(colorset);

    colorset.clear();
    check_empty(colorset);

    unordered_multiset<string> myset1 = {"minh", "nguyen", "tran"};
    unordered_multiset<string> myset2 = {"minh", "minh", "minh"};

    myset1.swap(myset2);
    print_set(myset1);
    print_set(myset2);
}

/**
 * @brief Runs buckets functions of unordered_multiset
 *
 */
void run_buckets()
{
    cout << "Test bucket_count(): " << endl;
    unordered_set<int> myset = {1, 2, 3, 4, 5, 6, 7, 100, 10000};
    cout << "Number of bucket is: " << myset.bucket_count() << endl;

    cout << "Test max_bucket_count(): " << endl;
    cout << "Max Bucket Count: " << myset.max_bucket_count() << endl;

    cout << "Test bucket_size(): " << endl;
    unordered_set<string> nameset = {"Minh", "Nguyen", "Tran", "Binh"};
    for (int i = 0; i < nameset.bucket_count(); i++)
    {
        cout << "Bucket " << i << " has " << nameset.bucket_size(i) << endl;
    }
    cout << endl;

    cout << "Test bucket() - locate the bucket of input data: " << endl;
    for (auto iter = nameset.begin(); iter != nameset.end(); iter++)
    {
        cout << *iter << " belongs to bucket #: " << nameset.bucket(*iter) << endl;
    }
}

/**
 * @brief Runs hash policy functions of unordered_multiset
 *
 */
void run_hash_policy()
{
    cout << "Test loading factor: " << endl;
    unordered_set<int> name;
    cout << "Loading Factor: " << name.load_factor() << endl;
    cout << "Max Loading Factor: " << name.max_load_factor() << endl;

    cout << "Test rehash(): " << endl;
    unordered_set<int> myset;
    cout << "Current bucket_count: " << myset.bucket_count() << endl;
    myset.rehash(11);
    myset.insert(1);
    myset.insert(2);
    myset.insert(100);
    cout << "After rehash() current bucket bucket_count: " << myset.bucket_count() << endl;

    // reserve() sets the number of buckets in the container (bucket_count) to the most approprate to contain at least n elements.
    unordered_set<int> myintset;
    myintset.reserve(6);
    myintset.insert(1);
    myintset.insert(123123);
    myintset.insert(6);
    myintset.insert(65);
    myintset.insert(2);

    cout << "myintset contains: ";
    for (auto iter = myintset.begin(); iter != myintset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "Number of buckets: " << myintset.bucket_count() << endl;

    for (int i = 0; i < myintset.bucket_count(); i++)
    {
        cout << "Bucket # " << i << " has a size: " << myintset.bucket_size(i) << " contains: ";
        for (auto local_iter = myintset.begin(i); local_iter != myintset.end(i); local_iter++)
        {
            cout << *local_iter << " ";
        }
        cout << endl;
    }
}


/*User Interface*/
int main()
{
    // run_capacity();
    // run_iterators();
    // run_element_lookup_find();
    // run_element_lookup_count();
    // run_modifiers();
    // run_buckets();
    run_hash_policy();
    return 0;
}