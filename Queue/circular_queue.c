#include <stdio.h>
#include <stdlib.h>
#define max 4

void insert_cq(int *cq, int *rear, int *count)
{
    int elem;
    if (*count == max)
    {
        printf("\nQueue is full.");
        return;
    }
    printf("\nenter element:");
    scanf("%d", &elem);
    (*rear) = ((*rear) + 1) % max;
    cq[*rear] = elem;
    (*count)++;
}

void delete_cq(int *cq, int *front, int *count)
{
    int elem;
    if (*count == 0)
    {
        printf("\nUnderflow condition.");
        return;
    }
    elem = cq[*front];
    printf("\n %d is deleted", elem);
    (*front) = ((*front) + 1) % max;
    (*count)--;
}

void display(int *cq, int front, int count)
{
    if (count == 0)
    {
        printf("No element");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("\n %d ", cq[front]);
        front = (front + 1) % max;
    }
}

int main()
{
    int cq[max], front = 0, rear = max - 1, count = 0;
    int ch;
    while (1)
    {
        printf("\nEnter 1.inser \n 2.delete \n 3.display \n 4.exit \n");
        printf("enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_cq(cq, &rear, &count);
            break;
        case 2:
            delete_cq(cq, &front, &count);
            break;
        case 3:
            display(cq, front, count);
            break;
        default:
            exit(0);
        }
    }
}