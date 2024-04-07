#include <stdio.h>
#include <stdlib.h>

void q_insert(int *queue, int *rear, int n)
{
    int elem;
    printf("Enter elem:");
    scanf("%d", &elem);
    if ((*rear) == n - 1)
    {
        printf("\nQueue is full.");
        return;
    }
    (*rear)++;
    queue[*rear] = elem;
}

void q_delete(int *queue, int rear, int *front)
{
    if ((*front) > rear)
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("\n %d is deleted.", queue[*front]);
    (*front)++;
}

void display_q(int *queue, int rear, int front)
{
    if (front > rear)
    {
        printf("\n Queue is empty.");
        return;
    }
    printf("\n queue Elements are.");
    for (int i = front; i <= rear; i++)
    {
        printf("\n%d", queue[i]);
    }
}

int main()
{
    int *q, rear, front, n, ch;
    rear = -1, front = 0;
    printf("\nEnter number of elements.");
    scanf("%d", &n);
    q = (int *)malloc(sizeof(int) * n);
    while (1)
    {
        printf("\n enter \n 1.insert \n 2.delte \n 3.display \n 4.exit\n");
        printf("Enter choice.");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            q_insert(q, &rear, n);
            break;
        case 2:
            q_delete(q, rear, &front);
            break;
        case 3:
            display_q(q, rear, front);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
