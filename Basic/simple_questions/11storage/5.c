#include <stdio.h>
main()
{
  int  k = 10;
  {
    for (int  i = 0; i < 2; i++) \\ A
    {
      \\ B
      printf("value of i is %d\n", i); \\ C
    } \\ D
  }
  printf("the value of i is %d\n", i); \\ E
}
