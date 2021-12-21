# Note on sorting algorithms
- Sorting Techniques:
    - Comparison based sorts: 
        - Bubble Sort O(n^2)
            - Why call BS? We sort it in terms of smaller to larger number. As the sorting algorithm proceed, the smaller number rise up like bubble when you throw large number down the water.
            - Number of comparisons O(n^2)
            - Number of swaps O(n^2)
        - Insertion Sort O(n^2) - This is better for linked list because you don't have to shift the element
            - Meaning insert the value in the sorted element.
            - Min search time O(1)
            - Max search time O(n0)
        - Selection Sort O(n^2)
            - Why call SS? You select a position for sorting purposes.
        -------------------------------------------------------

        - Heap Sort O(nlogn)
        - Merge Sort O(nlogn): 
            - Merging = Merge the two sorted lists.
            - Idea: you have two sorted array, you can iterate through the arrays, compare the element of each array to other array, then put the element in the new (larger) array.
            - In the unsorted list, say there are 8 elements, we can change the statement to "merge sort 8 arrays with each array contain only 1 element."
            - This sort need extra space.
        - Quick Sort O(nlogn)
            - Frequently used.
            - Other names: selection exchange sort, partition exchange sort.
            - Why call Quicksort? An element is considered sorted if all the elements on its rightside is less than its value, and all of the elements on its leftside is larger than its value. This does not mean that it's the fastest sort but just each element "know" its own position.
            - Best case - if the partition is in middle: O(nlogn)
            - Worst case - if the partition is either the left or right end of the array O(n^2)
            - Average case: O(nlogn)
        - Tree Sort O(nlogn)
        -------------------------------------------------------

        - Shell Sort O(n^(3/2)) / O(nlogn) / O(n^5/3)
            - This sorting algorithm uses insertion sort.
            - The idea is that if you shuffle the elements, they might get sorted quickly.
            - Shell Sort does not take any extra space.
        -------------------------------------------------------

    - Index based sorts - faster but consume a lot of space:
        - Count Sort O(n)
            - This is index-based sorting algorithm.
            - Fast, easy to understand but consume a lot of memory. 
            - This algorithm is very good for small range number.
        - Bucket/Bin Sort O(n)
            - Similar to count sort.
            - The size of the Bin[] is equal to the value of the largest number + 1, all element is initialized to NULL.
            - We can think of this Bin[] as the array of linked list
        - Radix Sort O(n)
            - This sorting algorithm is similar to Bin Sort but has 10 bin since you can check the last digit of a number and put in the bin. (Fill the bin)
            - You then apply FIFO and have all the number layout in a new order (Empty the bin)
            - Next you drop the just-sorted array element to the bin again based on the second-digit of that number.
            - Then repeat the fill and empty bin until the array is sorted.

- Criteria of Analysis:
    - Number of comparisons.
    - Number of swaps.
    - Adaptive.
    - Stable.
    - Extra Memory.

