/*Implementation of Binary Tree with Array from scratch in C*/
#include <stdio.h>

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
int max_complete_node = 15;

// the order in the array is level-order traversal
char binary_tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', 'V', 'J', 'L'};

/**
 * @brief Get the right child object
 *
 * @param index - node level index
 * @return int - the right child values
 */
int get_right_child(int index)
{
    if (binary_tree[index] != '\0' && ((2 * index) + 1) <= max_complete_node)
    {
        return (2 * index) + 1;
    }
    return -1;
}

/**
 * @brief Get the left child object
 *
 * @param index - node level index
 * @return int - the left child values
 */
int get_left_child(int index)
{
    if (binary_tree[index] != '\0' && (2 * index) <= max_complete_node)
    {
        return 2 * index;
    }
    return -1;
}

/**
 * @brief Get the parent object
 *
 * @param index - node level index
 * @return int - the parents values
 */
int get_parent(int index)
{
    if (binary_tree[index] != '\0' && index / 2 != '\0')
        return index / 2;
    else
        return -1;
}

/**
 * @brief Pre-order traversal recursively
 *
 * @param index - root index
 */
void pre_order_traversal(int index)
{
    if (index > 0 && binary_tree[index] != '\0')
    {
        printf(" %c ", binary_tree[index]);          // visit root
        pre_order_traversal(get_left_child(index));  // visit left subtree
        pre_order_traversal(get_right_child(index)); // visit right subtree
    }
}

/**
 * @brief Post-order traversal recursively
 *
 * @param index - root index
 */
void post_order_traversal(int index)
{
    if (index > 0 && binary_tree[index] != '\0')
    {
        post_order_traversal(get_left_child(index));  // visit left subtree
        post_order_traversal(get_right_child(index)); // visit right subtree
        printf(" %c ", binary_tree[index]);           // visit root
    }
}

/**
 * @brief In-order traversal recursively
 *
 * @param index root index
 */
void in_order_traversal(int index)
{
    if (index > 0 && binary_tree[index] != '\0')
    {
        post_order_traversal(get_left_child(index));  // visit left subtree
        printf(" %c ", binary_tree[index]);           // visit root
        post_order_traversal(get_right_child(index)); // visit right subtree
    }
}

/*User Interface*/
int main()
{
    printf("\nPre-order traversal: \n");
    pre_order_traversal(1);
    printf("\nPost-order traversal: \n");
    post_order_traversal(1);
    printf("\nIn-order traversal: \n");
    in_order_traversal(1);

    return 0;
}