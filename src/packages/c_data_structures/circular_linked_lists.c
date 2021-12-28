/*Implementation of Circular Linked Lists from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct CircularLinkedList
{
    Node *last; // similar to *next in Singly or Doubly Linked List
} CircularLinkedList;

/**
 * @brief Creates a new node from input data
 *
 * @param data - input int data
 * @return Node* - a new node stored int data
 */
Node *new_node(int data)
{
    Node *z = (Node *)malloc(sizeof(Node));
    z->data = data;
    z->next = NULL;
    return z;
}

/**
 * @brief Creates a new circular linked list from the input int data
 *
 * @param data - input int data
 * @return CircularLinkedList* - a new circular linked list with the head/last node stored the input int data.
 */
CircularLinkedList *new_list(int data)
{
    Node *z = new_node(data);
    z->next = z;

    CircularLinkedList *c = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    c->last = z;
    return c;
}

/**
 * @brief Inserts a new node after a node in linked list
 *
 * @param n - a node to be added in linked list
 * @param a - a node in linked list
 */
void insert_after(Node *n, Node *a)
{
    n->next = a->next;
    a->next = n;
}

/**
 * @brief Inserts a node at last/beginning position in the circular linked list.
 *
 * @param c - circular linked list
 * @param n - the node to be added
 */
void insert_at_last(CircularLinkedList *c, Node *n)
{
    n->next = c->last->next;
    c->last->next = n;
    c->last = n;
}

/**
 * @brief Deletes a node in a Circular Linked List
 *
 * @param c - circular linked list
 * @param n - node to be deleted
 */
void delete_node(CircularLinkedList *c, Node *n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = c->last;
    while (temp->next != n) // traverse till finding the node
    {
        temp = temp->next;
    }

    if (n == c->last)
    { // case 1: delete the last node
        {
            if (n->next == n)
            { // case 1.a: if there is one node in the linked list
                c->last = NULL;
            }
            else
            { // case 1.b: there are more than one node and last node
                temp->next = n->next;
                c->last = temp;
            }
        }
    }
    else
    { // not last node
        temp->next = n->next;
    }
    free(n);
}

/**
 * @brief Traverses through the input linked list and print out all values stored in nodes
 *
 * @param c - input linked list
 */
void traversal(CircularLinkedList *c)
{
    Node *temp = (Node *)malloc(sizeof(Node *));
    temp = c->last;
    printf("%d ", temp->data);
    temp = temp->next;

    while (temp != c->last)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // creates a new linked list with nodes
    CircularLinkedList *l = new_list(10);
    Node *a, *b, *c;
    a = new_node(20);
    b = new_node(30);
    c = new_node(40);

    // linkes all nodes with linked list
    l->last->next = a;
    a->next = b;
    b->next = c;
    c->next = l->last;

    // prints out linked list
    traversal(l);

    // creates a new node
    Node *z;

    // tests insert
    z = new_node(50);
    insert_after(z, c);
    z = new_node(25);
    insert_after(z, a);
    z = new_node(100);
    insert_at_last(l, z);

    // prints out linked list
    traversal(l);

    // tests delete
    delete_node(l, l->last);
    delete_node(l, b);

    // prints out linked list
    traversal(l);

    return 0;
}
