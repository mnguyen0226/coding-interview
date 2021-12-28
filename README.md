# Coding Interview Practice for SWE & MLE

This repository is for my personal usages & preparation for SWE and MLE interviews.

## 1. Study Guide

- What are the most relevant problems?
- Understand the goal of practicing coding interview
- Start with easy problems
- Simulate the real world coding interview
- Strategy when you get stuck
  - Clarify the input/output the problem.
  - Read Solution.
  - Try to code the problem on paper from scratch => Find what you don't understand about the problem.
  - Document the problem on Excel.

## 2. Data Structures & Algorithms

## Data Structures in C & C++

### :heavy_check_mark:[C++ Practice](https://github.com/mnguyen0226/coding-interview-swe-ml/tree/main/src/practices/cpp)

### :heavy_check_mark:[C Practice](https://github.com/mnguyen0226/coding-interview-swe-ml/tree/main/src/practices/c)

### :heavy_check_mark:[Big-O](https://www.bigocheatsheet.com/)

### :heavy_check_mark:Array

- :runner::clock1230: Time Complexity - Worst Case:
  - Access: O(1)
  - Search: O(n)
  - Insert: O(n)
  - Remove: O(n)

### :heavy_check_mark:Linked Lists

- About: A linked list is a linear collection of data elements, called nodes, each pointing to the next node by means of a pointer. It is a data structure consisting of a group of nodes which together represent a sequence. Generally, we call the first node of a linked list the "head" of the linked list, and we always keep the access of the head of the linked list so that we have access to all the nodes of a linked list. This is also called "Singly Linked List" in which each node points to the next node and the last node points to null.
- Implementation: C, C++
- Operations:

  ```c++
  // inserts a node at the begin
  void insert_at_beginning(LinkedList *l, Node *n);

  // inserts a node at the end
  void insert_at_last(LinkedList *l, Node *n);

  // inserts a node after any node
  void insert_node_after(Node *n, Node *a);

  // deletes a node
  void delete_node(LinkedList *l, Node *n);
  ```

- :runner::clock1230: Time Complexity - Worst Case:
  - Access: `O(n)`
  - Search: `O(n)`
  - Insert: `O(1)`
  - Remove: `O(1)`

### :heavy_check_mark:Doubly Linked List

- About: A linked list in which each node has two pointers, p and n, such that p points to the previous node and n points to the next node; the last node's n pointer points to null. Compared to Singly Linked List, Doubly Linked List requires extra space because it stores one extra pointer for each node. However, Doubly Linked List is comparatively more efficient than singly linked list because we can iterate in both direction.
- Implementation: C, C++
- Operations:

  ```c++
  // inserts a node at the front/head
  void insert_at_front(DoublyLinkedList *l, Node *n);

  // inserts a node at the tail/end
  void insert_at_tail(DoublyLinkedList *l, Node *n);

  // inserts a node after any node
  void insert_node_after(Node *n, Node *a);

  // deletes a node
  void delete_node(DoublyLinkedList *l, Node *n);
  ```

- :runner::clock1230: Time Complexity - Worst Case:
  - Access: `O(n)`
  - Search: `O(n)`
  - Insert: `O(1)`
  - Remove: `O(1)`

### :heavy_check_mark:Circular Linked List

- About: A linked list in which each node points to the next node and the last node points back to the first node.
- Implementation: C, C++
- Operations:

  ```c++
  // inserts a node after a node
  void insert_after(Node *n, Node *a);

  // inserts a node at the last/head
  void insert_at_last(CircularLinkedList *c, Node *n);

  // delete a node
  void delete_node(CircularLinkedList *c, Node *n);
  ```

- :runner::clock1230: Time Complexity - Worst Case:
  - Access: `O(n)`
  - Search: `O(n)`
  - Insert: `O(1)`
  - Remove: `O(1)`

### :heavy_check_mark:Stacks

- About:
  - A Stack is a collection of elements, with two principle operations: _push_, which adds to the collection, and _pop_, which removes the most recently added element.
  - **Last In, First Out (LIFO)** data structure: the most recently added object is the first to be removed.
  - Stack is a Abstract Data Type (ADT) because it works on LIFO policy which provides operations like push, pop,... for users to interact with the data. We can implement Stacks in both array or linked list.
- Implementation:
  - With array in C, C++
  - With linked list in C, C++
- Operations:

  ```c++
  // adds a new element to the stack's top
  void push(Stack *s, Node *n);

  // removes and returns the top-most from the stack
  int pop(Stack *s);

  // return the top-most but not removes from the stack
  int get_top(Stack *s);

  // check whether any elements in the stack or not
  int is_empty(Stack *s)
  ```

- :runner::clock1230: Time Complexity - Worst Case:
  - Access: `O(n)`
  - Search: `O(n)`
  - Insert: `O(1)`
  - Remove: `O(1)`

### :heavy_check_mark:Queues

- About:
  - A Queue is a collection of element, with two principle operations: _enqueue_, which inserts an element into the queue, and _dequeue_, which removes an element from the queue.
  - **First In, First Out (FIFO)** data structure: the oldest added object is the first to be removed.
  - Similar to Stack, Queue is also an ADT.
- Implementation:
  - With array in C, C++
  - With linked list in C, C++
- Operations:

  ```c++
  // adds an item to the tail of queue
  void enqueue(Queue *q, Node *n);

  // returns and deletes the front element front queue
  int dequeue(Queue *q);

  // checks whether the queue has any element or not
  int is_empty(Queue *q);

  // returns but not deletes the front element of the queue
  int front(Queue *q);
  ```

- :runner::clock1230: Time Complexity - Worst Case:
  - Access: `O(n)`
  - Search: `O(n)`
  - Insert: `O(1)`
  - Remove: `O(1)`

### :heavy_check_mark:Trees

- About:
  - Tree is a non-linear data structure. Tree stores data in a hierarchical order.
- Terminologies:<br>
  ![alt-text](https://github.com/mnguyen0226/coding-interview-swe-ml/blob/main/docs/imgs/resize_tree_structure.png)

  - _Root:_ The topmost node of the hierarchy is called the root of the tree.
  - _Child:_ Nodes next in the hierachy are the children of the previous node.
  - _Parent:_ The node just previous to the current node is the parent of the current node.
  - _Siblings:_ Nodes with the same parent are called siblings.
  - _Ancestors:_ nodes which are higher in the hierarchy are ancestors of the given node.
  - _Descendents:_ Nodes which are lower in the hierarchy are descendants of a given node.
  - _Internal Nodes:_ Nodes with at least one child are internal nodes.
  - _External Nodes/Leaves:_ Nodes which don't have any child are called leaves of tree.
  - _Edge:_ The link bedtween two nodes are called edge.
    ![alt-text](https://github.com/mnguyen0226/coding-interview-swe-ml/blob/main/docs/imgs/tree_level_height.png)
  - _Level:_ The root of a tree is at level 0 and the nodes whose parent is root are at level 1 and so on.
  - _Height:_ The height of a node is the number of nodes (excluding the node) on the longest path from the node to a leaf.
  - _Height of a tree:_ It is the height of its root.
    ![alt-text](https://github.com/mnguyen0226/coding-interview-swe-ml/blob/main/docs/imgs/tree_depth_degree.png)
  - _Depth:_ The depth of a node is the number of nodes (excluding the node) on the path from the root to the node.
  - _Node Degree:_ It is the max number of children a node has.
  - _Tree Degree:_ It is the max number of node degree. 3 for the image above.

- Implementation: C, C++

### :heavy_check_mark:Binary Trees

- About:<br>
  ![alt-text](https://github.com/mnguyen0226/coding-interview-swe-ml/blob/main/docs/imgs/bt_vs_full_bt.png)

  - _A Binary Tree_ is a tree data structure in which each node has at most two children, which are reffered to as the left and right child.
  - _A Full Binary Tree_ is a binary tree in which every ndoe has 2 children excep the leaves.
    ![alt-text](https://github.com/mnguyen0226/coding-interview-swe-ml/blob/main/docs/imgs/complete_bt_vs_perfect_bt.png)
  - _A Complete Binary Tree_ is a binary tree which is completely filled with a possible exception at the bottom level, ie, the last level may not be completely filled and the bottom level is filled from left to right.
  - _A Perfect Binary Tree_ is a binary tree that has each leaf is at the same level and all the interior nodes have two children.

- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:Binary Search Trees

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:Red-Black Tree

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:AVL Trees

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:Splay Trees

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:Heap

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:Priority Queues

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

### :heavy_check_mark:Graphs

- About:
- Implementation:
- :runner::clock1230: Time Complexity - Worst Case:
  - Access:
  - Search:
  - Insert:
  - Remove:

## Algorithms in C & C++

- Algorithms Coursera (TBD)

## 3. CTCI Questions

Tips: Write out question. Take picture of thought process -> README. Solve. Take note on Google Sheet

- Array & Strings
- Linked Lists
- Stacks & Queues
- Trees & Graphs
- Bit Manipulations
- OOP Designs
- Recursion & DP
- Systems Designs & Scalability
- Sorting & Searching

## 4. Machine Learning & Deep Learning

### :heavy_check_mark:Coursera Deep Learning Course [(completed)](https://github.com/mnguyen0226/deep-learning-coursera).

### :question:FastAI ML Course - Pytorch practice:

- Introduction to Random Forest.
- Random Forest Deep Dive.
- Performance, Validation, and Model Interpretation.
- Feature Importance, Tree Interpreter.
- Extrapolation and RF from Scratch/
- Data Products and Live Coding.
- RF from Scratch & Gradient Descent.
- Gradient Descent & Logistic Regression.
- Regularization, Learning Rate, and NLP
- More NLP & Columnar Data.
- Embeddings
- Complete Rossmann, Ethical Issues

### :question:Fast AI DL Course - Pytorch practice:

- Recognizaing Cats & Dogs.
- Improving your image classifier.
- Understanding convolution.
- Structured, time series, and language models.
- Collaborative filtering, inside the training loop.
- Interpreting embeddings, RNNs from scratch.
- ResNet from scratch.
- Object detection.
- SSD: Single shot multibox detector.
- NLP classification & transfer learning.
- Neural translation, Multi-modal learning.
- DarkNet, GANs.
- CycleGANs, Data ethics, Style transfer.
- Super resolution; Segmentation with Unets

### :question:Kaggle

### :question:Deep Learning for Coder - Pytorch book (TBD)

### :question:MLOps Coursera (TBD)

### :question:Reinforcement Learning Coursera (TBD)
