/*Reverses a Linked List using Stacks*/

#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;
};

/**
 * @brief Reverses linked list using stack
 * 
 * @param head 
 */
void reverse_linked_list(Node **head)
{
    stack<Node *> s;
    Node *temp = *head; // set temp for traversal

    // push all the node to stack
    while (temp->next_node != NULL)
    {
        s.push(temp);
        temp = temp->next_node;
    }

    // temp now is at the top of the stack, set the head at the top of the stack
    *head = temp; // start new linked list

    // pop all the element out of the stack
    while (!s.empty())
    {
        // store the top value of the stack in the list
        temp->next_node = s.top();

        // pop the top item out of the stack
        s.pop();

        // move to the next block in the linked list
        temp = temp->next_node;
    }
    temp->next_node = NULL; // end of linked list, for traversal
}

/**
 * @brief Prints out all elements in the linked list
 * 
 * @param temp 
 */
void traversal(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next_node;
    }
    cout << endl;
}

/**
 * @brief Insert new data to the end of the linked list
 * 
 * @param head 
 * @param data 
 */
void insert_back(Node **head, int data)
{
    Node *temp = new Node(); // temp stores the data
    temp->data = data;
    temp->next_node = NULL;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    else
    {
        Node *last_node = *head;
        while (last_node->next_node != NULL)
        {
            last_node = last_node->next_node;
        }
        last_node->next_node = temp;
        return;
    }
}

/*User Interface*/
int main()
{
    Node *head = NULL;
    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_back(&head, 3);
    insert_back(&head, 4);
    cout << "Initial Linked List: ";
    traversal(head);

    reverse_linked_list(&head);
    cout << "Reverse Linked List: ";
    traversal(head);
    return 0;
}