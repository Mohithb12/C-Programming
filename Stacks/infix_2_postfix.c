/*
Without push and pop functions infix to postfix conversion
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

int f(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;
    case '/':
    case '%':
    case '*':
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
    case '/':
    case '%':
    case '*':
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

int main()
{
    int j = 0, top = 0;
    char s[max] = {"#"}, pos[max], inf[max], ch;
    printf("\n enter infix expression:");
    scanf("%s", inf);
    for (int i = 0; i < strlen(inf); i++)
    {
        ch = inf[i];
        while (f(s[top]) > g(ch)) // if any

        {
            pos[j] = s[top];
            j++;
            top--;
        }
        if (f(s[top]) != g(ch))
        {
            s[++top] = ch;
        }
        else
            top--;
    }

    for (; s[top] != '#'; top--)
    {
        pos[j++] = s[top];
    }
    pos[j] = '\0';
    printf("\npostfix expression is: %s", pos);
}