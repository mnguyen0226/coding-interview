# Containers Operators

[Source](https://www.cplusplus.com/reference/stl/).

### :heavy_check_mark: `<array>`

### :heavy_check_mark: `<deque>`

### :heavy_check_mark: `<forward_list>`

### :heavy_check_mark: `<list>`

### :heavy_check_mark: `<map>`

### :heavy_check_mark: `<queue>`

### :heavy_check_mark: `<set>`

### :heavy_check_mark: `<stack>`

### :heavy_check_mark: `<unordered_map>`

### :heavy_check_mark: `<unordered_set>`

### :heavy_check_mark: `<vector>`

- Iterators:

```c++
    begin(); // Returns an iterator pointing to  the first element in the vector.
    end(); // Returns an iterator pointing to the theoretical element that follows the last element in the vector.
    rbegin() // Returns a reverse iterator pointing to the last element in the vector (reverse beginning).
    rend(); // Returns a reverse iterator pointing to the last element preceding the first elelemt in the vector (considered as reverse end).
    cbegin(); // Returns a constant iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
    cend(); // Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
    crbegin(); // Return the constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
    crend(); // Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reversed end).

```

- Illustration: C++
