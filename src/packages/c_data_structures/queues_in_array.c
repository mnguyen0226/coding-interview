/*Implementation of Queues with Array from scratch in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int head;
    int tail;
    int size;
    int Q[];
} Queue;

/**
 * @brief Creates an empty queue from size
 *
 * @param size - input size
 * @return Queue*
 */
Queue *new_queue(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue) + size*sizeof(int));

    // initially, the queue will be empty, both head and tain will point in the same index 1
    q->head = 1;
    q->tail = 1;
    q->size = size;

    return q;
}

/**
 * @brief Checks if the input queue is empty or not
 *
 * @param q - input queue
 * @return int - 1 if the queue is empty, 0 otherwise
 */
int is_empty(Queue *q)
{
    if (q->tail == q->head)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Checks if the input queue is full or not, only happen with array
 *
 * @param q - input queue
 * @return int - 1 if the queue is full, 0 otherwise
 */
int is_full(Queue *q)
{
    if (q->head == q->tail + 1)
    { // circular check
        return 1;
    }
    return 0;
}

/**
 * @brief Adds an element to the tail of queue
 *
 * @param q - input queue
 * @param x - input value to be added
 */
void enqueue(Queue *q, int x)
{
    if (is_full(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->Q[q->tail] = x; // since the tail is empty, set the Q[tail] = x

        // move tail pointer
        if (q->tail == q->size)
        {                // if queue is full
            q->tail = 1; // replace the q->head
        }
        else
        {
            q->tail = q->tail + 1;
        }
    }
}

/**
 * @brief Returns and deletes the front element of queue
 *
 * @param q - input queue
 * @return int
 */
int dequeue(Queue *q)
{
    if (is_empty(q))
    { // check if the queue is empty
        printf("Queue Underflow\n");
        return -1000; // indicator that queue is empty
    }
    else
    {
        int x = q->Q[q->head]; // retrieve from head
        if (q->head == q->size)
        { // if keep retreive all iteam till the end, then move to the front circularly
            q->head = 1;
        }
        else
        {
            q->head = q->head + 1;
        }
        return x;
    }
}

/**
 * @brief Traverses and displays all elements in the queue
 *
 * @param q - input queue
 */
void traverse(Queue *q)
{
    for (int i = q->head; i < q->tail; i++)
    {
        printf("%d\n", q->Q[i]);
        if (i == q->size)
        { // if reach the end of queue then move pointer to front
            i = 0;
        }
    }
}

/*User Interface*/
int main()
{
    Queue *q = new_queue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    traverse(q);

    printf("\n");

    dequeue(q);
    dequeue(q);
    traverse(q);

    printf("\n");

    enqueue(q, 60);
    enqueue(q, 70);
    traverse(q);

    return 0;
}