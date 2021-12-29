/*Implementation of Binary Tree with Linked List from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    Node *right;
    Node *left;
    Node *parent;
} Node;

typedef struct BinaryTree
{
    Node *root;
} BinaryTree;

/**
 * @brief Creates a new tree node from input char c
 *
 * @param c input character
 * @return Node*
 */
Node *new_node(char c)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->c = c;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;

    return n;
}

/**
 * @brief Creates a new binary tree from input Node
 *
 * @param n
 * @return BinaryTree*
 */
BinaryTree *new_tree(Node *n)
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->root = n;
    return tree;
}

/**
 * @brief Pre-order traversal recursively
 *
 * @param n - root node
 */
void pre_order_traversal(Node *n)
{
    if (n != NULL)
    {
        printf(" %c ", n->c);
        pre_order_traversal(n->left);
        pre_order_traversal(n->right);
    }
}

/**
 * @brief Post-order traversal recursively
 *
 * @param n - root node
 */
void post_order_traversal(Node *n)
{
    if (n != NULL)
    {
        post_order_traversal(n->left);
        post_order_traversal(n->right);
        printf(" %c ", n->c);
    }
}

/**
 * @brief in-order traversal recursively
 *
 * @param n - root node
 */
void in_order_traversal(Node *n)
{
    if (n != NULL)
    {
        in_order_traversal(n->left);
        printf(" %c ", n->c);
        in_order_traversal(n->right);
    }
}

/* Says, we got this array

         D
        / \
       /   \
      /     \
     A       F
    / \     / \
   /   \   /   \
  E     B R     T
 / \     /     / \
G   Q   V     J   L
*/

/*User Interface*/
int main()
{
    Node *d, *a, *f, *e, *b, *r, *t, *g, *q, *v, *j, *l;
    d = new_node('D');
    a = new_node('A');
    f = new_node('F');
    e = new_node('E');
    b = new_node('B');
    r = new_node('R');
    t = new_node('T');
    g = new_node('G');
    q = new_node('q');
    v = new_node('v');
    j = new_node('J');
    l = new_node('L');

    BinaryTree *bt = new_tree(d);

    bt->root->right = f;
    bt->root->left = a;

    f->right = t;
    f->left = r;

    a->right = b;
    a->left = e;

    e->right = q;
    e->left = g;

    r->left = v;

    t->right = j;
    t->left = l;

    printf("\nPre-order traversal: \n");
    pre_order_traversal(bt->root);

    printf("\nPost-order traversal: \n");
    post_order_traversal(bt->root);

    printf("\nIn-order traversal: \n");
    in_order_traversal(bt->root);

    return 0;
}