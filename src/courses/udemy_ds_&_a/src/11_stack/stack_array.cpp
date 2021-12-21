// Stack Implementation using Array.
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top; // index of the top
    int *s;  // pointer to the stack
};

/* Create a stack fron struct stack - like constructor */
void Create(struct Stack *st)
{
    printf("Enter the size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;                                  // initialize top
    st->s = (int *)malloc(st->size * sizeof(int)); // create an array for stack
}

/* Display all elements in the stack */
void Display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

/* Push operator for Stack */
void Push(struct Stack *st, int x)
{
    // check if the stack is full
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        st->top++;
        st->s[st->top] = x; // insert data to stack
    }
}

/* Pop operator for Stack */
int Pop(struct Stack *st)
{
    // check if the stack is empty
    int x = -1;

    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->s[st->top]; // get the data
        st->top--;
    }
    return x;
}

/* Peek operator for Stack */
int Peek(struct Stack st, int index)
{
    int pos = st.top - index + 1;
    int x = -1;

    if (pos < 0)
    {
        printf("Invalid Index\n");
    }
    else
    {
        x = st.s[pos];
    }
    return x;
}

/* Check which data is on top of the stack */
int StackTop(struct Stack st)
{
    if (st.top == -1)
    { // if the stack is empty
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}

/* Check if the stack is Empty or not */
int IsEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Check if the stack is Full or not */
int IsFull(struct Stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* User Interface */
int main()
{
    struct Stack st;
    Create(&st);

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 50);

    // printf("Pop: %d \n", Pop(&st));

    Display(st);

    printf("Peek: %d \n", Peek(st, 4)); // expect 10, position 4 has index = 0 = 3 - 4 + 1

    return 0;
}