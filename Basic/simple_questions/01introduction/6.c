#include <stdio.h>
main()
{
  int i, n; //the
  scanf("%d", &n);
  i = 0;
  
  do                   // statement A
  {
    printf("the numbers are %d \n", i);
    i = i + 1;
  }
  while (i < n)  ;
}
