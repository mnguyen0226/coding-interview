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

void insert_at_tail(DoublyLinkedList *l, Node *n){
    Node* temp = (struct Node *)malloc(sizeof(Node))
}

/*User Interface*/
int main()
{

    return 0;
}
