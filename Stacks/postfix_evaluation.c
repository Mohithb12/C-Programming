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
        ch = postfix[i]; // ch is assigned each character
        if (isdigit(ch)) // checking if ch is digit
        {
            // if it is a oprand/number then push to stack
            push(stack, &top, ch - '0');
        }
        else // else if not number then it is operator pop 2 elem from stack
        {
            op2 = pop(stack, &top);         // assign 1st popped elem to 2nd operator
            op1 = pop(stack, &top);         // assign 2nd popped elem to 1nd operator
            result = compute(op1, ch, op2); // call compute function and assigned the returned value to variable
            push(stack, &top, result);      // push the result into stack
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