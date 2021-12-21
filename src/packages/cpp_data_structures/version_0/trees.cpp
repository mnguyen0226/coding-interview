// Tree Data Structures - a non linear data structures
// This is just an introduction to tree

#include <stdio.h>
#include <stdlib.h>

/* Define a node of a tree storing a data, with pointers right, left, and parents */
typedef struct tree_node{
    int data;
    struct tree_node *right;
    struct tree_node *left;
    struct tree_node *parent; // the node previous of the current node
} tree_node;

/* Function creates a tree node */
tree_node* new_tree_node(int data){
    tree_node* n = (tree_node*)malloc(sizeof(tree_node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;

    return n;
}

int main(){
    printf("Basic implementation for tree \n");

    return 0;
}