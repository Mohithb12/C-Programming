#include <stdio.h>
#include <stdlib.h>

struct poly
{
  int cf, px, py, pz;
  struct poly *link;
};

typedef struct poly *P;

P getnode()
{
  P temp;
  temp = (P)malloc(sizeof(struct poly));
  if (temp == NULL)
  {
    printf("Memory not alocated");
    exit(0);
  }
  return temp;
}

void read_poly(P p1, int n)
{
  P temp, next;
  int i;
  for (i = 0; i < n; i++)
  {
    temp = getnode();
    printf("\n Enter cf,px,py,pz:");
    scanf("%d %d %d %d", &(temp->cf), &(temp->px), &(temp->py), &(temp->pz));
    next = p1->link;
    p1->link = temp;
    temp->link = next;
  }
}

void display(P head)
{
  P cur;
  printf("elem of poly:");
  cur = head->link;
  while (cur != head)
  {
    if (cur->cf > 0)
      printf("+%dx^%dy^%dz^%d", cur->cf, cur->px, cur->py, cur->pz);
    else
      printf("%dx^%dy^%dz^%d", cur->cf, cur->px, cur->py, cur->pz);
    cur = cur->link;
  }
  printf("\n");
}

P compare(P term, P p2)
{
  P cur;
  cur = p2->link;
  while (cur != p2)
  {
    if (cur->px == term->px && cur->py == term->py && cur->pz == term->pz)
      return cur;
    cur = cur->link;
  }
  return NULL;
}

void insert(P p3, int cf, int px, int py, int pz)
{
  P temp, next;
  temp = getnode();
  temp->cf = cf;
  temp->px = px;
  temp->py = py;
  temp->pz = pz;
  next = p3->link;
  p3->link = temp;
  temp->link = next;
}

P add_poly(P p1, P p2, P p3)
{
  P cur, next;
  next = p1->link;
  while (next != p1)
  {
    cur = compare(next, p2);
    if (cur == NULL)
    {
      insert(p3, next->cf, next->px, next->py, next->pz);
    }
    else
    {
      insert(p3, next->cf + cur->cf, next->px, next->py, next->pz);
      cur->cf = -999;
    }
    next = next->link;
  }

  cur = p2->link;
  while (cur != p2)
  {
    if ((cur->cf) != -999)
    {
      insert(p3, cur->cf, cur->px, cur->py, cur->pz);
    }
    cur = cur->link;
  }
}

int main()
{
  P p1, p2, p3;
  int m, n;
  p1 = getnode();
  p1->link = p1;
  printf("\nEnter terms of poly:");
  scanf("%d", &n);
  read_poly(p1, n);
  display(p1);
  p2 = getnode();
  p2->link = p2;
  printf("\nEnter terms of poly");
  scanf("%d", &n);
  read_poly(p2, n);
  display(p2);
  p3 = getnode();
  p3->link = p3;
  printf("\npolynomial addition:");
  add_poly(p1, p2, p3);
  display(p3);
}