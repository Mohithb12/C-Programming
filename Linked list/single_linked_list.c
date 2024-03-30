/*
Single Linked List basics
 1.insert front
 2.insert rer
 3.delete front
 4.delete rear
 5.display
 functions
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int info;
  struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
  NODE temp;
  temp = (NODE)malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("memory not allocated");
    exit(0);
  }
  return temp;
}

NODE insert_front(NODE first, int elem)
{
  NODE temp, cur;
  temp = getnode();
  temp->info = elem;
  temp->link = NULL;
  /*(if (first == NULL)
  {
    return temp;       // not needed
  })*/
  temp->link = first;
  return temp;
}

NODE insert_rear(NODE first, int elem)
{
  NODE temp;
  temp = getnode();
  temp->info = elem;
  temp->link = NULL;
  if (first == NULL)
  {
    return temp;
  }
  NODE cur = first;
  while (cur->link != NULL)
  {
    cur = cur->link;
  }
  cur->link = temp;
  return first;
}

NODE del_front(NODE first)
{
  NODE next;
  if (first == NULL)
  {
    printf("SLL is empty");
    return NULL;
  }
  next = first->link;
  printf("delted elem is %d", first->info);
  free(first);
  return next;
}

NODE del_rear(NODE first)
{
  NODE prev, cur;
  if (first == NULL)
  {
    printf("SLL is empty");
    return first;
  }
  else if (first->link == NULL)
  {
    printf("Deleted elem is %d", first->link);
    free(first);
    return NULL;
  }
  cur = first;
  while (cur->link != NULL)
  {
    prev = cur;
    cur = cur->link;
  }
  prev->link = NULL;
  printf("%d is deleted", cur->info);
  free(cur);
  return first;
}

void display(NODE first)
{
  NODE cur = first;
  printf("Elments of sll");
  if (first == NULL)
  {
    printf("\nSLL is empty");
    return;
  }
  while (cur != NULL)
  {
    printf("\n %3d ", cur->info);
    cur = cur->link;
  }
}

NODE concat(NODE first, NODE second)
{
  NODE cur, res = NULL;
  cur = first;
  while (cur != NULL)
  {
    res = insert_rear(res, cur->info);
    cur = cur->link;
  }
  cur = second;
  while (cur != NULL)
  {
    res = insert_rear(res, cur->info);
    cur = cur->link;
  }
}

NODE rev(NODE first)
{
  NODE cur, rev = NULL;
  cur = first;
  while (cur != NULL)
  {
    rev = insert_front(rev, cur->info);
    cur = cur->link;
  }
}

int main()
{
  NODE first = NULL;
  int ch, elem;

  while (1)
  {
    printf("\n Enter  \n 1.insert front \n 2.insert rer \n 3.delete front \n 4.delete rear \n 5.display \n ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter elem to insert:");
      scanf("%d", &elem);
      first = insert_front(first, elem);
      break;
    case 2:
      printf("Enter elem to insert:");
      scanf("%d", &elem);
      first = insert_rear(first, elem);
      break;
    case 3:
      first = del_front(first);
      break;
    case 4:
      first = del_rear(first);
      break;
    case 5:
      display(first);
      break;
    default:
      exit(0);
    }
  }
}