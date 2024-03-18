#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define days 3

struct dairy
{
  char *day;
  int date;
  char *desc;
};
typedef struct dairy *Plan;

Plan create()
{
  Plan t;
  t = (Plan)malloc(sizeof(struct dairy) * 7);
  if (t == NULL)
  {
    printf("Memory not allocated");
    exit(0);
  }
  return t;
}

void read(Plan cal)
{
  for (int i = 0; i < days; i++)
  {
    printf("\nEnter day:");
    cal[i].day = (char *)malloc(9);
    scanf("%s", cal[i].day);
    printf("Enter date:");
    scanf("%d", &cal[i].date);
    printf("Enter description of actvity:");
    cal[i].desc = (char *)malloc(40);
    scanf(" %[^\n]", cal[i].desc);
    cal[i].desc = (char *)realloc(cal[i].desc, strlen(cal[i].desc) + 1);
  }
}

void display(Plan cal)
{
  printf("\n****Activity description of %d days is***");
  for (int i = 0; i < days; i++)
  {
    printf("\nday:%s", cal[i].day);
    printf("\nDay:%d", cal[i].date);
    printf("\ndescription:%s", cal[i].desc);
  }
}

int main()
{
  Plan cal;
  cal = create();

  read(cal);
  display(cal);
}