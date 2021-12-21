// Linked List
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*Struct for the first node of the linked list*/
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; // A pointer is a node type. Thus the first node will have the data and the pointer to the next node

/* Function take in the array and number of elements to create a linked list */
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first; // last is use as a traversal pointer so first pointer can keep hold of the pointer to the linked list

    for (i = 1; i < n; i++)
    {
        // create a node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t; // set connection
        last = t;       // move the pointer to a newly created node
    }
}

/* Function take in the array and number of elements to create a linked list */
void Create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second; // last is use as a traversal pointer so first pointer can keep hold of the pointer to the linked list

    for (i = 1; i < n; i++)
    {
        // create a node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t; // set connection
        last = t;       // move the pointer to a newly created node
    }
}

/* Display the entire linked list with just the head node */
void Display(struct Node *p)
{
    printf("\n\nLinked List Displayment:");
    while (p != NULL)
    {
        printf("\nData: %d", p->data);
        p = p->next; // move the pointer to point to the next node
    }
} // when the function is complete, p is set to NULL again since p = p->next

/* Display all values in the linked list via recursion */
void RecursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("\nData: %d", p->data);
        RecursiveDisplay(p->next);
    }
}

/* Count number of nodes in the linked list */
int CountNode(struct Node *p)
{
    int counter = 0;
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

/* Calculate the Sum of all data in the linked list */
int Sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

/* Find the max value in the linked list */
int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

/* Find and return the node address based on the data */
struct Node *Search(struct Node *p, int data)
{
    while (p)
    {
        if (p->data == data)
        {
            return (p);
        }
        p = p->next;
    }
    printf("\n\nThere is no node in the linked list with data %d", data);
    return NULL;
}

/* Find and return the node address based on the data and move the found node to the top */
struct Node *MoveToHeadSearch(struct Node *p, int data)
{
    struct Node *pre_p = NULL;
    while (p)
    {
        if (p->data == data)
        {
            pre_p->next = p->next; // previous p pointer points to the next of p
            p->next = first;       // let p point to the first
            first = p;             // set the first point to be p
            return p;              // return the address of that found node
        }
        // if not able to find, move to front
        pre_p = p;
        p = p->next;
    }
    printf("\n\nThere is no node in the linked list with data %d", data);
    return NULL;
}

/* Insert new node to the front of the linked list
- Linked List Node Position is 1 2 3 4 5
- Linked List Node Insertion Position is 0 1 2 3 4 5 between the node (that's why it is insert after a given position)
*/
void Insert(struct Node *p, int data, int pos) // p is the first node
{
    struct Node *temp;
    // if the position is out of the linked list length
    if (pos < 0 || pos > CountNode(p))
    {
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    if (pos == 0)
    { // insert new node to the first node
        temp->next = first;
        first = temp; // not first->next
    }
    else // insert a new node after a given position
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

/* Function insert an element in a sorted linked list */
void SortedInsert(struct Node *p, int x)
{ // x is element
    struct Node *new_node, *follow_p = NULL;

    // create a new Node to store data x
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;

    // check if the linked list is null
    if (first == NULL)
    {
        first = new_node;
    }
    else
    { // iterate to find the position
        // move both pointer p and follow_p to be the next node
        while (p && p->data < x)
        {
            follow_p = p;
            p = p->next;
        }
        // if there is a node but the new node has value smaller than the first node
        if (p == first)
        {
            new_node->next = first;
            first = new_node;
        }
        else
        {
            // insert new node to linked list
            new_node->next = p;
            follow_p->next = new_node;
        }
    }
}

/* Function delete the node from the linked list*/
int DeleteNode(struct Node *p, int position)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *follow_temp = (struct Node *)malloc(sizeof(struct Node));
    int x = -1; // store value of the deleted node

    // if we want to delete the first node
    if (position == 1)
    {
        temp = p; // set temp to p
        p = p->next;
        x = temp->data;
        delete temp;
    }

    // if we want to delete the node at any position
    else
    {
        // set temp to be the first node and the following temp as NULL
        temp = p;
        follow_temp = NULL;

        // traverse position - 1 time
        for (int i = 0; i < position - 1 && p; i++)
        {
            follow_temp = temp;
            temp = temp->next;
        }

        // do the delete
        if (temp)
        { // temp is the one that we want to delete at position
            follow_temp->next = temp->next;
            x = temp->data;
        }
        delete temp;
    }
    return x;
}

/* Function checks whether a linked list is sorted or not */
bool CheckSort(struct Node *p)
{
    int x = -32768;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = p;
    while (temp != NULL)
    { // traverse till the end of the linked list
        if (temp->data < x)
        { // if it is smaller than the smallest number of ther current number is smaller than the previous number
            return false;
        }
        x = temp->data;    // set x to the the current data
        temp = temp->next; // move to the next node
    }
    return true;
}

/* Consider a sorted linked list, delete the duplicate */
int DeleteDuplicateSort(struct Node *p)
{
    int x = -1;
    struct Node *temp, *follow_temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    follow_temp = p;
    temp = p->next;
    while (temp)
    { // while the linked list is not null
        // foward the two node
        if (temp->data != follow_temp->data)
        {
            follow_temp = temp;
            temp = temp->next; // stop when temp == NULL
        }

        // if the two node is equal, then delete
        else if (temp->data == follow_temp->data)
        {
            x = temp->data;                 // get the data of the deleted node
            follow_temp->next = temp->next; // delete temp node
            delete temp;
            temp = follow_temp->next;
        }
    }
    return x;
}

/* Reverse linked list using array - node reversal */
void Reverse1(struct Node *p)
{
    // create an array for reversing the node
    int *A;
    int i = 0;
    A = (int *)malloc(sizeof(int) * CountNode(p));

    // copy data of linked list to array
    struct Node *temp; // for traversal
    temp = first;
    while (temp)
    {
        A[i] = temp->data;
        temp = temp->next;
        i++;
    }

    // copy the reverse of array to linked list
    temp = first;
    i--;
    while (temp)
    {
        temp->data = A[i];
        temp = temp->next;
        i--;
    }
}

/* Reverse linked list by sliding pointers */
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

/* Reverse linked list by recursion */
void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        // This is equivalent to set q = p and set p = p=>next
        Reverse3(p, p->next); // moving to the end of linked list
        p->next = q;          // after move back we reverse the link
    }
    else
    {
        first = q; // p now is null and q is the last node so we set first to be q
    }
}

/* Function concatenate two linked list to create a third linked list*/
void Concatenate(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

/* Function merge the two linked list in sorted order */
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    { // while the two linked list exist
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
}

/* User Interface */
int main()
{
    int A[] = {3, 5, 5, 5, 7, 10, 15};
    int B[] = {4, 6, 11, 21, 31, 41, 51};
    Create(A, 5); // create a linked list
    Create2(B, 5);

    printf("Display First Linked List");
    Display(first);

    printf("Display Second Linked List");
    Display(second);

    // Concatenate(first, second);
    // Display(third);

    Merge(first, second);

    Display(third);

    //////////////////////////////////////////////////////////////
    // printf("\n\nRecursive Display");
    // RecursiveDisplay(first);

    // int num_node = CountNode(first);
    // printf("\n\nNumber of nodes: %d", num_node);

    // int sum = Sum(first);
    // printf("\n\nSum of linked list is: %d", sum);

    // int max = Max(first);
    // printf("\n\nMax of linked list is: %d", max);

    // Node *found = Search(first, 20);
    // printf("\n\nThe address of the node is: %p", found);

    // Node *temp = first;                        // make a copy of first for traversal but first is still pointing to the head of the linked list
    // Node *found2 = MoveToHeadSearch(temp, 15); // temp is a copy of first
    // printf("\n\nThe address of the node is: %p", found2);

    // Display(first);

    // Insert(first, 21, 5);
    // Display(first);

    // Insert(first, -1, 0);
    // Display(first);

    // SortedInsert(first, 11);
    // Display(first);

    // int delete_value = DeleteNode(first, 3);
    // Display(first);

    // if (CheckSort(first))
    // {
    //     printf("\n\nThe linked list is sorted.");
    // }
    // else
    // {
    //     printf("\n\nThe linked list is not sorted.");
    // }

    // int delete_duplicate = DeleteDuplicateSort(first);
    // printf("\n\nThe deleted duplicate data is %d", delete_duplicate);

    // Reverse1(first);
    // Display(first);

    // Reverse2(first);
    // Display(first);

    // Reverse3(NULL, first);
    // Display(first);

    return 0;
}