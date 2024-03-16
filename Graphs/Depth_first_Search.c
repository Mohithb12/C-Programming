// Depth First Search
#include <stdio.h>

int a[10][10], f[10];

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
  int s[10];
  int source = 0, top = -1;
  int no_conn = 0, num;
  printf("\nEnter number of nodes:");
  scanf("%d", &num);
  read_adj(num);

  for (source = 0; source < num; source++)
  {
    for (int i = 0; i < num; i++)
    {
      f[i] = 0;
    }
    f[source] = 1;
    s[++top] = source;
    printf("\nNodes reachable by %d : %d\t", source, source);
    while (top != -1)
    {
      no_conn = 0;
      for (int j = 0; j < num; j++)
      {
        if (a[s[top]][j] == 1 && f[j] == 0)
        {
          printf("%d \t", j);
          s[++top] = j;
          f[j] = 1;
          no_conn = 1;
          break;
        }
      }
      if (no_conn == 0)
        top--;
    }
  }
}