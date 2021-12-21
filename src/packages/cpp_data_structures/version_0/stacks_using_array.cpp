// Stacks applies LIFO: Last In First Out
// We can implement stacks using linked list or array
// Operation:
// 1. Push = adds a new element to the stack.
// 2. Pop = removes and returns the top-most from the stack
// 3. Top = return the top-most element of a stack
// 4. isEmpty = check whether a stack is empty or there is any eleemnt present in the stack or not
// 5. Error 1: Stack underflows = if we try to pop an element from an empty stack
// 6. Error 2: Stack overflows = if we try to push an fulled stack

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // the stack and can only store 10 elements

// Initialize the array and the position of the pointer in the stack
int S[SIZE + 1];
int top = 0;

/* Function checks if the stack is empty or not */
int is_empty()
{
    if (top == 0)
    {
        return 1;
    }
    return 0;
}

/* Function pushs an element to the stack */
void push(int x)
{
    top = top + 1;
    if (top > SIZE)
    {
        printf("Stackoverflow\n");
    }
    else
    {
        S[top] = x;
    }
}

/* Function that pop an element out of the stack */
int pop()
{
    if (is_empty())
    {
        printf("Stackunderflow\n");
        return -1000; // This mark the underflow
    }
    else
    {
        // Remove the element and return that element
        top = top - 1;
        return S[top + 1];
    }
}

/* Print all elements in the stack */
void print_stack(int S[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", S[i]);
    }
}

int main()
{
    pop();

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    push(110);

    print_stack(S);

    return 0;
}