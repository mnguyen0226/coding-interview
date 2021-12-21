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

/* Function checks if the linked list is a circular linked list or not*/
int isLoop(struct Node *f)
{
    struct Node *p, *q; // create two empty pointer
    p = q = f;          // let both of them point to the first node

    do
    {                           // q will always 2 steps in front of p
        p = p->next;            // traverse p to the next node
        q = q->next;            // traverse q to the next node
        q = q ? q->next : q;    // if q != null then q move to the next node, else stay at q
    } while (p && q && p != q); // keep doing when both node not NULL and they are not pointing to the same address
    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* User Interface */
int main()
{
    struct Node *t1, *t2;

    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5); // create a linked list via array

    // create a circular linked list
    t1 = first->next->next;             // let t1 points to the third node
    t2 = first->next->next->next->next; // point to 5th node
    t2->next = t1;

    printf("Is the linked list a circular linked list? %d\n", isLoop(first));

    return 0;
}