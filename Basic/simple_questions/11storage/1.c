#include <stdio.h>
int g = 10; \\ A
main()
{
  int i = 0; \\ B
  void f1();  \\ C
  f1();   \\ D
  printf(" after first call \n");
  f1();   \\ E
  printf("after second  call \n");
  f1();   \\ F
  printf("after third  call \n");
}
void f1()
{
  static int k = 0; \\ G
  int j = 10;   \\ H
  printf("value of k %d j %d", k, j);
  k = k + 10;
}

