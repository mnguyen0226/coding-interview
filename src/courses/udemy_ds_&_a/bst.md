# Note on Binary Search Tree
- BST will note have duplicate.
- If we take the Inorder Traversal we will get the sorted order.
- The time search for an element is O(h) = O(logN), with h is the height of the tree. logN <= h <= N.
- The time complexity for buiding a bst from a set of keys (values):
    - insert: N time
    - search: logN (aka based on height)
    - Thus: O(NlogN)

- When delete a node in BST, either the inorder successor or inorder predecessor will take place