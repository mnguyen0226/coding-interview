// Queue Implementation using Array
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; // for dynamically create array in the heap
};

/* Creates a new queue with size */
void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

/* Adds new element to queue */
void Enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

/* Deletes element from queue */
int Dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

/* Displays all queue's elements */
void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

/* User Interface */
int main()
{
    struct Queue q; // create new queue in a stack
    Create(&q, 5);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);

    Display(q);

    Dequeue(&q);

    Display(q);

    return 0;
}