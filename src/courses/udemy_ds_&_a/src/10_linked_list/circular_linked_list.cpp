// Circular Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* Structure Node */
struct Node
{
    int data;
    struct Node *next; // pointer next
} * Head;

/* Creates a circular linked list */
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last; // t is the pointer for create new node, last is the pointer for traverse through the circular linked lsit

    // create a circular linked list that has the first node stored the data of the first element in the array
    Head = (struct Node *)malloc(sizeof(struct Node)); // use malloc here because we create a node that store a data
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node)); // create a memory to store data
        t->data = A[i];                                 // insert data to new node
        t->next = last->next;                           // set new node to link to the last's next pointer
        last->next = t;                                 // set last to link with new node
        last = t;                                       // set new node to last
    }
}

/* Displays all node in the CLL */
void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

/* Insert a new node in the CLL */
void Insert(int pos, int x)
{
    Node *t, *p; // t is to create a new node, p is for traversal
    int i;

    // case 1: Insert infront of the head node
    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        if (Head == NULL)
        { // if head node is null then create a new node and have it pointed to itself
            Head = t;
            Head->next = Head;
        }
        else
        {
            p = Head; // traversal pointer start at the front

            while (p->next == Head)
            { // traverse till the end of the linked list
                p = p->next;
            }
            t->next = Head;
            p->next = t;
            Head = t;
        }
    }
    else
    { // case 2: Insert at any position
        p = Head;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new Node; // create a new node to store adata
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

/* Deletes a node at a given position */
int Delete(int pos)
{
    Node *p, *q; // p for traversal, q to hold the node you want to delete for deletion
    int x = -1;

    // case 1: delete the head node
    if (pos == 1)
    {
        p = Head;
        while (p->next != Head)
        {
            p = p->next;
        }
        x = Head->data; // extract the data from the deleted node
        if (p == Head)
        { // case 1a: if we have only 1 node in the linked list
            delete Head;
            Head = NULL; // set NULL else it will point to gabage address
        }
        else
        { // case 1b: if there is more than 1 node in the linked list
            p->next = Head->next;
            delete Head;
            Head = p->next; // note that p is the tail of the linked list
        }
    }
    else
    { // case 2: delete the node at a given position
        p = Head;
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next; // set q as the node after p
        x = q->data;
        delete q;
    }
    return x;
}

/* User Interface */
int main()
{
    int A[] = {2, 3, 4, 5, 6};
    Create(A, 5);
    Display(Head);
    Insert(3, 7); // insert after
    Display(Head);
    Delete(1); // delete the first node
    Display(Head);
    return 0;
}
