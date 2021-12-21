# Notes on Hashing Techniques
- 1. Why Hashing?
    - Hashing is useful for searching. For searching, we already do Linear Search or Binary Search.
        - Linear Search - O(N)
        - Binary Search - O(logN): Requirement - the key have to be sorted
    - We want a search method that is faster than O(logN) ~ O(1)
    - Hashing: Key/Value is stored in the Hash array index. Thus, to find the key/value, you can directly go to the Hashing array and find the key/value instance time O(1)
        - Drawbacks: Hashing Array required a lot of space and wasted. Thus we will apply Hashing.
    - Hash Function take in the key/value and return the index of the Hash Table
    - Mappings:
        - One to One (Function)
        - One to Many
        - Many to One (Function)
        - Many to Many

- 2. Ideal Hashing:
    - Why call a function ideal hashing? because the time of storing, deletion, or inserting is O(1).
    - We can modify the hash function H(x) = x to H(x) = x % 10 to have the H[10]. We can using chaining techniques to solve collision.
    - Resolve collisions 1 - Open Hashing (Chaining)
        - Note that the array of the Hash Table is the array of pointers.
        - Insert 
        - Search: For successful search - 1 + lambda / 2. For unsuccessful search: 1 + lambda. lambda is the loading factor = n_number of element  / size_of_hash_table.
        - Analysis
        - Delete
        - If the key is 5,35,95,145,175,... then H(x) = x % 10 will not provide a uniform distributed hash table. Thus to come up with a good hashing function, you will have to understand the key.
    - Resolve collisions 2 - Close Hashing (Open Addressing)
        - Close hashing means that we will not increase the space of the Hashtable. We can do this by store elements in different address instead of the same address.
        - Linear Probing
        - Quadratic Probing
        - Double Hashing


- 3. Modulus Hash Function
- 4. Drawbacks
- 5. Solutions 