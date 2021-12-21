# Notes on Red Black Trees
- 2_3 Tree
    - 2-3 Trees are search trees.
    - Degree = 3 = can contain 3 children
    - We can called it Multiway search Tree
    - 2-3 Trees are height balance search Tree = B TREE
        - All leaf node have the same level
        - Every node must have half the children = upper(n/2) = upper(3/2) = 2 (max number of key/value stored in the node)

- Red-Black Tree
    - It is a Height Balanced BST, similar to 2 3 4 Tree
    - Every Node is either Red or Black
    - Root of the tree is Black
    - NULL is also Black
    - NUmber of Blacks on Pats from Root to Leaf are the same
    - No 2 consecutive Red, Parent, and Children of Red are Black.
    - New Insered Node is Red
    - Height in logN <= h <= 2logN