// Prefix to Postfix conversion with Stack

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

/* Push new element in the Stack */
void Push(int x)
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
int Pop()
{
    struct Node *temp;
    int x = -1;
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

int IsPrecedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    return true;
}

char *InToPost(char *infix)
{
    char *postfix;
    int i = 0, j = 0;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (IsOperand(infix[i]))
        { // a,b,c...
            postfix[j++] = infix[i++];
        }
        else
        { // check precedences
            if (IsPrecedence(infix[i]) > IsPrecedence(top->data))
            {
                Push(infix[i++]);
            }
            else
            {
                postfix[j++] = Pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

/* Evaluate Postfix */
int Eval(char *postfix)
{
    int i = 0;
    int x1, x2, r;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (IsOperand(postfix[i]))
        {
            Push(postfix[i] - '0');
        }
        else
        {
            x2 = Pop();
            x1 = Pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;

            case '/':
                r = x1 / x2;
                break;
            }
            Push(r);
        }
    }
    return top->data;
}

/* User Interface */
int main()
{
    char postfix[] = "234*+82/-";
    printf("Result is %d\n", Eval(postfix));

    return 0;
}