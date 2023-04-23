#include <stdio.h>
main()
{
  int i;
  void (int *k)     // D
  i = 0;
  printf(“ The value of i before call % d \n”, i);
  f1(&i);     // A
  printf(“ The value of i after call % d \n”, i);
}
void (int *k)     // B
{
  *k = *k + 10; // C
}

