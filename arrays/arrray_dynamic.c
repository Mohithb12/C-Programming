#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *arr;
  int n;
  printf("Enter n:");
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);
  if (arr == NULL)
    printf("\nMemorey not allocated");
  else
    printf("\nMemory allocated");

  free(arr);
}