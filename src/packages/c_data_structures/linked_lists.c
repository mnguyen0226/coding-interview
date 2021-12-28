/*Implementation of Linked Lists from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    struct Node *head;
} LinkedList;

/**
 * @brief Creates a new node from input int data
 *
 * @param data - input int data
 * @return struct Node* - a new node that stored int data
 */
Node *new_node(int data)
{
    struct Node *z = (struct Node *)malloc(sizeof(struct Node));
    z->data = data;
    z->next = NULL;
    return z;
}

/**
 * @brief Creates a new linked list from intput data
 *
 * @param data
 * @return LinkedList* - a new linked list with first node store int data
 */
LinkedList *new_list(int data)
{
    struct Node *a = new_node(data);
    LinkedList *l = (struct LinkedList *)malloc(sizeof(LinkedList));
    l->head = a; // let the linked list pointer points to the first node
    return l;
}

/**
 * @brief Traverses through the input linked list and print out all values stored in nodes
 *
 * @param l - input linked list
 */
void traversal(LinkedList *l)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = l->head; // create a temp node for traversal
    while (temp != NULL)
    { // while there is still a next node
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Inserts a new node at the begin of linked list
 *
 * @param l - input linked list
 * @param n - input node
 */
void insert_at_beginning(LinkedList *l, Node *n)
{
    n->next = l->head;
    l->head = n;
}

/**
 * @brief Inserts a new node at the end of linked list
 *
 * @param l - input linked list
 * @param n - input node
 */
void insert_at_last(LinkedList *l, Node *n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(Node)); // create a temporary node for traversal to the end;
    temp = l->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
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
    a->next = n;
}

/**
 * @brief Deletes a node from linked list
 *
 * @param l - input linked list
 * @param n - any node to be deleted in linked list
 */
void delete_node(LinkedList *l, Node *n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(Node));
    temp = l->head;

    // case 1: if the node to be deleted is a head node
    if (temp == n)
    {
        l->head = n->next;
        free(n);
    }

    // case 2: if the node to be deleted is else where
    else
    {
        while (temp != NULL)
        { // traverse though the node
            if (temp->next == n)
            {
                temp->next = n->next;
                free(n);
                break;
            }
            temp = temp->next;
        }
    }
}

/* User Interface */
int main()
{
    // create a new linked list with nodes
    LinkedList *l = new_list(10);
    Node *a, *b, *c;
    a = new_node(20);
    b = new_node(50);
    c = new_node(60);

    // links all nodes with linked list
    l->head->next = a;
    a->next = b;
    b->next = c;

    // print out linked list
    traversal(l);

    // create a new node
    struct Node *z;

    // test insert
    z = new_node(0);
    insert_at_beginning(l, z);
    z = new_node(-10);
    insert_at_beginning(l, z);
    z = new_node(100);
    insert_at_last(l, z);
    z = new_node(30);
    insert_node_after(z, a);
    z = new_node(40);
    insert_node_after(z, a->next);
    z = new_node(500);
    insert_node_after(z, a->next->next);

    // print out linked list
    traversal(l);

    // test delete
    delete_node(l, l->head);
    delete_node(l, z);

    // print out linked list
    traversal(l);

    return 0;
}