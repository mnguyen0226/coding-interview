// Linked List Challenge: Find the Middle Element of a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

/* Function take in the array and number of elements to create a linked list */
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first; // last is use as a traversal pointer so first pointer can keep hold of the pointer to the linked list

    for (i = 1; i < n; i++)
    {
        // create a node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t; // set connection
        last = t;       // move the pointer to a newly created node
    }
}

/* Display the entire linked list with just the head node */
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next; // move the pointer to point to the next node
    }
    printf("\n");
} // when the function is complete, p is set to NULL again since p = p->next

int MiddleLinkedList(struct Node *p)
{
    struct Node *q;
    p = q = first;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (q) // after moving q, it it exist then move p, else have p stay still
        {
            p = p->next;
        }
    }
    return p->data;
}

int main()
{
    int A[] = {1, 2, 3, 5, 6, 8, 9, 10};
    Create(A, 8);
    Display(first);
    printf("Middle Node is: %d", MiddleLinkedList(first));

    return 0;
}