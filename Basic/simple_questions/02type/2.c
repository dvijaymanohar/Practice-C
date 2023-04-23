// the program gives maximum and minimum value of datatype
#include <stdio.h>
main()
{
  char i, j ;
  i = 1;
  
  while (i > 0) // A
  {
    j = i;  //  B
    i++;    //  C
  }
  
  printf("the maximum value of char is %d\n", j);
  printf("the value of  char after overflow is %d\n", i);
}
