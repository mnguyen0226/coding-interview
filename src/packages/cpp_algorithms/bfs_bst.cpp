/*Breadth First Search Implementation for BST*/

// BFS can be considered as Level-Order Tree Traversal.
// Create an empty queue
// temp_node = root
// loop while temp_node is not NULL;
// - print temp_node->data
// - enqueue temp_node's children (left the right) to queue
// - dequeue a node from q.

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>

using namespace std;

typedef struct Node
{
    char letter;
    struct Node *left, *right;
} Node;

/**
 * @brief Level-order traversal
 *
 * @param root
 */
void bfs_display(Node *root)
{
    // checks if root node is null
    if (root == NULL)
    {
        return;
    }

    // creates an empty queue
    queue<Node *> q;

    // enqueues root
    q.push(root);

    cout << "Level-order Traversal: ";

    while (!q.empty())
    {
        // dequeue and set the popped Node as temp node
        Node *temp_node = q.front();
        cout << temp_node->letter << " ";
        q.pop();

        if (temp_node->left)
            q.push(temp_node->left);

        if (temp_node->right)
            q.push(temp_node->right);
    }
}

/**
 * @brief Creates a new node with input character
 *
 * @param c
 * @return Node*
 */
Node *new_node(char c)
{
    Node *n = new Node;
    n->letter = c;
    n->left = n->right = NULL;
    return n;
}

/*User Interface*/
int main()
{
    Node *root = new_node('A');
    root->left = new_node('B');
    root->right = new_node('C');
    root->left->left = new_node('D');
    root->left->right = new_node('E');
    root->right->left = new_node('F');
    root->left->right->left = new_node('G');

    bfs_display(root);

    return 0;
}