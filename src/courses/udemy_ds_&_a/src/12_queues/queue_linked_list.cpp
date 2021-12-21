// Queue implementation using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void Enqueue(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Queue is Full \n");
    }
    else
    {
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
        { // if the queue is initially empty
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

int Dequeue()
{
    int x = -1;
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = front->data;
        temp = front;
        front = front->next;
        free(temp);
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);

    Display();

    printf("Dequeue %d \n", Dequeue());
    Display();

    return 0;
}