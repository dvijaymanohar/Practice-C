#include <stdio.h>
int i = 0;  //Global variable
main()
{
  int j;    // local variable in main
  void f1(void)  ;
  i = 0;
  printf("value of i in main %d\n", i);
  f1();
  printf("value of i after call%d\n", i);
}
void f1(void)
{
  int k;    // local variable for f1.
  i = 50;
}
