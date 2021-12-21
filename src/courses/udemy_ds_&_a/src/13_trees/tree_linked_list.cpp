// Implementation of Tree in linked list and queue
// We have the representation of a tree on paper, if the left-child or right child of the node does not exist then we mark -1.
// We use the circular queue as a buffer.
// Create a root node, then dequeue it to append to the root node.
// If on paper there is a right child of root node then append to the queue
// If on paper there is a left child of root node then append to the queue
// If we type -1 then it will keep dequeue the queue until the rear node to go back to the front node.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue // create with dynamic array. This is circular queue
{
    int size;
    int front;
    int rear;
    Node **Q; // dynamic array to store type Node
};

void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

void Enqueue(struct Queue *q, Node *x)
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

Node *Dequeue(struct Queue *q)
{
    Node *x = NULL;

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

int IsEmpty(struct Queue q)
{
    return q.front == q.rear;
}
////////////////////////////////////////////////////////////////////
struct Node *root = NULL;

void CreateTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;  // note that the queue is empty
    Create(&q, 100); // create a queue of 100 space for 100 nodes of the tree

    // Create a root node for a tree
    printf("Enter Root Value:");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;

    Enqueue(&q, root); // append the root node to queue

    while (!IsEmpty(q))
    { // move data from queue to Tree
        p = Dequeue(&q);
        printf("Enter Left Child of %d: ", p->data); // create a left child
        scanf("%d", &x);
        if (x != -1) // create the left child if there is no left child of the current node
        {
            t = (struct Node *)malloc(sizeof(struct Node)); // create a node
            t->data = x;
            t->rchild = NULL;
            t->lchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }

        printf("Enter Right Child of %d: ", p->data); // create a left child
        scanf("%d", &x);
        if (x != -1) // create the right child if there is no right child of the current node
        {
            t = (struct Node *)malloc(sizeof(struct Node)); // create a node
            t->data = x;
            t->rchild = NULL;
            t->lchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }
}

/* Print out the data in Pre-order recursively*/
void PreOrderDisplay(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data); // this is the root
        PreOrderDisplay(p->lchild);
        PreOrderDisplay(p->rchild);
    }
}

/* Print out the data in In-order recursively*/
void InOrderDisplay(struct Node *p)
{
    if (p)
    {
        InOrderDisplay(p->lchild);
        printf("%d ", p->data); // this is the root node
        InOrderDisplay(p->rchild);
    }
}

/* Print out the data in Post-order recursively*/
void PostOrderDisplay(struct Node *p)
{
    if (p)
    {
        PostOrderDisplay(p->lchild);
        PostOrderDisplay(p->rchild);
        printf("%d ", p->data); // this is the root node
    }
}

////////////////////////////////////////////////////////////////////
struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void StackCreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void Push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *Pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top == st.size - 1;
}

void IterativePreOrder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);
    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            Push(&stk, p);
            p = p->lchild;
        }
        else
        { // traverse back when hit the leave node
            p = Pop(&stk);
            p = p->rchild;
        }
    }
}

void IterativeInOrder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);
    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            Push(&stk, p);
            p = p->lchild;
        }
        else
        { // traverse back when hit the leave node
            p = Pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

////////////////////////////////////////////////////////////////////
/* User Interface */
int main()
{
    CreateTree(); // create a tree with 1 root node
    printf("\nPre Order Display:");
    PreOrderDisplay(root);

    printf("\nIn Order Display:");
    InOrderDisplay(root);

    printf("\nPost Order Display:");
    PostOrderDisplay(root);

    printf("\nIterative Pre Order Display:");
    IterativePreOrder(root);

    printf("\nIterative In Order Display:");
    IterativeInOrder(root);

    return 0;
}