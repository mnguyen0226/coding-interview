// Implementation of stacks using linked list
// Operation:
// 1. Push = adds a new element to the stack.
// 2. Pop = removes and returns the top-most from the stack
// 3. Top = return the top-most element of a stack
// 4. isEmpty = check whether a stack is empty or there is any eleemnt present in the stack or not
// 5. Error 1: Stack underflows = if we try to pop an element from an empty stack
// 6. Error 2: Stack overflows = if we try to push an fulled stack

#include <stdio.h>
#include <stdlib.h>

/* Initialize a node */
typedef struct node
{ 
    int data;
    struct node *next;
} node;

/* Initialize a linked list */
typedef struct linked_list
{
    struct node *head;
    struct node *top;
} stack;

/* Function creates a new node dynamically */
node *create_node(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

/* Function creates a new linked list dynamically
 * Unlike regular linked list, the stack can be create as empty without any initial node storing data */
stack *create_stack()
{
    stack *S = (stack *)malloc(sizeof(stack));
    S->head = NULL;
    S->top = NULL;
    return S;
}

/* Function checks if the stack is empty or not. Using top to keep track of this */
int is_empty(stack *S)
{
    if (S->top == NULL)
    {
        return 1;
    }
    return 0;
}

/* Function traverses the stack and print out all elements. Using head to keep track of this */
void traverse(stack *S)
{
    node *temp = S->head;
    while (temp != NULL)
    {
        printf("Data: %d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Function that push a new node to the end of the stack */
void push(stack *S, node *n)
{
    // if the stack is empty, then set the head and the top to that node
    if (S->top == NULL)
    {
        S->head = n;
        S->top = n;
    }
    // else, set connection of top node to that node, and set top node to that node
    else
    {
        S->top->next = n;
        S->top = n;
    }
}

/* Function that pop a new node to the end of the stack
 * return a data of the top node */
int pop(stack *S)
{
    // If the stack is empty
    if (is_empty(S))
    {
        printf("Stackunderflow\n");
        return -1000;
    }
    // If the stack is not empty
    else
    {
        int x = S->top->data;
        // If the only node in the stack
        if (S->top == S->head)
        {
            S->top = NULL;
            S->head = NULL;
        }
        // If the stack has more than 1 node, we move the node previous to the top node and make the next of it point to null and also point to the top to it
        else
        {
            node *temp = S->head;
            // Traverse till find the Top Node
            while (temp->next != S->top)
            {
                temp = temp->next;
            }
            temp->next = NULL; // right now temp->next is S->head, so set to null
            S->top = temp;
        }
        return x;
    }
}

int main()
{
    printf("Stacks Implementation with Linked List");
    stack *S = create_stack();

    node *a, *b, *c;
    a = create_node(10);
    b = create_node(20);
    c = create_node(30);

    pop(S);
    push(S, a);
    push(S, b);
    push(S, c);

    traverse(S);
    pop(S);
    traverse(S);
    return 0;
}