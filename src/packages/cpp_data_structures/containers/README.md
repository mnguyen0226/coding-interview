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
    rbegin(); // Returns a reverse iterator pointing to the last element in the vector (reverse beginning).
    rend(); // Returns a reverse iterator pointing to the last element preceding the first elelemt in the vector (considered as reverse end).
    cbegin(); // Returns a constant iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
    cend(); // Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
    crbegin(); // Return the constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
    crend(); // Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reversed end).

```

- Capacity:

```c++
    size(); // Returns the number of elements in the vector.
    max_size(); // Returns the max number of elements that the vector can hold.
    capacity(); // Returns the size of the of the storage space currently allocated to the vector expressed as number of elements.
    resize(n); // Resizes the container so that it contains "n" elements.
    empty(); // Returns whether the container is empty.
    shrink_to_fit(); // Reduces the capacity of the container to fit its size and destroys all elements beyong the capacity.
    reverse(); // Requests that the vector capacity be at least enough to contain n elements.

```

- Element Access:

```c++
    reference operator [g] // Returns a reference to the element at position g in the vector.
    at(g); // Returns a reference to the eleemnt at position 'g' in the vector.
    front(); // Return the first element in the vector.
    back(); // Returns a reference to the last element in the vector.
    data(); // Returns a direct pointer to the memory array used internally by the vector to store its own elements.
```

- Modifiers:

```c++
    assign(); // Assigns new value to the vector elemenets to replacing old ones.
    push_back(); // Pushs the elements into a vector from the back.
    pop_back(); // Used to pop or remove elements from a vector from the back.
    insert(); // Inserts new elements before the element at the specified position.
    erase(); // Used to remove elements from a container from the specified position or range.
    swap(); // Used to swap the contents of one vector with another vector of same type.
```
