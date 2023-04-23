#include <stdio.h>
int fact(int n);
long  old = 0;  \\E
long current = 0; \\F
main()
{
  int k = 4, i;
  long diff;
  i = fact(k);
  printf("The value of i is %d\n", i);
  diff = old - current;
  printf("stack overheads are %16lu\n", diff);
}
int fact(int n)
{
  int j;
  static int m = 0;
  
  if (m == 0) { old = (long) &j; }  \\A
  
  if (m == 1) { current = (long) &j; }  \\B
  
  m++;    \\C
  printf("the address of j and m is  %16lu %16lu\n", &j, &m); \\D
  
  if (n <= 0)
  {
    return (1);
  }
  else
  {
    return (n * fact(n - 1));
  }
}

