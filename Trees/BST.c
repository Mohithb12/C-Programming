#include <stdio.h>
#include <stdlib.h>
struct node
{
  int info;
  struct node *rlink, *llink;
};

typedef struct node *NODE;

NODE getnode()
{
  NODE x;
  x = (NODE)malloc(sizeof(struct node));
  if (x == NULL)
  {
    printf("Memory not allocated.");
    exit(0);
  }
  return x;
}

NODE insert(NODE root, int item)
{
  NODE temp, cur, prev;
  temp = getnode();
  temp->rlink = temp->llink = NULL;
  temp->info = item;
  if (root == NULL)
  {
    return temp;
  }
  cur = root;
  prev = NULL;
  while (cur != NULL)
  {
    prev = cur;
    if (cur->info > item)
      cur = cur->llink;
    else
      cur = cur->rlink;
  }
  if (item > prev->info)
  {
    prev->rlink = temp;
  }
  else
    prev->llink = temp;

  return root;
}

void preorder(NODE root)
{
  if (root == NULL)
  {
    return;
  }
  printf("\t%d", root->info);
  preorder(root->llink);
  preorder(root->rlink);
}

void postorder(NODE root)
{
  if (root == NULL)
  {
    return;
  }
  postorder(root->llink);
  postorder(root->rlink);
  printf("\t %d", root->info);
}

void inorder(NODE root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->llink);
  printf("\t%d", root->info);
  inorder(root->rlink);
}

int main()
{
  NODE root = NULL;
  int ch, elem;
  while (1)
  {
    printf("\nEnter \n 1.insert \n2.Preorder traversal \n3.Postorder traversal \n 4.Inorder traversal \nEnter choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case (1):
      printf("Enter element:");
      scanf("%d", &elem);
      root = insert(root, elem);
      break;
    case (2):
      printf("preorder of BST is:");
      preorder(root);
      break;
    case (3):
      printf("postorder of BST is:");
      postorder(root);
      break;
    case (4):
      printf("inorder of BST is:");
      inorder(root);
      break;
    default:
      exit(0);
    }
  }
  return 0;
}
