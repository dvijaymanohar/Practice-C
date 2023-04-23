#include <stdio.h>
main()
{
  printf(“A\n”);    //A
#line100     //H
  printf(“B\n”);    //B
  printf(“C FILE % s  LINE % d\n”, __FILE__, __LINE__);   //C
#line200     //K
  printf(“D\n”);    //D
  printf(“E\n”);    //E
}

