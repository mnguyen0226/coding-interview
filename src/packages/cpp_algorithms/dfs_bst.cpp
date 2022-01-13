/*Implementation of depth first search*/

// There are three type of dfs:
// - Pre-order traversal
// - In-order traversal
// - Post-order traversal

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    char c;
    struct Node *left, *right;
};

/**
 * @brief Creates a new node
 *
 * @param data
 * @return Node*
 */
Node *new_node(char c)
{
    Node *n = new Node;
    n->c = c;
    n->right = NULL;
    n->left = NULL;

    return n;
}

/**
 * @brief Pre-order traversal
 * 
 * @param root 
 */
void pre_order_traversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->c << " ";
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

/**
 * @brief In-order traversal
 * 
 * @param root 
 */
void in_order_traversal(Node *root)
{
    if (root != NULL)
    {
        in_order_traversal(root->left);
        cout << root->c << " ";
        in_order_traversal(root->right);
    }
}

/**
 * @brief Post-order traversal
 * 
 * @param root 
 */
void post_order_traversal(Node *root)
{
    if (root != NULL)
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->c << " ";
    }
}

/*User Interface*/
int main()
{
    Node *a, *b, *c, *d, *e, *f, *g;
    a = new_node('A');
    b = new_node('B');
    c = new_node('C');
    d = new_node('D');
    e = new_node('E');
    f = new_node('F');
    g = new_node('G');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    e->left = g;

    cout << "Pre-order traversal: ";
    pre_order_traversal(a);
    cout << endl;
    cout << "In-order traversal: ";
    in_order_traversal(a);
    cout << endl;
    cout << "Post-order traversal: ";
    post_order_traversal(a);
    cout << endl;

    Node *root = new_node('A');
    root->left = new_node('B');
    root->right = new_node('C');
    root->left->left = new_node('D');
    root->left->right = new_node('E');
    root->right->left = new_node('F');
    root->left->right->left = new_node('G');

    cout << "Pre-order traversal: ";
    pre_order_traversal(root);
    cout << endl;
    cout << "In-order traversal: ";
    in_order_traversal(root);
    cout << endl;
    cout << "Post-order traversal: ";
    post_order_traversal(root);

    return 0;
}