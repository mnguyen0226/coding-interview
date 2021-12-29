/*Implementation of Red-Black Tree from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

enum COLOR
{
    Red,
    Black
};

typedef struct Node
{
    int data;
    Node *right;
    Node *left;
    Node *parent;
    enum COLOR color;
} Node;

typedef struct RedBlackTree
{
    Node *root;
    Node *NIL; // leave nodes (black)
} RBTree;

/**
 * @brief Creates a new node from input int data. Newly created node has color Red
 *
 * @param data
 * @return Node*
 */
Node *new_node(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->data = data;
    n->color = Red;
    return n;
}

/**
 * @brief Creates a new red-black tree with root note is Black
 *
 * @return RBTree*
 */
RBTree *new_tree()
{
    RBTree *rbt = (RBTree *)malloc(sizeof(RBTree));
    Node *nil_node = (Node *)malloc(sizeof(Node));
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->parent = NULL;
    nil_node->color = Black;
    nil_node->data = 0;

    rbt->NIL = nil_node; // leave node
    rbt->root = rbt->NIL;

    return rbt;
}

/**
 * @brief Left rotations at a node
 *
 * @param rbt - input RBTree
 * @param n - rotation at node n
 */
void left_rotation(RBTree *rbt, Node *n)
{
    Node *y = n->right;
    n->right = y->left;

    if (y->left != rbt->NIL)
    {
        y->left->parent = n;
    }
    y->parent = n->parent;

    if (n->parent == rbt->NIL)
    { // n is root
        rbt->root = y;
    }
    else if (n == n->parent->left)
    { // n is the left child
        n->parent->left = y;
    }
    else
    { // n is the right child
        n->parent->right = y;
    }
    y->left = n;
    n->parent = y;
}

/**
 * @brief Right rotations at a node
 *
 * @param rbt - input RBTree
 * @param n - rotation at node n
 */
void right_rotation(RBTree *rbt, Node *n)
{
    Node *y = n->left;
    n->left = y->right;

    if (y->right != rbt->NIL)
    {
        y->right->parent = n;
    }
    y->parent = n->parent;

    if (n->parent == rbt->NIL)
    { // n is root
        rbt->root = y;
    }
    else if (n == n->parent->right)
    { // n is the right child
        n->parent->right = y;
    }
    else
    { // n is the left child
        n->parent->left = y;
    }
    y->right = n;
    n->parent = y;
}

/**
 * @brief After rotation, fix the RBTree to maintain the rules
 *
 * @param rbt
 * @param n
 */
void insertion_fixup(RBTree *rbt, Node *n)
{
    while (n->parent->color == Red)
    {
        // n->parent is the left child
        if (n->parent == n->parent->parent->left)
        {
            Node *y = n->parent->parent->right; // set y as uncle of n

            // case 1: if the root node is black and uncle node is red
            if (y->color == Red)
            {
                n->parent->color = Black;
                y->color = Black;
                n->parent->parent->color = Red;
                n = n->parent->parent;
            }

            else
            {
                // case 2: if the root node is black and uncle node is black, the new node is right child
                if (n == n->parent->right)
                {
                    n = n->parent;
                    left_rotation(rbt, n);
                }
                // case 3: if the root node is black and uncle node is black, the new node is left child
                n->parent->color = Black;
                n->parent->parent->color = Red;
                right_rotation(rbt, n->parent->parent);
            }
        }
        // n->parent is the right child
        else
        {
            Node *y = n->parent->parent->left;

            if (y->color == Red)
            {
                n->parent->color = Black;
                y->color = Black;
                n->parent->parent->color = Red;
                n = n->parent->parent;
            }
            else
            {
                if (n == n->parent->left)
                {
                    n = n->parent;
                    right_rotation(rbt, n);
                }
                n->parent->color = Black;
                n->parent->parent->color = Red;
                left_rotation(rbt, n->parent->parent);
            }
        }
    }
    rbt->root->color = Black;
}

void insert_node(RBTree *rbt, Node *n)
{
    Node *y = rbt->NIL; // used for the parent of added node
    Node *temp = rbt->root;

    while (temp != rbt->NIL)
    {
        y = temp;
        if (n->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    n->parent = y;

    if (y == rbt->NIL)
    { // newly added node is root
        rbt->root = n;
    }
    else if (n->data < y->data)
    { // data of child is less than its parent, left child
        y->left = n;
    }
    else
    {
        y->right = n;
    }
    n->right = rbt->NIL;
    n->left = rbt->NIL;

    // after insertion, fix the rbtree
    insertion_fixup(rbt, n);
}

/**
 * @brief v is either left or right node of u. This function move right/left subtree of u to replace to u
 *
 * @param rbt - input RBTree
 * @param u - any node in RBTree
 * @param v - left or right node of u
 */
void rb_transplant(RBTree *rbt, Node *u, Node *v)
{
    if (u->parent == rbt->NIL)
        rbt->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

/**
 * @brief Finds the node with min values in the tree from node n
 *
 * @param rbt - input RBTree
 * @param n - root node
 * @return Node*
 */
Node *find_min_node(RBTree *rbt, Node *n)
{
    while (n->left != rbt->NIL)
        n = n->left;
    return n;
}

/**
 * @brief After rotation, fix the RBTree to maintain the rules
 *
 * @param rbt
 * @param n
 */
void deletion_fixup(RBTree *rbt, Node *n)
{
    while (n != rbt->root && n->color == Black)
    {
        if (n == n->parent->left)
        {
            Node *w = n->parent->right;
            if (w->color == Red)
            {
                w->color = Black;
                n->parent->color = Red;
                left_rotate(rbt, n->parent);
                w = n->parent->right;
            }
            if (w->left->color == Black && w->right->color == Black)
            {
                w->color = Red;
                n = n->parent;
            }
            else
            {
                if (w->right->color == Black)
                {
                    w->left->color = Black;
                    w->color = Red;
                    right_rotate(rbt, w);
                    w = n->parent->right;
                }
                w->color = n->parent->color;
                n->parent->color = Black;
                w->right->color = Black;
                left_rotate(rbt, n->parent);
                n = rbt->root;
            }
        }
        else
        {
            Node *w = n->parent->left;
            if (w->color == Red)
            {
                w->color = Black;
                n->parent->color = Red;
                right_rotate(rbt, n->parent);
                w = n->parent->left;
            }
            if (w->right->color == Black && w->left->color == Black)
            {
                w->color = Red;
                n = n->parent;
            }
            else
            {
                if (w->left->color == Black)
                {
                    w->right->color = Black;
                    w->color = Red;
                    left_rotate(rbt, w);
                    w = n->parent->left;
                }
                w->color = n->parent->color;
                n->parent->color = Black;
                w->left->color = Black;
                right_rotate(rbt, n->parent);
                n = rbt->root;
            }
        }
    }
    n->color = Black;
}

void delete_node(RBTree *rbt, Node *n)
{
    Node *y = n;
    Node *x;
    enum COLOR y_orignal_color = y->color;
    if (n->left == rbt->NIL)
    {
        x = n->right;
        rb_transplant(rbt, n, n->right);
    }
    else if (n->right == rbt->NIL)
    {
        x = n->left;
        rb_transplant(rbt, n, n->left);
    }
    else
    {
        y = minimum(rbt, n->right);
        y_orignal_color = y->color;
        x = y->right;
        if (y->parent == n)
        {
            x->parent = n;
        }
        else
        {
            rb_transplant(rbt, y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        rb_transplant(rbt, n, y);
        y->left = n->left;
        y->left->parent = y;
        y->color = n->color;
    }
    if (y_orignal_color == Black)
        rb_delete_fixup(rbt, x);
}

/**
 * @brief Prints sorted order
 *
 * @param rbt - input rbtree
 * @param n - root node
 */
void in_order_traversal(RBTree *rbt, Node *n)
{
    if (n != rbt->NIL)
    {
        in_order_traversal(rbt, n->left); // visit left subtree
        printf("%d\n", n->data);
        in_order_traversal(rbt, n->right); // visit right subtree
    }
}

/*User Interface*/
int main()
{
    RBTree *rbt = new_tree();

    Node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
    a = new_node(10);
    b = new_node(20);
    c = new_node(30);
    d = new_node(100);
    e = new_node(90);
    f = new_node(40);
    g = new_node(50);
    h = new_node(60);
    i = new_node(70);
    j = new_node(80);
    k = new_node(150);
    l = new_node(110);
    m = new_node(120);

    insert_node(rbt, a);
    insert_node(rbt, b);
    insert_node(rbt, c);
    insert_node(rbt, d);
    insert_node(rbt, e);
    insert_node(rbt, f);
    insert_node(rbt, g);
    insert_node(rbt, h);
    insert_node(rbt, i);
    insert_node(rbt, j);
    insert_node(rbt, k);
    insert_node(rbt, l);
    insert_node(rbt, m);

    in_order_traversal(rbt, rbt->root);

    delete_node(rbt, a);
    delete_node(rbt, m);

    in_order_traversal(rbt, rbt->root);

    return 0;
}