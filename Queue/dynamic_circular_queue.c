// dynamic circular queue

#include <stdio.h>
#include <stdlib.h>

void insert(float *cq, int *rear, int *count, int n)
{
  float elem;
  if (*count == (n))
  {
    printf("Queue is full");
    return;
  }
  (*rear) = ((*rear) + 1) % n;
  printf("\nEnter elem:");
  scanf("%f", &elem);
  cq[*rear] = elem;
  (*count)++;
}

void delete(float *cq, int *front, int *count, int n)
{
  if ((*count) == 0)
  {
    printf("Queue is empty");
    return;
  }
  printf("%f is deleted.", cq[*front]);
  (*front) = ((*front) + 1) % n;
  (*count)--;
}

void display(float *cq, int front, int count, int n)
{
  printf("\nthe queue elements are:");
  for (int i = 0; i < count; i++)
  {
    printf("\n %f", cq[front]);
    front = (front + 1) % n;
  }
}

int main()
{
  int ch, n, count = 0, front = 0;
  float *cq;
  int rear;
  printf("Enter the max:");
  scanf("%d", &n);
  rear = n - 1;
  cq = (float *)malloc(sizeof(float) * n);

  while (1)
  {
    printf("\n enter \n 1.insert \n 2.delete \n 3.display \n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      insert(cq, &rear, &count, n);
      break;
    case 2:
      delete (cq, &front, &count, n);
      break;
    case 3:
      display(cq, front, count, n);
      break;
    default:
      exit(0);
    }
  }
  free(cq);
}