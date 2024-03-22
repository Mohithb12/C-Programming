#include <stdio.h>
#include <stdlib.h>
struct node
{
  int info;
  struct node *llink, *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
  NODE x;
  x = (NODE)malloc(sizeof(struct node));
  if (x == NULL)
  {
    printf("Memory not alloctaed");
    exit(0);
  }
}

void preorder_iter(NODE root)
{
  NODE cur, s[50];
  int top = -1;
  if (root == NULL)
  {
    printf("\nBST is empty");
    return;
  }
  cur = root;
  for (;;)
  {
    while (cur != NULL)
    {
      printf("%d \n", cur->info);
      s[++top] = cur;
      cur = cur->llink;
    }
    if (top != -1)
    {
      cur = s[top--];
      cur = cur->rlink;
    }
    else
      return;
  }
}

NODE insert(NODE root, int elem)
{
  NODE temp, cur = root, prev;
  temp = getnode();
  temp->info = elem;
  temp->rlink = temp->llink = NULL;
  if (cur == NULL)
  {
    return temp;
  }
  while (cur != NULL)
  {
    prev = cur;
    if (elem > cur->info)
      cur = cur->rlink;
    else
      cur = cur->llink;
  }
  if (elem > prev->info)
  {
    prev->rlink = temp;
  }
  else
    prev->llink = temp;

  return root;
}

int main()
{
  NODE root = NULL;
  int ch, elem;

  while (1)
  {
    printf("Enter 1 to insert and 2 display:");
    scanf("%d", &ch);
    if (ch == 1)
    {
      printf("Enter elem:");
      scanf("%d", &elem);
      root = insert(root, elem);
    }
    else if (ch == 2)
      preorder_iter(root);
    else
      exit(0);
  }
}