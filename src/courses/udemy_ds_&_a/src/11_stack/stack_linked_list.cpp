// Stack implementation with Linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

/* Push new element in the Stack */
void Push(int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Stack is full \n");
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

/* Pop element out of the Stack */
int Pop()
{
    struct Node *temp;
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

/* Display all elements in the Stack */
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

/* User Interface */
int main()
{
    Push(10);
    Push(20);
    Push(30);
    Display();

    printf("Pop: %d\n", Pop());

    return 0;
}