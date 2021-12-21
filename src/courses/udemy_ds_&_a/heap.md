# Notes for Heap
- What is a Heap? A complete binary tree with the height always logN
- Insert in a Heap
- Delete from a Heap. For max heap, we can only delete the root/largest number/highest priority element
- Heap Sort:
    - Create a Heap of n element: nlogn
    - Delete n element: nlogn
    - Total O(nlogn)
- Heapify Procedures = create a heap out of array from bottom to top. This is the fastest method to create a heap from an arbitrary array
- Priority Queues = The larger the element value, the higher the priority