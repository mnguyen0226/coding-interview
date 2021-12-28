/*Implementation of Doubly Linked Lists from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    struct Node *head;
} DoublyLinkedList;

/**
 * @brief Creates a new node with input data
 *
 * @param data - input int data
 * @return Node* - new node stored int data
 */
Node *new_node(int data)
{
    Node *z = (Node *)malloc(sizeof(Node));
    z->data = data;
    z->next = NULL;
    z->prev = NULL;
    return z;
}

/**
 * @brief Creates a new linked list with input data
 *
 * @param data - input int data
 * @return DoublyLinkedList* - new linked list stored int data in the head Node
 */
DoublyLinkedList *new_list(int data)
{
    Node *z = new_node(data);
    DoublyLinkedList *l = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    l->head = z;
    return l;
}

/**
 * @brief Traverses through the input linked list and print out all values stored in nodes
 *
 * @param l - input linked list
 */
void traversal(DoublyLinkedList *l)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = l->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Inserts a new node at the front of linked list
 *
 * @param l - input linked list
 * @param n - input node
 */
void insert_at_front(DoublyLinkedList *l, Node *n)
{
    n->next = l->head;
    l->head->prev = n;
    l->head = n;
}

/**
 * @brief Inserts a new node at the end of linked list
 *
 * @param l - input linked list
 * @param n - input node
 */
void insert_at_tail(DoublyLinkedList *l, Node *n)
{
    Node *temp = (struct Node *)malloc(sizeof(Node)); // temp node for traversal to the end
    temp = l->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

/**
 * @brief Inserts a new node after a node in linked list
 *
 * @param n - a new node to be added
 * @param a - a node in linked list
 */
void insert_node_after(Node *n, Node *a)
{
    n->next = a->next;
    a->next->prev = n;
    a->next = n;
    n->prev = a;
}

/**
 * @brief Deletes a node from linked list.
 *
 * @param l - input linked list
 * @param n - any node to be deleted in linked list
 */
void delete_node(DoublyLinkedList *l, Node *n)
{
    if (n->prev != NULL)
    { // if ther is a node previous to the one we want to delete
        n->prev->next = n->next;
    }
    else
    { // if there is no node previous, aka head node to be deleted
        l->head = n->next;
    }
    if (n->next != NULL)
    {
        n->next->prev = n->prev;
    }
    free(n);
}

/*User Interface*/
int main()
{
    // create a new linked list with nodes
    DoublyLinkedList *l = new_list(10);
    Node *a, *b, *c;
    a = new_node(20);
    b = new_node(50);
    c = new_node(60);

    // links all nodes with linked list
    l->head->next = a;
    
    a->next = b;
    a->prev = l->head;

    b->next = c;
    b->prev = a;

    c->prev = b;
    c->next = NULL;

    return 0;
}
