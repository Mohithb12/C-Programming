#include <stdio.h>
#include <string.h>
#define max 30

int f(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

int g(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

void push(char *s, int *top, char ch)
{
    (*top)++;
    s[*top] = ch;
}

char pop(char *s, int *top)
{
    char ch;
    ch = s[*top];
    (*top)--;
    return ch;
}

void convert_infix2postfix(char infix[max])
{
    char s[max], postfix[max], ch;
    int top = -1, j = 0, i;
    push(s, &top, '#');

    for (int i = 0; i < infix[i] != '\0'; i++)
    {
        ch = infix[i];
        while ((f(s[top])) > g(ch))
        {
            postfix[j++] = pop(s, &top);
        }
        if ((f(s[top])) != g(ch))
        {
            push(s, &top, ch);
        }
        else
            top--;
    }

    while (s[top] != '#')
    {
        postfix[j] = pop(s, &top);
        j++;
    }
    postfix[j] = '\0';
    printf("%s", postfix);
}

int main()
{
    char infix[max];
    printf("Enter infix expression:");
    scanf("%s", infix);
    convert_infix2postfix(infix);
}
