#include <stdio.h>
main()
{
  \\ Block 1
  int  i = 10;  \\ A
  {
    \\ Block 2
    int i = 0;    \\ B
    
    for (i = 0; i < 2; i++)  \\ C
    {
      printf("value of i is %d\n", i);
    } \\ End of block 2
  }
  printf("the value of i is %d\n", i);   \\ D
} \\ End of block 1
