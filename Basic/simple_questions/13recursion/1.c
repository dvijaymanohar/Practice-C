#include <stdio.h>
int add(int pk, int pm);
main()
{
  int k, i, m;
  m = 2;
  k = 3;
  i = add(k, m);
  printf("The value of addition is %d\n", i);
}
int add(int pk, int pm)
{
  if (pm == 0) { return (pk); }   \\ A
  else { return (1 + add(pk, pm - 1)); }  \\ B
}
