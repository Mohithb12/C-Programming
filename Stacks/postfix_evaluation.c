#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define max 30

void push(int *stack, int *top, int n)
{
    (*top)++;
    stack[*top] = n;
}

int pop(int *stack, int *top)
{
    int n;
    n = stack[*top];
    (*top)--;
    return n;
}

int compute(int op1, char ch, int op2)
{
    switch (ch)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '%':
        return (op1 % op2);
    case '/':
        return (op1 / op2);
    case '*':
        return (op1 * op2);
    case '^':
        return (pow(op1, op2));
    }
}

// IMP function
void eval_postfix(char postfix[max])
{
    int stack[max];
    int top = -1, result, op1, op2;
    char ch;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(stack, &top, ch - '0');
        }
        else
        {
            op2 = pop(stack, &top);
            op1 = pop(stack, &top);
            result = compute(op1, ch, op2);
            push(stack, &top, result);
        }
    }
    printf("Result=%d", pop(stack, &top));
}

int main()
{
    char postfix[max];
    printf("Enter postfix expression:");
    scanf("%s", postfix);
    eval_postfix(postfix);
}