#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct Node *t = root; // t is used for traversal, but we need the follow t (move 1 step behind t) so that if t is at Null, we still have a pointer to link the new node to the leaf node.
    struct Node *r, *p;    // follow

    if (root == NULL) // if there is no node in the tree, then we create one and set it as root
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p; // set root as new node
        return;
    }

    while (t != NULL) // if there are nodes in the tree, we have to find the spot to insert it
    {
        // move the follow t to t
        r = t;
        if (key < t->data) // set as left child
        {
            t = t->lchild;
        }
        else if (key > t->data) // set as right child
        {
            t = t->rchild;
        }
        else // if it is equal, we can't add to the tree
        {
            return;
        }
    }
    // create a new node if
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void InOrder(struct Node *p)
{
    if (p != NULL)
    {
        InOrder(p->lchild);
        printf("%d, ", p->data);
        InOrder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node *RecursiveInsert(struct Node *p, int key)
{                  // p is root
    if (p == NULL) // if the tree if empty
    {
        Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    { // insert in the left handside
        p->lchild = RecursiveInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RecursiveInsert(p->rchild, key);
    }
    else
    {
        return p;
    }
}

int Height(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *InPre(struct Node *p)
{ // find right most child
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct Node *InSuc(struct Node *p)
{ // find left most child
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    { // key is found
        // based on the height of left subtree vs right subtree then I will pick predecessor or successor
        if (Height(p->lchild) > Height(p->rchild))
        { // delete element from LHS as it is higher
            // need a function to find in predecessor - the right most node of the left subtree
            q = InPre(p->lchild);
            p->data = q->data; // set the data of the predecessor node to the deleted node
            p->lchild = Delete(p->lchild, q->data); 
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data; // set the data of the predecessor node to the deleted node
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    // Insert(10); // root
    // Insert(5);
    // Insert(20);
    // Insert(8);
    // Insert(30);

    // InOrder(root);
    // printf("\n");

    root = RecursiveInsert(root, 50); // create a first node thus have root point to it
    RecursiveInsert(root, 10);
    RecursiveInsert(root, 40);
    RecursiveInsert(root, 20);
    RecursiveInsert(root, 30);

    Delete(root, 50);

    InOrder(root);
    printf("\n");

    struct Node *temp = Search(20);
    if (temp != NULL)
    {
        printf("Element is found: %d\n", temp->data);
    }
    else
    {
        printf("Element is not found\n");
    }

    printf("Root Data: %d\n", root->data);

    return 0;
}