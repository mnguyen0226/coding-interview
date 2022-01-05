# C++ Containers Operators

[Reference](https://www.cplusplus.com/reference/stl/).

# Sequence Containers

## :heavy_check_mark: 1. `<array>` - array

| Operators | Meaning                        |
| --------- | ------------------------------ |
| begin     | Returns iterator to beginning. |
| end       | Returns iterator to end.       |

## :heavy_check_mark: 2. `<vector>` - dynamic array

### Iterators:

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity:

| Operators     | Meaning                                     |
| ------------- | ------------------------------------------- |
| size          | Returns size.                               |
| max_size      | Returns max size.                           |
| resize        | Changes size.                               |
| capacity      | Returns size of allocated storage capacity. |
| empty         | Tests whether vector is empty.              |
| reserve       | Requests a change in capacity.              |
| shrink_to_fit | Shrink to fit.                              |

### Element Access:

| Operators  | Meaning               |
| ---------- | --------------------- |
| operator[] | Access element.       |
| at         | Access element.       |
| front      | Access first element. |
| back       | Access last element.  |
| data       | Access data.          |

### Modifiers:

| Operators    | Meaning               |
| ------------ | --------------------- |
| assign       | Access element.       |
| push_back    | Access element.       |
| pop_back     | Access first element. |
| insert       | Access last element.  |
| erase        | Access data.          |
| swap         | Access data.          |
| clear        | Access data.          |
| emplace      | Access data.          |
| emplace_back | Access data.          |

## :heavy_check_mark: 3. `<deque>` - double ended queue

### Iterators:

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity:

| Operators     | Meaning                        |
| ------------- | ------------------------------ |
| size          | Returns size.                  |
| max_size      | Returns max size.              |
| resize        | Changes size.                  |
| empty         | Tests whether vector is empty. |
| shrink_to_fit | Shrink to fit.                 |

### Element Access:

| Operators  | Meaning               |
| ---------- | --------------------- |
| operator[] | Access element.       |
| at         | Access element.       |
| front      | Access first element. |
| back       | Access last element.  |

### Modifiers:

| Operators     | Meaning                                     |
| ------------- | ------------------------------------------- |
| assign        | Access container content.                   |
| push_back     | Adds element at the end.                    |
| push_front    | Inserts element at beginning.               |
| pop_back      | Deletes last element.                       |
| pop_front     | Access first element.                       |
| insert        | Inserts elements.                           |
| erase         | Erases elements.                            |
| swap          | Swaps elements.                             |
| clear         | Clears content.                             |
| emplace       | Constructs and insert element.              |
| emplace_front | Constructs and insert element at beginning. |
| emplace_back  | Constructs and insert element at end.       |

## :heavy_check_mark: 4. `<forward_list>` - singly linked list

- About: forward_list objects are thus more efficient than list objects, although they can only be iterated forwards. Compared to other base standard sequence containers (array, vector and deque), forward_list perform generally better in inserting, extracting and moving elements in any position within the container, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

### Iterators

| Operators     | Meaning                                     |
| ------------- | ------------------------------------------- |
| before_begin  | Returns iterator to before beginning.       |
| begin         | Returns iterator to beginning.              |
| end           | Returns iterator to end.                    |
| cbefore_begin | Returns const_iterator to before beginning. |
| cbegin        | Retusns const_iterator to beginning.        |
| cend          | Returns const_iterator to end.              |

### Capacity

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| max_size  | Returns maximum size.         |

### Element Access

| Operators | Meaning               |
| --------- | --------------------- |
| front     | Access first element. |

### Modifiers

| Operators     | Meaning                                     |
| ------------- | ------------------------------------------- |
| assign        | Assigns content.                            |
| emplace_front | Constructs and insert element at beginning. |
| push_front    | Inserts element at beginning.               |
| pop_front     | Deletes first element.                      |
| emplace_after | Constructs and inserts element at end.      |
| insert_after  | Inserts elements.                           |
| erase_after   | Erases elements.                            |
| swap          | Swaps elements.                             |
| clear         | Clears content.                             |
| resize        | Changes size.                               |

### Operations

| Operators    | Meaning                                       |
| ------------ | --------------------------------------------- |
| splice_after | Transfers elements from another forward_list. |
| remove       | Removes elements with specific value.         |
| remove_if    | Removes elements fulfilling condition.        |
| unique       | Removes duplicate values.                     |
| merge        | Merges sorted list.                           |
| sort         | Sorted elements in container.                 |
| reverse      | Reverses the order of elements.               |

## :heavy_check_mark: 5. `<list>` - doubly linked list

### Iterators

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| size      | Returns size.                 |
| max_size  | Returns maximum size.         |

### Element Access

| Operators | Meaning               |
| --------- | --------------------- |
| front     | Access first element. |
| back      | Access last element.  |

### Modifiers

| Operators     | Meaning                                     |
| ------------- | ------------------------------------------- |
| assign        | Assigns content.                            |
| emplace_front | Constructs and insert element at beginning. |
| push_front    | Inserts element at beginning.               |
| pop_front     | Deletes first element.                      |
| emplace_back  | Constructs and insert element at beginning. |
| push_back     | Adds element at the end                     |
| pop_back      | Deletes last element.                       |
| emplace       | Constructs and inserts element.             |
| insert        | Inserts elements.                           |
| erase         | Erases elements.                            |
| swap          | Swaps elements.                             |
| resize        | Changes size.                               |
| clear         | Clears content.                             |

### Operations

| Operators | Meaning                                |
| --------- | -------------------------------------- |
| splice    | Transfers elements from list to list.  |
| remove    | Removes elements with specific value.  |
| remove_if | Removes elements fulfilling condition. |
| unique    | Removes duplicate values.              |
| merge     | Merges sorted list.                    |
| sort      | Sorted elements in container.          |
| reverse   | Reverses the order of elements.        |

# Containers Adaptors

## :heavy_check_mark: 1. `<stack>` - LIFO stack

| Operators | Meaning                           |
| --------- | --------------------------------- |
| empty     | Tests whether container is empty. |
| size      | Returns size.                     |
| top       | Access next element.              |
| push      | Inserts element.                  |
| emplace   | Constructs and inserts element.   |
| pop       | Removes top element.              |
| swap      | Swap contents.                    |

## :heavy_check_mark: 2. `<queue>` - FIFO queue

| Operators | Meaning                           |
| --------- | --------------------------------- |
| empty     | Tests whether container is empty. |
| size      | Returns size.                     |
| front     | Access next element.              |
| back      | Access last element.              |
| push      | Inserts element.                  |
| emplace   | Constructs and inserts element.   |
| pop       | Removes next element.             |
| swap      | Swap contents.                    |

## :heavy_check_mark: 3. `<priority_queue>` - heap

| Operators | Meaning                           |
| --------- | --------------------------------- |
| empty     | Tests whether container is empty. |
| size      | Returns size.                     |
| top       | Access top element.               |
| push      | Inserts element.                  |
| emplace   | Constructs and inserts element.   |
| pop       | Removes next element.             |
| swap      | Swap contents.                    |

# Associative Containers

## :heavy_check_mark: 1. `<set>` - binary search tree

### Iterators

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| size      | Returns size.                 |
| max_size  | Returns maximum size.         |

### Modifiers

| Operators    | Meaning                                  |
| ------------ | ---------------------------------------- |
| insert       | Insert elemnent.                         |
| erase        | Erase elements.                          |
| swap         | Swap content.                            |
| clear        | Clear content.                           |
| emplace      | Constructs and insert element.           |
| emplace_hint | Constructs and insert element with hint. |

### Observers

| Operators   | Meaning                    |
| ----------- | -------------------------- |
| key_comp    | Returns comparison object. |
| value_compt | Returns comparion object.  |

### Operations:

| Operators   | Meaning                                |
| ----------- | -------------------------------------- |
| find        | Gets iterator to elements.             |
| count       | Counts elements with a specific value. |
| lower_bound | Returns iterator to lower bound.       |
| upper_bound | Returns iterator to upper bound.       |
| equal_range | Get range of equal elements.           |

## :heavy_check_mark: 2. `<multiset>` - Multiple-key set, bst

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| size      | Returns size.                 |
| max_size  | Returns maximum size.         |

### Modifiers

| Operators    | Meaning                                  |
| ------------ | ---------------------------------------- |
| insert       | Insert elemnent.                         |
| erase        | Erase elements.                          |
| swap         | Swap content.                            |
| clear        | Clear content.                           |
| emplace      | Constructs and insert element.           |
| emplace_hint | Constructs and insert element with hint. |

### Observers

| Operators   | Meaning                    |
| ----------- | -------------------------- |
| key_comp    | Returns comparison object. |
| value_compt | Returns comparion object.  |

### Operations:

| Operators   | Meaning                                |
| ----------- | -------------------------------------- |
| find        | Gets iterator to elements.             |
| count       | Counts elements with a specific value. |
| lower_bound | Returns iterator to lower bound.       |
| upper_bound | Returns iterator to upper bound.       |
| equal_range | Get range of equal elements.           |

## :heavy_check_mark: 3. `<map>` - associative arrays

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| size      | Returns size.                 |
| max_size  | Returns maximum size.         |

### Element Access:

| Operators  | Meaning         |
| ---------- | --------------- |
| operator[] | Access element. |
| at         | Access element. |

### Modifiers

| Operators    | Meaning                                  |
| ------------ | ---------------------------------------- |
| insert       | Insert elemnent.                         |
| erase        | Erase elements.                          |
| swap         | Swap content.                            |
| clear        | Clear content.                           |
| emplace      | Constructs and insert element.           |
| emplace_hint | Constructs and insert element with hint. |

### Observers

| Operators   | Meaning                    |
| ----------- | -------------------------- |
| key_comp    | Returns comparison object. |
| value_compt | Returns comparion object.  |

### Operations:

| Operators   | Meaning                                |
| ----------- | -------------------------------------- |
| find        | Gets iterator to elements.             |
| count       | Counts elements with a specific value. |
| lower_bound | Returns iterator to lower bound.       |
| upper_bound | Returns iterator to upper bound.       |
| equal_range | Get range of equal elements.           |

## :heavy_check_mark: 4. `<multimap>` - Multiple-key map

| Operators | Meaning                                              |
| --------- | ---------------------------------------------------- |
| begin     | Returns iterator to beginning.                       |
| end       | Returns iterator to end.                             |
| rbegin    | Returns reverse iterator to reverse beginning.       |
| rend      | Returns reverse iterator to reverse end.             |
| cbegin    | Returns const_iterator to beginning.                 |
| cend      | Returns const_iterator to end.                       |
| crbegin   | Returns const_reverse_iterator to reverse beginning. |
| crend     | Returns const_reverse_iterator to reverse end.       |

### Capacity

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| size      | Returns size.                 |
| max_size  | Returns maximum size.         |

### Element Access:

| Operators  | Meaning         |
| ---------- | --------------- |
| operator[] | Access element. |
| at         | Access element. |

### Modifiers

| Operators    | Meaning                                  |
| ------------ | ---------------------------------------- |
| insert       | Insert elemnent.                         |
| erase        | Erase elements.                          |
| swap         | Swap content.                            |
| clear        | Clear content.                           |
| emplace      | Constructs and insert element.           |
| emplace_hint | Constructs and insert element with hint. |

### Observers

| Operators   | Meaning                    |
| ----------- | -------------------------- |
| key_comp    | Returns comparison object. |
| value_compt | Returns comparion object.  |

### Operations:

| Operators   | Meaning                                |
| ----------- | -------------------------------------- |
| find        | Gets iterator to elements.             |
| count       | Counts elements with a specific value. |
| lower_bound | Returns iterator to lower bound.       |
| upper_bound | Returns iterator to upper bound.       |
| equal_range | Get range of equal elements.           |

# Unordered Associative Containers

## :heavy_check_mark: 1. `<unordered_set>` - unordered set

### Capacity:

| Operators | Meaning                       |
| --------- | ----------------------------- |
| empty     | Tests whether array is empty. |
| size      | Returns size.                 |
| max_size  | Returns maximum size.         |

### Iterators:

| Operators | Meaning                              |
| --------- | ------------------------------------ |
| begin     | Returns iterator to beginning.       |
| end       | Returns iterator to end.             |
| cbegin    | Returns const_iterator to beginning. |
| cend      | Returns const_iterator to end.       |

### Element Lookup:

| Operators   | Meaning                                     |
| ----------- | ------------------------------------------- |
| find        | Gets iterator to element.                   |
| count       | Counts elements with a specific key.        |
| equal_range | Gets range of elements with a specific key. |

### Modifiers:

| Operators    | Meaning                                  |
| ------------ | ---------------------------------------- |
| emplace      | Constructs and insert element.           |
| emplace_hint | Constructs and insert element with hint. |
| insert       | Inserts elements.                        |
| erase        | Erases elements.                         |
| clear        | Clears content.                          |
| swap         | Swap content.                            |

### Buckets:

| Operators        | Meaning                        |
| ---------------- | ------------------------------ |
| bucket_count     | Returns number of buckets.     |
| max_bucket_count | Returns max number of buckets. |
| bucket_size      | Returns bucket size.           |
| bucket           | Locates element's bucket.      |

### Hash Policy:

| Operators       | Meaning                       |
| --------------- | ----------------------------- |
| load_factor     | Returns load factor.          |
| max_load_factor | Gets or sets max load factor. |
| rehash          | Sets number of buckets.       |
| reserve         | Requests a capacity change.   |

### Observers:

| Operators     | Meaning                         |
| ------------- | ------------------------------- |
| hash_function | Gets hash function.             |
| key_eq        | Gets key equivalence predicate. |
| get_allocator | Gets allocator.                 |

## :heavy_check_mark: 2. `<unordered_multiset>` - unordered multiset

## :heavy_check_mark: 3. `<unordered_map>` - unordered map

## :heavy_check_mark: 4. `<unordered_multimap>` - unordered multimap
