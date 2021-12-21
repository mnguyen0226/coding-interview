// Stack Linked List Class in CPP

#include <iostream>
using namespace std;

/* Node Class */
class Node
{
public:
    int data;
    Node *next;
};

/* Stack Class */
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void Push(int x);
    int Pop();
    void Display();
};

/* Push new element to the head node of the linked list */
void Stack::Push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack is Full." << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

/* Pop the head node out of the linked list */
int Stack::Pop()
{

    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

/* Traverse and display all the elements in the linked list */
void Stack::Display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/* User Interface */
int main()
{
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);

    st.Display();

    st.Pop();

    st.Display();
    
    return 0;
}