#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int n)
{
    int elem;
    printf("Enter element:");
    scanf("%d", &elem);
    if ((*top) == n - 1)
    {
        printf("\nstack is full.");
        return;
        // to avoid overflow condition use
        // stack = (int *)realloc(stack, n * 2);
        // to increase memory of stack
    }
    (*top)++;
    stack[*top] = elem;
}

void pop(int *stack, int *top)
{
    if ((*top) == -1)
    {
        printf("\n stack is empty.");
        return;
    }
    printf("\n%d is deleted.", stack[*top]);
    (*top)--;
}

void display(int *stack, int top)
{
    int i = 0;
    printf("\nstack elemnts are:");
    for (i = top; i >= 0; i--)
    {
        printf("\n %d", stack[i]);
    }
}
int main()
{
    int n, *stack, top = -1, ch;
    printf("Enter number of elements:");
    scanf("%d", &n);

    stack = (int *)malloc(sizeof(int) * n);
    while (1)
    {
        printf("\nEnter \n1.push\n2.pop\n3.display\n4.exit\n");
        printf("Enter choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(stack, &top, n);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            display(stack, top);
            break;
        default:
            exit(0);
        }
    }
    free(stack);
    return 0;
}
