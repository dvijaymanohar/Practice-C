#include <stdio.h>
#define VAL 40; //A
#undef  VAL     //B
#define  VAL 40 //C

main()
{
  printf(“ % d\n”, VAL); //D
}

