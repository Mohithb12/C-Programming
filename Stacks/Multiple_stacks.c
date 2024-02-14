// Multiple stacks

#include <stdio.h>
#include <stdlib.h>
#define stack_size 12
#define no_of_stacks 4

void push(int s[], int top[], int bound[], int i)
{
  int elem;
  if (top[i] == bound[i + 1])
  {
    printf("\nStack is full.");
    return;
  }
  printf("\nEnter element:");
  scanf("%d", &elem);
  top[i] = top[i] + 1;
  s[top[i]] = elem;
}

void pop(int s[], int top[], int bound[], int i)
{
  int elem;
  if (top[i] == bound[i])
  {
    printf("\n stack is empty.");
    return;
  }
  elem = s[top[i]];
  printf("\n %d is delted.", elem);
  top[i] = top[i] - 1;
}

void display(int s[], int top[], int bound[])
{
  int j, i;
  for (i = 0; i < no_of_stacks; i++)
  {
    printf("\n elments of stacks are:");
    if (top[i] == bound[i])
    {
      printf("Stack %d is in underflow condition.", i);
      continue;
    }
    for (j = bound[i] + 1; j <= top[i]; j++)
      printf("\n%d", s[j]);
  }
}

int main()
{
  int s[stack_size], top[no_of_stacks], bound[no_of_stacks], i, ch;
  for (i = 0; i <= no_of_stacks; i++)
  {
    top[i] = stack_size / no_of_stacks * i - 1;
    bound[i] = top[i];
  }

  while (1)
  {
    printf("\nEnter \n 1.push \n 2.pop \n 3.display \n 4.exit \n ");
    printf("Enter choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\nEnter stack no:");
      scanf("%d", &i);
      push(s, top, bound, i);
      break;
    case 2:
      printf("\nEnter stack no:");
      scanf("%d", &i);
      pop(s, top, bound, i);
      break;
    case 3:
      display(s, top, bound);
      break;
    default:
      exit(0);
    }
  }
}