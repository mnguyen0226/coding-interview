/*Illustration of Unordered-Set stl*/

#include <iostream>
#include <unordered_set>

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
}

/**
 * @brief Runs element lookup functions for unordered list.
 *
 */
void run_element_lookup()
{
}

/**
 * @brief Runs modifiers functions for unordered list.
 *
 */
void run_modifiers()
{
}

/**
 * @brief Runs buckets functions for unordered list.
 *
 */
void run_buckets()
{
}

/**
 * @brief Runs hash policy functions for unordered list.
 *
 */
void run_hash_policy()
{
}

/**
 * @brief Runs observer functions for unordered list.
 *
 */
void run_observer()
{
}

/*User Interface*/
int main()
{
    // run_capacity();
    run_iterators();
    // run_element_lookup();
    // run_modifiers();
    // run_buckets();
    // run_hash_policy();
    // run_observer();
    return 0;
}