// the program gives maximum and minimum value of datatype
#include <stdio.h>
main()
{
  int i, j ; // A
  i = 1;
  
  while (i > 0)
  {
    j = i;
    i++;
  }
  
  printf("the maximum value of integer is %d\n", j);
  printf("the value of  integer after overflow is %d\n", i);
}


