/*Implementation of BST with Linked List from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
} Node;

typedef struct BinarySearchTree
{
    Node *root;
} BST;

/**
 * @brief Creates a new node from input int data
 *
 * @param data - input int data
 * @return Node*
 */
Node *new_node(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;

    return n;
}

/**
 * @brief Creates a new BST
 *
 * @return BST*
 */
BST *new_bst()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

/**
 * @brief Finds the far-left node in the tree / the node with smallest data
 *
 * @param bst - input BST
 * @param n - input Node
 * @return Node*
 */
Node *find_min_node(BST *bst, Node *n)
{
    while (n->left != NULL)
    {
        n = n->left;
    }
    return n;
}

/**
 * @brief Inserts new node to BST by first finding whether the BST has that node, else, insert it
 *
 * @param bst
 * @param n
 */
void insert_node(BST *bst, Node *n)
{
    Node *y = NULL;         // used for keep track of parent node
    Node *temp = bst->root; // for traversal
    while (temp != NULL)
    {
        y = temp;
        if (n->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    // set new node parent to y
    n->parent = y;

    if (y == NULL) // newly added node is root
        bst->root = n;
    else if (n->data < y->data)
        y->left = n;
    else
        y->right = n;
}

/**
 * @brief v is either left or right node of u. This function move right/left subtree of u to replace to u
 *
 * @param bst - input BST
 * @param u - any node in BST
 * @param v - left or right node of u
 */
void transplant(BST *bst, Node *u, Node *v)
{
    // note: two way connections, similar to doubly linked list for easy traversal
    if (u->parent == NULL) // u is root
        bst->root = v;
    else if (u == u->parent->left) // u is left child
        u->parent->left = v;
    else // u is right child
        u->parent->right = v;

    if (v != NULL)
        v->parent = u->parent;
}

/**
 * @brief Deletes any node in BST
 *
 * @param bst - input BST
 * @param n - node you want to delete
 */
void delete_node(BST *bst, Node *n)
{
    // case 1: if the left leave node of n is null, we just remove n by transplant NULL leave
    if (n->left == NULL)
    {
        transplant(bst, n, n->right);
        free(n);
    }
    // case 2: if the right leave node of n is null, we just remove n by transplant NULL leave
    else if (n->right == NULL)
    {
        transplant(bst, n, n->left);
        free(n);
    }
    // case 3: if there are sub tree of n
    else
    {
        Node *y = find_min_node(bst, n->right); // find min element in right subtree

        // transplant the right subtree of n to y
        if (y->parent != n)
        {
            transplant(bst, y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        transplant(bst, n, y); // delete n

        // transplant the left subtree of n to y
        y->left = n->left;
        y->left->parent = y;
        free(n);
    }
}

/**
 * @brief Inorder traversal in BST will provide sorted list
 *
 * @param bst - input BST
 * @param n - root node
 */
void in_order_traversal(BST *bst, Node *n)
{
    if (n != NULL)
    {
        in_order_traversal(bst, n->left); // visit left subtree
        printf("%d ", n->data);
        in_order_traversal(bst, n->right); // visit right subtree
    }
}

/*User Interface*/
int main()
{
    BST *bst = new_bst();
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

    insert_node(bst, a);
    insert_node(bst, b);
    insert_node(bst, c);
    insert_node(bst, d);
    insert_node(bst, e);
    insert_node(bst, f);
    insert_node(bst, g);
    insert_node(bst, h);
    insert_node(bst, i);
    insert_node(bst, j);
    insert_node(bst, k);
    insert_node(bst, l);
    insert_node(bst, m);

    in_order_traversal(bst, bst->root);
    printf("\n");

    delete_node(bst, a);
    delete_node(bst, m);

    in_order_traversal(bst, bst->root);

    return 0;
}