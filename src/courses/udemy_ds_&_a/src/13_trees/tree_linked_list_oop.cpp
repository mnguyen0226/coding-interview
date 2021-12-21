// Create a tree with linked list using CPP
#include <iostream>
#include <stdio.h>
using namespace std;
///////////////////////
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

///////////////////////
class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    // constructor
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    // parameterized constructor
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void Enqueue(Node *x);
    Node *Dequeue();
    void Display();
    int IsEmpty() { return front == rear; };
};

void Queue::Enqueue(Node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::Dequeue()
{
    Node *x = NULL;
    if (front == rear)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << " " << Q[i];
    }
    cout << endl;
}

///////////////////////
class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void CreateTree();
    void PreOrderDisplay(Node *p);
    void PostOrderDisplay(Node *p);
    void InOrderDisplay(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *root);
    int Count(Node *root);
    int CountLeafNode(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100); // note that the queue is empty

    // Create a root node for a tree
    printf("Enter Root Value:");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;

    q.Enqueue(root); // append the root node to queue

    while (!q.IsEmpty())
    { // move data from queue to Tree
        p = q.Dequeue();
        printf("Enter Left Child of %d: ", p->data); // create a left child
        scanf("%d", &x);
        if (x != -1) // create the left child if there is no left child of the current node
        {
            t = new Node; // create a node
            t->data = x;
            t->rchild = NULL;
            t->lchild = NULL;
            p->lchild = t;
            q.Enqueue(t);
        }

        printf("Enter Right Child of %d: ", p->data); // create a left child
        scanf("%d", &x);
        if (x != -1) // create the right child if there is no right child of the current node
        {
            t = new Node; // create a node
            t->data = x;
            t->rchild = NULL;
            t->lchild = NULL;
            p->rchild = t;
            q.Enqueue(t);
        }
    }
}

/* Print out the data in Pre-order recursively*/
void Tree::PreOrderDisplay(Node *p)
{
    if (p)
    {
        printf("%d ", p->data); // this is the root
        PreOrderDisplay(p->lchild);
        PreOrderDisplay(p->rchild);
    }
}

/* Print out the data in In-order recursively*/
void Tree::InOrderDisplay(Node *p)
{
    if (p)
    {
        InOrderDisplay(p->lchild);
        printf("%d ", p->data); // this is the root node
        InOrderDisplay(p->rchild);
    }
}

/* Print out the data in Post-order recursively*/
void Tree::PostOrderDisplay(Node *p)
{
    if (p)
    {
        PostOrderDisplay(p->lchild);
        PostOrderDisplay(p->rchild);
        printf("%d ", p->data); // this is the root node
    }
}

void Tree::LevelOrder(Node *root)
{
    Queue q(100);
    cout << root->data;
    q.Enqueue(root);

    while (!q.IsEmpty())
    {
        root = q.Dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data;
            q.Enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data;
            q.Enqueue(root->rchild);
        }
    }
}

// int Tree::Count(Node *root){
//     if(root){ // if there is root
//         return Count(root->lchild) + Count(root->rchild) + 1;
//     }
// }

int Tree::Count(Node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = Count(root->lchild);
        y = Count(root->rchild);
        if (root->lchild && root->rchild)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int Tree::Height(Node *root)
{
    int x = 0;
    int y = 0;
    if (root == 0)
    {
        return 0;
    };
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int Tree::CountLeafNode(Node *root)
{
    int x, y; // initialize as 0
    if (root != NULL)
    {
        x = Count(root->lchild);
        y = Count(root->rchild);
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

///////////////////////
int main()
{
    Tree t;
    t.CreateTree();
    t.PreOrderDisplay(t.root);

    t.InOrderDisplay(t.root);
    t.PostOrderDisplay(t.root);
    t.LevelOrder(t.root);
}