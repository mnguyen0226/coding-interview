/*Implementation of Stacks using Linked List in C*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *top;
} Stack;

/**
 * @brief Makes a new node with input int data
 *
 * @param data - input int data
 * @return Node*
 */
Node *new_node(int data)
{
    Node *z = (Node *)malloc(sizeof(Node));
    z->data = data;
    z->next = NULL;
    return z;
}

/**
 * @brief Creates a new empty stacks
 *
 * @return Stack*
 */
Stack *new_stack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->head = NULL;
    s->top = NULL;
    return s;
}

/**
 * @brief Traverses through stacks and print out all element values
 *
 * @param s - input stack
 */
void traversal(Stack *s)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = s->head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Checks whether the stack is empty by checking the top pointer
 *
 * @param s - input stack
 * @return int - 1 if the stack is empty, 0 if not empty
 */
int is_empty(Stack *s)
{
    if (s->top == NULL)
        return 1;
    return 0;
}

/**
 * @brief Pushs the new node to the stack's top
 *
 * @param s - input stack
 * @param n - new node
 */
void push(Stack *s, Node *n)
{
    // if the stack is empty then set the head and top pointer to the new node
    if (is_empty(s))
    {
        s->head = n;
        s->top = n;
    }
    // if not, then link and set the new node with the top pointer
    else
    {
        s->top->next = n;
        s->top = n;
    }
}

/**
 * @brief Pops the top node out of the stack and return the data
 *
 * @param s
 * @return int
 */
int pop(Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack Underflow\n");
        return -100000;
    }
    else
    {
        int r = s->top->data;

        // create a temp, delete top, then set top to temp
        Node *temp = (Node *)malloc(sizeof(Node));
        temp = s->head;

        // traverse to find top
        while (temp->next != s->top)
        {
            temp = temp->next;
        }
        temp->next = NULL; // s->top->next
        free(s->top);
        s->top = temp;
        return r;
    }
}

/**
 * @brief Returns the top of the stacks
 * 
 * @param s - input stacks
 * @return int 
 */
int get_top(Stack *s){
    return s->top->data;
}

/*User Interface*/
int main()
{
    // creates new stack and nodes
    Stack *s = new_stack();

    Node *a, *b, *c;
    a = new_node(10);
    b = new_node(20);
    c = new_node(30);

    pop(s); // test underflow
    push(s, a);
    push(s, b);
    push(s, c);

    traversal(s);
    pop(s);
    traversal(s);

    printf("Top Elements is: %d", get_top(s));

    return 0;
}