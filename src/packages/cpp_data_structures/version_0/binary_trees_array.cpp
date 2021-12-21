// Binary tree is a tree in which every node has at most two children.
// Full Binary Tree = every node has 2 children except the leaves.
// Complete Tree = binary tree which is completely filled with a possible exception at the bottom level. The last level many not be completely filled and the bottom level is filled from left to right

// HERE IS THE ARRAY REPRESENTATIVE OF THE BINARY TREE

#include <stdio.h>
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

// Number of nodes in the complete binary tree
int tree_max_size = 15;

// Array store the tree
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

/* Get position in the array of the tree[] array with index level for the right child */
int get_right_child(int index){ // index of the array
    // If the current tree index is not null and the index of the tree is within the tree[] array
    if(tree[index] != '\0' && (2*index + 1) <= tree_max_size){
        return 2*index + 1;
    }
    return -1;
}

/* Get position in the array of the tree [] array with index level for the left child */
int get_left_child(int index){ // index of the array
    // If the current tree index is not null and the index of the tree is within the tree[] array
    if(tree[index] != '\0' && 2*index <= tree_max_size){
        return 2*index;
    }
    return -1;
}

/* Get the position in the array of the tree [] with index level for the parent node */
int get_parent_node(int index){ // index of the array
    // If the current tre index is not null and the index of the parent is NULL (null no tree_max_size because we go backward of the tree)
    if(tree[index] != '\0' && index / 2 != '\0'){
        return index / 2;
    }
    return -1;
}

/* Recursive call for pre-order */
void preorder_traversal(int index){
    // Check for valid index and null node
    if(index > 0 && tree[index] != '\0'){
        printf(" %c ", tree[index]); // visit the node
        preorder_traversal(get_left_child(index)); // visit all left branch
        preorder_traversal(get_right_child(index)); // visit all right branch
    }
}

/* Recursive call for in-order */
void inorder_traversal(int index){
    // Check for valid index and null node
    if(index > 0 && tree[index] != '\0'){
        inorder_traversal(get_left_child(index)); // visit all the left branch
        printf(" %c ", tree[index]); // visit the node
        inorder_traversal(get_right_child(index)); // visit all the right branch
    }
}

/* Recursive call for post-order */
void postorder_traversal(int index){
    // Check for valid index and null node
    if(index > 0 && tree[index] != '\0'){
        postorder_traversal(get_left_child(index)); // visit all the left branch
        postorder_traversal(get_right_child(index)); // visit all the right branch
        printf(" %c ", tree[index]); // visit the node
    }
}

int main(){
    printf("The left child of node 2 is: %c\n", tree[get_left_child(3)]); // R
    printf("The right child of node 2 is: %c\n", tree[get_right_child(3)]); // T
    printf("The parent child of node 2 is: %c\n", tree[get_parent_node(3)]); // D

    // Test pre-order traversal
    printf("Pre-order: \n");
    preorder_traversal(1);

    // Test post-order traversal
    printf("\nPost-order: \n");
    postorder_traversal(1);

    // Test in-order traversal
    printf("\nIn-order: \n");
    inorder_traversal(1);
    
    printf("Complete.\n");

    return 0;
}