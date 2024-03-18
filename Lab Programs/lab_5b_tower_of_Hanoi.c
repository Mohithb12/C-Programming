#include <stdio.h>

void hanoi(int n, char S, char T, char D)
{
  if (n == 0)
  {
    return;
  }
  hanoi(n - 1, S, D, T);
  printf("\nmove disc %d from %c to %c", n, S, D);
  hanoi(n - 1, T, S, D);
}

int main()
{
  int n = 3;
  hanoi(n, 'A', 'B', 'C');
}