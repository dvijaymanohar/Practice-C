#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main()
{
  struct link *res;
  int  *a, *val;
  int *b;
  //  res = (struct link*)malloc(sizeof(struct link));
  res = link_create();
  
  if (res != NULL)
  {
    printf("link is  created\n");
  }
  else
  {
    printf("link is not created\n");
  }
  
  a = (int *)malloc(sizeof(int));
  printf("enter a data value\n");
  scanf("%d", a);
  val = (int *)link_first_insert(res, a);
  printf("\tfirst node:\t%d\n", *val);
  printf("enter a data value\n");
  b = (int *)malloc(sizeof(int));
  scanf("%d", b);
  val = (int *)link_last_insert(res, b);
  printf("\tlast insert node:\t%d\n", *val);
  return 0;
}

