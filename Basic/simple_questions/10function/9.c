#include <stdio.h>
void  f1(int *k)    // B
{
  *k = *k + 10; // C
}

main()
{
  int i;
  i = 0;
  printf("The value of i before call %d \n", i);
  f1(&i);     // A
  printf("The value of i after call %d \n", i);
}
