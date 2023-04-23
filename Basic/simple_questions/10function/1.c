#include <stdio.h>
int add(int x, int y)   //A
{
  int z;    //B
  z = x + y;
  return (z); //C
}
main()
{
  int i, j, k;
  i = 10;
  j = 20;
  k = add(i, j);    //D
  printf(“The value of k is % d\n”, k); //E
}
