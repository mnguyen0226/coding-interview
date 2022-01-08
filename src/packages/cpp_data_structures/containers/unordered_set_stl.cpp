/*Illustration of Unordered-Set stl*/

// Note: Unordered containers organize their elements using hash tables that allow for fast access to elements by their key.

#include <iostream>
#include <unordered_set>
#include <string>
#include <array>

using namespace std;

/**
 * @brief Runs capacity functions for unordered list.
 *
 */
void run_capacity()
{
    unordered_set<int> myset = {5, 9, 4, 0, 3, 1};

    cout << "Checks empty: " << endl;
    if (myset.empty())
        cout << "Unordered Set is empty." << endl;
    else
        cout << "Unordered Set is not empty." << endl;

    cout << "Size: " << myset.size() << endl;
    cout << "Max Size: " << myset.max_size() << endl;
}

/**
 * @brief Runs iterator functions for unordered list.
 *
 */
void run_iterators()
{
    unordered_set<string> myset = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    cout << "myset contains / hash: ";
    for (auto iter = myset.begin(); iter != myset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl
         << endl;

    cout << "myset's buckets contains:\n";
    for (int i = 0; i < myset.bucket_count(); i++)
    {
        cout << "Bucket # " << i << " contains: ";
        for (auto bucket_iter = myset.begin(i); bucket_iter != myset.end(i); bucket_iter++)
        {
            cout << *bucket_iter << " ";
        }
        cout << endl;
    }

    cout << "myset contains / hash (can't modify *iter): ";
    for (auto iter = myset.cbegin(); iter != myset.cend(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs element lookup function find() for unordered list.
 *
 */
void run_element_lookup_find()
{
    cout << "Tests for find() in unordered_set: " << endl;
    unordered_set<string> colorset = {"red", "blue", "yellow"};
    string input;
    cout << "Please enter your color: ";
    getline(cin, input);

    unordered_set<string>::const_iterator iter_find = colorset.find(input);
    // this is how to check item in unordered_set
    if (iter_find == colorset.end())
        cout << "Not found in set" << endl;
    else
        cout << *iter_find << " found in set" << endl;
}

/**
 * @brief Runs element lookup function count() for unordered list.
 *
 */
void run_element_lookup_count()
{
    cout << "Tests for count() in unordered_set: " << endl;
    unordered_set<int> myset = {1, 0, 4, 93, 6, 2, 85};
    int input;
    cout << "Please enter the number that you want to count: "; // this is kinda useless because all elements are distinct
    cin >> input;
    cout << "There are " << myset.count(input) << " elememt " << input << endl;
}

/**
 * @brief Runs modifiers functions for unordered list.
 *
 */
void run_modifiers()
{
    cout << "Test emplace(): " << endl;
    unordered_set<int> myset;
    myset.emplace(1);
    myset.emplace(3);
    myset.emplace(5);
    myset.emplace(6);
    myset.emplace(7);

    // prints all elements and its storing hashing buckets
    cout << "myset contains: ";
    for (auto iter = myset.begin(); iter != myset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl
         << endl;

    for (int i = 0; i < myset.bucket_count(); i++)
    {
        cout << "Bucket # " << i << " contains: ";
        for (auto local_iter = myset.begin(i); local_iter != myset.end(i); local_iter++)
        {
            cout << *local_iter << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Test insert(): ";
    unordered_set<string> colorset = {"red"};
    array<string, 2> colorarr = {"blue", "green"};

    colorset.insert(colorarr.begin(), colorarr.end());
    cout << "colorset includes: ";
    for (auto iter = colorset.begin(); iter != colorset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Test erase(): ";
    colorset.erase("blue");
    cout << "colorset includes: ";
    for (auto iter = colorset.begin(); iter != colorset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Test clear(): ";
    colorset.clear();
    if (colorset.empty())
        cout << "Color set is empty." << endl;
    else
        cout << "Color set is not empty." << endl;

    cout << "Test swap(): " << endl;
    unordered_set<int> set1 = {1, 2, 3, 4, 5, 6};
    unordered_set<int> set2 = {7, 8, 9};
    set1.swap(set2);

    cout << "set1 includes: ";
    for (auto iter = set1.begin(); iter != set1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "set2 includes: ";
    for (auto iter = set2.begin(); iter != set2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * @brief Runs buckets functions for unordered list.
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
 * @brief Runs hash policy functions for unordered list.
 *
 * rehash()
 * - Sets the number of buckets in the containers to n or more.
 * - If n is greater than the current number of buckets in the container (bucket_count), a rehash is forced. The new bucket count can be either be equal or greater than n.
 * - If n is lower than the current number of buckets in the container (bucket_count), the function may have no effect on the bucket count and may not fortce a rehash.
 * - A rehash is the reconstruction of hash table: All the elements in the container are rearranged according to their hash value into the new set of buckets.
 * This may alter the order of iteration of elements within the container.
 * - Rehashes are automatically performed by the container whenever its load facto is going to surpass its max_load_facter in  an operation.
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