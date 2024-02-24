/* 
Basic linked list program
->insert->front
->insert->rear
->delete->front
->delete->rear
->display
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int info;
  struct node *link;
};

struct node *getnode()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("memory not allocated");
    exit(0);
  }
  return temp;
}

struct node *insert_front(struct node *first, int elem)
{
  struct node *temp;
  temp = getnode();
  temp->info = elem;
  temp->link = first;
  // if (first == NULL)/*    Not necessary as we are
  // {                       inserting to the front just
  //   return temp;          intitalize temp to first
  // }
  // temp->link = first;
  // first = temp;*/
  return temp;
}

struct node *insert_rear(struct node *first, int elem)
{
  struct node *temp, *cur, *prev;
  temp = getnode();
  temp->info = elem;
  temp->link = NULL;
  if (first == NULL)
  {
    return temp;
  }
  cur = first;
  prev = NULL;
  while (cur != NULL)
  {

    prev = cur;
    cur = cur->link;
  }
  prev->link = temp;
  return first;
}

struct node *delete_front(struct node *first)
{
  struct node *next;
  if (first == NULL)
  {
    printf("Linked list is empty.");
    return NULL;
  }
  printf("Elem %d is deleted", first->info);
  next = first->link;
  free(first); // free node after deletion
  return next;
}

struct node *delete_rear(struct node *first)
{
  struct node *prev, *cur;
  if (first == NULL)
  {
    printf("SLL is empty");
    return NULL;
  }
  if (first->link == NULL)
  {
    printf("%d is deleted", first->info);
    free(first);
    return NULL; // return null here not first
  }
  cur = first;
  prev = NULL;
  while (cur->link != NULL) // compare cur->link not cur because
  {                         // the previos node link of which is to be deleted
    prev = cur;             // should be made NULL
    cur = cur->link;
  }
  prev->link = NULL;
  printf("deleted elem is %d", cur->info);
  free(cur);
  return first;
}

void display(struct node *first)
{
  struct node *cur;
  cur = first;
  printf("\n Elements of linked list are:");
  if (cur == NULL)
  {
    printf("SLL is empty");
    return;
  }
  while (cur != NULL)
  {
    printf("\t %d \t", cur->info);
    cur = cur->link;
  }
}

int main()
{
  struct node *first = NULL;
  int elem, ch;
  while (1)
  {
    printf("\nEnter \n 1.insert_front\n 2. Insert_rear \n 3.delete_front \n 4.delet_rear \n 5.display");
    printf("\n Enter choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case (1):
      printf("\nEnter element to be inserted:");
      scanf("%d", &elem);
      first = insert_front(first, elem);
      break;
    case (2):
      printf("\nEnter element to be inserted:");
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
      printf("program exited");
      exit(0);
    }
  }
}
