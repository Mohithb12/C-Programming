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
    printf("Memory not allocated");
    exit(0);
  }
  return x;
}

NODE insert_front(NODE first, int item)
{
  NODE temp;
  temp = getnode();
  temp->info = item;
  temp->rlink = temp->llink = NULL;
  if (first == NULL)
  {
    return temp;
  }
  // temp->rlink=first->llink;
  first->llink = temp;
  temp->rlink = first;
  return temp;
}
/*
       or
NODE insert_front(NODE first,int item)
{
  NODE temp;
  temp=getnode();
  temp->rlink=temp->llink=NULL;
  if(first!=NULL)
   first->llink=temp;
  return temp;
 }
*/

NODE insert_rear(NODE first, int elem)
{
  NODE temp, cur, prev;
  temp = getnode();
  temp->rlink = temp->llink = NULL;
  temp->info = elem;
  if (first == NULL)
  {
    return temp;
  }
  cur = first;
  prev = NULL;
  while (cur != NULL)
  {
    prev = cur;
    cur = cur->rlink;
  }
  temp->llink = prev;
  prev->rlink = temp;
  return first;
}

NODE delete_front(NODE first)
{
  NODE next;
  if (first == NULL)
  {
    printf("\nDLL is empty");
    return NULL;
  }
  else if (first->rlink == NULL)
  {
    printf("\ndeleted element is %d.", first->info);
    free(first);
    return NULL;
  }
  next = first->rlink;
  next->llink = NULL;
  printf("Deleted element is %d", first->info);
  free(first);
  return next;
}

NODE delete_rear(NODE first)
{
  NODE cur, prev;
  if (first == NULL)
  {
    printf("\nDLL is empty.");
    return NULL;
  }
  else if (first->rlink == NULL)
  {
    printf("Deleted element is %d", first->info);
    free(first);
    return NULL;
  }
  cur = first;
  prev = NULL;
  while (cur->rlink != NULL)
  {
    prev = cur;
    cur = cur->rlink;
  }
  printf("Deleted element is %d", cur->info);
  prev->rlink = NULL;
  free(cur);
  return first;
}

void display(NODE first)
{
  NODE cur;
  cur = first;
  if (first == NULL)
  {
    printf("\nDLL is empty.");
    return;
  }
  printf("DLL elements:");
  while (cur != NULL)
  {
    printf("%d\t", cur->info);
    cur = cur->rlink;
  }
}

int main()
{
  NODE first = NULL;
  int elem, ch;
  while (1)
  {
    printf("\nEnter 1.insert_fron \n 2.insert_rear\n 3.delete_front \n 4.delete_rear \n 5.display");
    printf("\nEnter the choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case (1):
      printf("\nEnter elem:");
      scanf("%d", &elem);
      first = insert_front(first, elem);
      break;
    case (2):
      printf("\nEnter elem:");
      scanf("%d", &elem);
      first = insert_rear(first, elem);
      break;
    case (3):
      first = delete_front(first);
      break;
    case (4):
      first = delete_rear(first);
      break;
    case (5):
      display(first);
      break;
    default:
      exit(0);
    }
  }
}
