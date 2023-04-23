#include <stdio.h>
main()
{
  int i, n; //the
  scanf("%d", &n);
  
  for (i = 0; i < n; i = i + 1) // statement A
  {
    printf("the numbers are %d \n", i); // statement B
  }
}
