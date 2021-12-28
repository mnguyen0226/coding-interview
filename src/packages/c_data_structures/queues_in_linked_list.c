/*Implementation of Queues with Linked List from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
} Queue;

/**
 * @brief Creates a mew queue from input int data
 * 
 * @param data - input data
 * @return Node* 
 */
Node *new_node(int data)
{
    Node *z = (Node *)malloc(sizeof(Node));
    z->data = data;
    z->next = NULL;

    return z;
}
