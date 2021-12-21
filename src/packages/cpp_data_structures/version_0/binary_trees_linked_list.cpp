// Binary tree implementation in linked list

#include <stdio.h>
#include <stdlib.h>

// Create a struct tree node data type named tree_node
typedef struct tree_node{
    char data;
    struct tree_node *right;
    struct tree_node *left;
    struct tree_node *parent;
} tree_node;

// Create a struct binary_tree type name binary_tree
typedef struct binary_tree{
    tree_node *root;
}binary_tree;

// Function creates a binary tree node which return the head node
tree_node* new_tree_node(char data){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;

    return n;
}

// Function creats a tree and return a root of the tree
binary_tree* new_binary_tree(tree_node *n){
    binary_tree *t = (binary_tree*)malloc(sizeof(binary_tree));
    t->root = n;

    return t;
}


// pre-order traversal take in any tree node
void preorder_traversal(tree_node *n){
    if(n != NULL){
        printf(" %c ", n->data);
        preorder_traversal(n->left);
        preorder_traversal(n->right);
    }
}

// post-order traversal take in any tree node
void postorder_traversal(tree_node *n){
    if(n != NULL){
        postorder_traversal(n->left);
        postorder_traversal(n->right);
        printf(" %c ", n->data);
    }
}

// in-order traversal take in any tree node
void inorder_traversal(tree_node *n){
    if(n != NULL){
        inorder_traversal(n->left);
        printf(" %c ", n->data);
        inorder_traversal(n->right);
    }
}

int main(){
/*
         D               1
        / \
       /   \
      /     \
     A       F           2  3
    / \     / \
   /   \   /   \
  E     B R     T        4  5  6  7
 / \     /     / \
G   Q   V     J   L      8  9  10  11  12
*/

// create tree node and add data to the node
tree_node *d, *a, *f, *e, *b, *r, *t1, *g, *q, *v, *j, *l;
d = new_tree_node('D');
a = new_tree_node('A');
f = new_tree_node('F');
e = new_tree_node('E');
b = new_tree_node('B');
r = new_tree_node('R');
t1 = new_tree_node('T');
g = new_tree_node('G');
q = new_tree_node('Q');
v = new_tree_node('V');
j = new_tree_node('J');
l = new_tree_node('L');

// Create a new tree and add the node manually to the tree
binary_tree* bt = new_binary_tree(d); // let d be the head node

bt->root->right = f; // bt->root == d
bt->root->left = a;

a->right = b;
a->left = e;

f->right = t1;
f->left = r;

e->right = q;
e->left = g;

r->left = v;

t1->right = l;
t1->left = j;

printf("The parent of f is: %c\n", t1->right->data); // There is no way to retrieve the parent yet because it's not doubly linked list

// Test Traversal function
printf("\nPreorder:\n");
preorder_traversal(bt->root);
printf("\nPostorder:\n");
postorder_traversal(bt->root);
printf("\nInorder:\n");
inorder_traversal(bt->root);
printf("\n");

return 0;
}

