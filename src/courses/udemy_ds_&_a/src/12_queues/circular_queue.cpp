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
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

/* Adds new element to queue */
void Enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
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
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

/* Displays all queue's elements */
void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

/* User Interface */
int main()
{
    struct Queue q; // create new queue in a stack
    Create(&q, 5);  // only take 4 elements

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);

    Display(q);

    Dequeue(&q);
    Dequeue(&q);

    Display(q);

    Enqueue(&q, 60);
    Enqueue(&q, 70);

    Display(q);

    return 0;
}