# include <stdio.h>
# include <stdlib.h>
# include "returnstructure.h"

void *mypush(int sizeofstack)
{
  struct datas *gan;
  int data, i;
  //  for(i = 0; i < sizeofstack; i++);
  //  {
  gan = malloc(sizeofstack * sizeof(struct datas *));
  //  }
  scanf("%d", &data);
  gan->num = data;
  printf("ji\n");
  return gan;
}
