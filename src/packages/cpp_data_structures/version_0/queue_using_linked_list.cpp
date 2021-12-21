// Queue Data Structure using linked list.
// Queue follows a First In Last Out Policy
// Operations:
// 1. Enqueue = add element to the tail of a queue
// 2. Dequeue = return and delete the elemetn from a queue
// 3. isEmpty = check whether the queue has any element or not
// 4. isFull = check whether the queue is full or not
// 5. Front = returns the front element of the queue but don't delete it.

#include <stdio.h>
#include <stdlib.h>

/* Define a node */
typedef struct node
{
    int data;
    struct node *next;
} node;

/* Define a linked list object */
typedef struct linked_list
{
    struct node *head;
    struct node *tail;
} queue;

/* Function makes a new node dynamically */
node *create_node(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    return n;
}

/* Function makes a new queue dynamically */
queue *create_queue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

/* Function traverse and print out all the element in the queue */
void traversal(queue *q)
{
    node *temp = q->head;
    while (temp != NULL)
    {
        printf("Data: %d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Function check if the queue is empty or node */
int is_empty(queue *q)
{
    if (q->head == NULL)
    {
        return 1;
    }
    return 0;
}

/* Function add a node to a queue */
void enqueue(queue *q, node *n)
{
    if (is_empty(q))
    {
        q->head = n;
        q->tail = n;
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
    }
}

/* Function remove an element at the end of the queue and return that element */
int dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is Underflow\n");
        return -1000;
    }
    else
    {
        int x = q->head->data;
        q->head = q->head->next;
        return x;
    }
}

int main()
{
    printf("Queue implementation using linked list \n");

    queue *q = create_queue();
    node *a, *b, *c;
    a = create_node(10);
    b = create_node(20);
    c = create_node(30);

    dequeue(q);
    enqueue(q, a);
    enqueue(q, b);
    enqueue(q, c);

    traversal(q);
    dequeue(q);

    traversal(q);

    return 0;
}