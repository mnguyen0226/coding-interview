// Queue Data Structure using array.
// Queue follows a First In Last Out Policy
// Operations:
// 1. Enqueue = add element to the tail of a queue
// 2. Dequeue = return and delete the elemetn from a queue
// 3. isEmpty = check whether the queue has any element or not
// 4. isFull = check whether the queue is full or not
// 5. Front = returns the front element of the queue but don't delete it.

#include <stdio.h>
#include <stdlib.h>

/* Define a queue object */
typedef struct queue
{
    int head;
    int tail;
    int size;
    int Q[]; // This is public so the whole files talks about the same queue
} queue;

/* Function creates queue with certain size dynamically */
queue *create_queue(int size)
{
    queue *q = (queue *)malloc(sizeof(queue) + size * (sizeof(int)));

    // q is empty so position is 1
    q->head = 1;
    q->tail = 1;
    q->size = size;

    return q;
}

/* Function checks if the queue is empty or not */
int is_empty(queue *q)
{
    if (q->tail == q->head)
    {
        return 1;
    }
    return 0;
}

/* Function checks if the queue is full or not */
int is_full(queue *q)
{
    if (q->head == q->tail + 1)
    {
        return 1;
    }
    return 0;
}

/* Enqueue adds the data to the end of the queue */
void enqueue(queue *q, int x)
{
    if (is_full(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {                      // if the queue is not full
        q->Q[q->tail] = x; // fill out the end slot of the array

        // If the tail is at the end of the queue and still be able to add at the front of head
        if (q->tail == q->size)
        { // if the tail is at the end
            q->tail = 1;
        }
        else
        {
            q->tail = q->tail + 1;
        }
    }
}

/* Dequeue removes the data in the front of the queue and return that data */
int dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue Underflow\n");
        return -1000;
    }
    else
    {
        int x = q->Q[q->head];

        // If the head (the one to be popped) is at the end, then set the head in front of the array
        if (q->head == q->size)
        {
            q->head = 1;
        }
        else
        { // if not then simply move to the next element in the array
            q->head = q->head + 1;
        }
        return x;
    }
}

/* Function traverse through the array and print out everything
 * Print from head to tail */
void display(queue *q)
{
    for (int i = q->head; i < q->tail; i++)
    {
        printf("%d\n", q->Q[i]);
        if (i == q->size)
        {
            i = 0;
        }
    }
}

int main()
{
    // Create a queue with size of 10
    queue *q = create_queue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    printf("\n");

    dequeue(q);
    dequeue(q);
    display(q);

    printf("\n");

    enqueue(q, 60);
    enqueue(q, 70);
    display(q);

    return 0;
}