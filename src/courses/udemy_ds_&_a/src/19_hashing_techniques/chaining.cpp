#include <stdio.h>
#include <stdlib.h>

/*Struct for the first node of the linked list*/
struct Node
{
    int data;
    struct Node *next;
}; // A pointer is a node type. Thus the first node will have the data and the pointer to the next node

/* Function insert an element in a sorted linked list */
void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
/* Find and return the node address based on the data */
struct Node *Search(struct Node *p, int data)
{
    while (p)
    {
        if (p->data == data)
        {
            return (p);
        }
        p = p->next;
    }
    printf("\n\nThere is no node in the linked list with data %d", data);
    return NULL;
}

// hash function
int hash(int key)
{
    return key % 10;
}

void InsertHT(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main()
{

    struct Node *HT[10]; // create a hash table size 10
    struct Node *temp;
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    InsertHT(HT, 12);
    InsertHT(HT, 22);
    InsertHT(HT, 42);

    temp = Search(HT[hash(22)], 22); // return 22 if found, error if not

    printf("%d ", temp->data);

    return 0;
}