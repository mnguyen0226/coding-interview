## Note on array Abstract Data Type (ADT) and time complexity
- Data:
    - 1. Array Space.
    - 2. Size.
    - 3. Length (or number of elements)

- Operations:
    - 1. Display()
    - 2. Add(x) / Append(x)
        - Insert at the end: O(1) - best case
    - 3. Insert(index, x)
        - Insert at the end: O(1) - best case
        - Insert in the middle: O(n)
        - Insert in the front: O(n) - worst case
    - 4. Delete(index)
        - Delete at the end: O(1) - best case
        - Delete in the middle: O(n)
        - Delete in the front: O(n) - worst case    
    - 5. Search(x): the elements have to be unique
        - Linear Search
            - Found element in the front of the array: O(1) - best case
            - Found element in the end of the array: O(n) - worst case
            - Found element in the middle: O(n) - average case
        - Binary Search:
            - Found the element in the middle: O(1) - best case
            - Found the element else where: O(logn) - log-base-2 - worst case
    - 6. Get(index) - O(1)
    - 7. Set(index, x) - O(1)
    - 8. Max()/ Min() - for unsorted list - O(n)
    - 9. Sum() - O(n) 
    - 9. Reverse() - O(n)
    - 10. Shift()/Rotate()
    - 11. Check if array is sorted
    - 12. Merge: Append, Concat, Compare, Copy
    - 13. Set Operations: Union, Intersection, Difference, Set Membership

- Leet Code:
    - One: Find single and multiple missing element in an sorted and unsorted array
    - Two: Find a pair of elements with sum K in a unique array
 