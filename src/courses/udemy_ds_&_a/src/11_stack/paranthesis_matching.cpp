// Stack Application: Check if the paranthesis are matched and balance or not.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

/* Push new element in the Stack */
void Push(char x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Stack is full \n");
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

/* Pop element out of the Stack */
char Pop()
{
    struct Node *temp;
    char x = -1;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

/* Display all elements in the Stack */
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* Check balance parenthesis pair */
int isBalanced(char *exp)
{
    // Go through the string to push and pop the stack
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            { // there is nothing in the stack to pop out
                return 0;
            }
            Pop();
        }
    }
    if (top == NULL)
    { // if there is nothing in the stack
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Check balance parenthesis pair */
int isBalanced2(char *exp)
{
    // Go through the string to push and pop the stack
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == NULL)
            { // there is nothing in the stack to pop out
                return 0;
            }
            else
            {
                char temp = top->data;
                if (temp == '(' && exp[i] == ')')
                {
                    Pop();
                }
                else if (temp == '[' && exp[i] == ']')
                {
                    Pop();
                }
                else if (temp == '{' && exp[i] == '}')
                {
                    Pop();
                }
            }
        }
    }
    if (top == NULL)
    { // if there is nothing in the stack
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
    char exp[] = "((a+b)*(c+d))";
    printf("Is Balanced? %d\n", isBalanced(exp));

    char exp2[] = "{([a+b]*[c+d])/e}";
    printf("Is Balanced? %d\n", isBalanced2(exp2));

    char exp3[] = "{[(a+b]*[c+d])/e}";
    printf("Is Balanced? %d\n", isBalanced2(exp3));

    return 0;
}