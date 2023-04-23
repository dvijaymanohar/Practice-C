#define CUBE(x)  x*x*x  //A 
#include <stdio.h>
main()
{
  int k = 5;
  int j = 0;
  j = CUBE(k);    //B  j = k*k*k
  printf(“value of j is % d\n”, j); //C
}

