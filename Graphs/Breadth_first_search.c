// bfs
#include <stdio.h>
int a[10][10], f[10];
int q[20];

void read_adj(int n)
{
  int i, j;
  printf("Enter adjacency matrix:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
}

int main()
{
  int source = 0, front = 0, rear = -1, n;
  int j;
  printf("Enter number of nodes:");
  scanf("%d", &n);
  read_adj(n);
  for (source = 0; source < n; source++)
  {
    for (int i = 0; i < n; i++)
    {
      f[i] = 0;
    }
    rear = -1;
    front = 0;
    printf("\nThe BFS traversal %d for the graph is: %d\n", source, source);
    q[++rear] = source;
    f[source] = 1;
    while (front <= rear)
    {

      for (j = 0; j < n; j++)
      {
        if (a[q[front]][j] == 1 && f[j] == 0)
        {
          q[++rear] = j;
          f[j] = 1;
          printf("%d", j);
        }
      }
      front++;
    }
  }
}