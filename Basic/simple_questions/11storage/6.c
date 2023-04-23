#include <stdio.h>
#include <malloc.h>
main()
{
  int  *base;  \\ A
  int i;
  int cnt = 0;
  int sum = 0;
  printf("how many integers you have to store \n");
  scanf("%d", &cnt);   \\ B
  base = (int *)malloc(cnt * sizeof(int));  \\ C
  printf("the base of allocation is %16lu \n", base);  \\ D
  
  if (!base) \\ E
    printf("unable to allocate size \n");
  else
  {
    for (int j = 0; j < cnt; j++)    \\ F
      *(base + j) = 5;
  }
  
  sum = 0;
  
  for (int j = 0; j < cnt; j++)     \\ G
    sum = sum + *(base + j);
    
  printf("total sum is %d\n", sum);
  free(base);    \\ H
  printf("the base of allocation is %16lu \n", base);
  base = (int *)malloc(cnt * sizeof(int));
  printf("the base of allocation is %16lu \n", base);
  base = (int *)malloc(cnt * sizeof(int));   \\ I
  printf("the base of allocation is %16lu \n", base);
  base = (int *)calloc(10, 2);        \\ H
  printf("the base of allocation is %16lu \n", base);
}

