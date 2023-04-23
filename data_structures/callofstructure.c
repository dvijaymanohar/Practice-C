# include <stdio.h>
# include <stdlib.h>
# include "returnstructure.h"

int main()
{
  printf("Enter the Max. size of stack");
  scanf("%d", &sizeofstack);
  struct datas *gan1;
  int i;
  gan1 = (struct datas *)malloc(sizeofstack * sizeof(struct datas *));
  
  for (i = 0; i < sizeofstack; i++)
  {
    (&gan1[i])->num = i + 1;
  }
  
  for (i = 0; i < sizeofstack; i++)
  {
    printf("%d is the %d element\n", (&gan1[i])->num, i + 1);
  }
  
  return 0;
}
