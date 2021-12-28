/*Simple implementation of Tree from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
} Node;

Node *new_tree_node(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;

    return n;
}

int main()
{
    Node *a, *b, *c;
    a = new_tree_node(20);
    b = new_tree_node(10);
    c = new_tree_node(30);
    a->right = b;
    a->left = c;

    return 0;
}