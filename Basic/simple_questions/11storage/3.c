#include <stdio.h>
main()
{
  register int  i = 0;  \\ A
  
  for (i = 0; i < 2; i++)
  {
    printf("value of i is %d\n", i);
  }
}

