/* Assignment */
#include <stdio.h>
int main()
{
  int a = 1, c = 1, e = 1;
  float b = 1.5, d = 1.5, f = 1.5;
  a += b += c += d += e += f;
  printf("\n value of a : %d ", a);
  printf("\n value of b : %f ", b);
  printf("\n value of c : %d ", c);
  printf("\n value of d : %f ", d);
  printf("\n value of e : %d ", e);
  printf("\n value of f : %f ", f);
  return 0;
}
