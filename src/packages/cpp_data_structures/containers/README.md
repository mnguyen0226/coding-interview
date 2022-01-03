# C++ Containers Operators

[Source](https://www.cplusplus.com/reference/stl/).

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

| Operators     | Meaning                                    |
| ------------- | ------------------------------------------ |
| assign        | Access container content.                  |
| push_back     | Add element at the end.                    |
| push_front    | Insert element at beginning.               |
| pop_back      | Delete last element.                       |
| pop_front     | Access first element.                      |
| insert        | Insert elements.                           |
| erase         | Erase elements.                            |
| swap          | Swap elements.                             |
| clear         | Clear elements.                            |
| emplace       | Construct and insert element.              |
| emplace_front | Construct and insert element at beginning. |
| emplace_back  | Construct and insert element at end.       |

## :heavy_check_mark: 4. `<forward_list>` - forward list

## :heavy_check_mark: 5. `<list>` - linked list

# Containers Adaptors

## :heavy_check_mark: 1. `<stack>` - LIFO stack

## :heavy_check_mark: 2. `<queue>` - FIFO queue

## :heavy_check_mark: 3. `<priority_queue>` - heap

# Associative Containers

## :heavy_check_mark: 1. `<set>` - tree

## :heavy_check_mark: 2. `<multiset>` - Multiple-key set

## :heavy_check_mark: 3. `<map>` - associative arrays

## :heavy_check_mark: 4. `<multimap>` - Multiple-key map

# Unordered Associative Containers

## :heavy_check_mark: 1. `<unordered_set>` - unordered set

## :heavy_check_mark: 2. `<unordered_multiset>` - unordered multiset

## :heavy_check_mark: 3. `<unordered_map>` - unordered map

## :heavy_check_mark: 4. `<unordered_multimap>` - unordered multimap
