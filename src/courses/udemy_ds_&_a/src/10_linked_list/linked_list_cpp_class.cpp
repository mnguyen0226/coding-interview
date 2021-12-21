// Writing CPP class of Linked List
#include <iostream>
using namespace std;

/* Node class */
class Node
{
public:
    int data;
    Node *next;
};

/* Linked List class */
class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; } // constructor
    LinkedList(int A[], int n);    // parameterized constructor
    ~LinkedList();                 // destructor

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

/* Creates a Linked List from array with n number of elements in the array */
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first; // traversal pointer

    for (i = 1; i < n; i++)
    {
        t = new Node;   // create a new node (instead of malloc)
        t->data = A[i]; // insert data to that node
        t->next = NULL; // set next = null
        last->next = t; // insert the new node to the linked list, aka link the last node to the new node
        last = t;       // set the new node as last node
    }
}

/* Deallocates memory of linked list and delete all the pointers and nodes in linked list*/
LinkedList::~LinkedList()
{
    Node *p = first; // make p a new traversal node
    while (first)
    {
        first = first->next;
        delete p; // deallocate and delete
        p = first;
    }
}

/* Displays all the elements in the linked list */
void LinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/* Returns the length of the linked list */
int LinkedList::Length()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

/* Inserts a new node at certain index with certain value */
void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first; // new node t to create new node and p as traversal node

    // invalid index
    if (index < 0 || index > Length())
    {
        return;
    }

    // create a new node and insert in the linked list
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0) // if inserted index is the first position
    {
        first = t;
    }
    else // other position
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next; // traverse to position index
        }
        t->next = p->next; // new node's next is p next
        p->next = t;       // then set p->next to t
    }
}

int LinkedList::Delete(int index)
{
    Node *p, *q = NULL; // p as traversal node and q as the node that follow p
    int x = -1;

    if (index < 1 || index > Length())
    {
        return -1; // if the index is invalid
    }
    if (index == 1)
    {                        // if we want to delete the first node
        p = first;           // have p as a place holder for first
        first = first->next; // move the header pointer
        x = p->data;         // extract the data from the first node
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

/* User Interface */
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList L(A, 5);

    cout << L.Delete(1) << endl;

    L.Display();

    return 0;
}