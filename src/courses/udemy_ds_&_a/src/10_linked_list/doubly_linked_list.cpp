// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

/* Creates a doubly linked list from an array */
void Create(int A[], int n)
{
    struct Node *t, *last; // t for create new node with data, last is for traversal
    int i;

    // creat the first node without any traversal
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;

    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];       // store data
        t->next = last->next; // link the new node
        t->prev = last;       // link the new node
        last->next = t;       // link the old node to new node
        last = t;             // link the old node to new node
    }
}

/* Displays the DLL */
void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* Returns the length of the linked list */
int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

/* Inserts the new node in the DLL */
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
    { // if the index is out of bound
        return;
    }
    if (index == 0)
    { // if the index is first node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
    }
    else
    { // if the index is anything else
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL)
        { // if not the last node in the DLL
            p->next->prev = t;
        }
        p->next = t;
    }
}

/* Delete the node at a give index, p is the copy of first node */
int Delete(struct Node *p, int index)
{
    int x = -1, i;

    if (index < 1 || index > Length(p))
    {
        return -1;
    }
    if (index == 1)
    {
        first = first->next;
        if (first)
        { // if able move first node to next node, aka there are more than 1 node in the DLL
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    { // if we want to delete a certain index
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

/* Traverses */
void Reversal(struct Node *p)
{
    struct Node *temp;

    while (p)
    {
        // Swap prev and next pointers
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p->next == NULL && p) 
        { // if the next pointer is null and the p exist
            p->next = p->prev; // swap
            p->prev = NULL; // set NULL
            first = p; // set header
            break;
        }
    }
}

/* User Interface */
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);
    printf("\nLength is: %d\n", Length(first));
    Display(first);
    Insert(first, 2, 25);
    Display(first);
    Delete(first, 1);
    Display(first);
    Reversal(first);
    Display(first);

    return 0;
}