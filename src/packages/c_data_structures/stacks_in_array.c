/*Implementation of Stacks with Array from scratch in C*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// global variable
int S[SIZE + 1];
int top = 0;

/**
 * @brief Checks if the stack is empty by checking top
 *
 * @return int - 1 for empty, 0 for not empty
 */
int is_empty()
{
    if (top == 0)
        return 1;
    return 0;
}

/**
 * @brief Pushs the new int data into stack
 *
 * @param x
 */
void push(int x)
{
    top = top + 1; // increment / move top up
    if (top > SIZE)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        S[top] = x;
    }
}

/**
 * @brief Pops the top data from the stack
 *
 * @return int
 */
int pop()
{
    if (is_empty())
    {
        printf("Stack Underflow\n");
        return -100000; // indicator for stack underflow when print
    }
    else
    {
        top = top - 1;
        return S[top + 1];
    }
}

/*User Interface*/
int main()
{
    pop(); // tests stack underflow
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
    push(110); // tests stack overflow

    // prints of all elements in the stack
    for (int i = 0; i < SIZE; i++)
    {
        // note that we keep S[0] == 0 for indicator that stack underflow
        printf("%d\n", S[i + 1]);
    }

    return 0;
}