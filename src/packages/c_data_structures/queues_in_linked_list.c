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
 * @brief Creates a new node from input int data
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

/**
 * @brief Creates a new empty queue
 *
 * @return Queue*
 */
Queue *new_queue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

/**
 * @brief Traverses through the input queue
 *
 * @param q - input queue
 */
void traversal(Queue *q)
{
    Node *temp = q->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Checks if the input queue is empty or not
 *
 * @param q - input queue
 * @return int - 1 if the queue is empty, 0 otherwise
 */
int is_empty(Queue *q)
{
    if (q->head == NULL)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Adds an new node in the front of the queue
 *
 * @param q - input queue
 * @param n - new node
 */
void enqueue(Queue *q, Node *n)
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

/**
 * @brief Removes and returns values of the node at head/front of the queue
 *
 * @param q - input queue
 * @return int
 */
int dequeue(Queue *q)
{
    if (is_empty(q))
    {
        printf("Underflow\n");
        return -1000;
    }
    else
    {
        int x = q->head->data; // get the data from head
        Node *temp = q->head;  // move the head pointer
        q->head = q->head->next;
        free(temp);
        return x;
    }
}

/**
 * @brief Returns but not removes the values of the node at head/front of the queue
 *
 * @param q - input queue
 * @return int
 */
int front(Queue *q)
{
    return q->head->data;
}

/*User Interface*/
int main()
{
    Queue *q = new_queue();

    Node *a, *b, *c;
    a = new_node(10);
    b = new_node(20);
    c = new_node(30);

    dequeue(q);
    enqueue(q, a);
    enqueue(q, b);
    enqueue(q, c);

    traversal(q);
    dequeue(q);
    traversal(q);

    printf("Front of queue is: %d", front(q));

    return 0;
}
