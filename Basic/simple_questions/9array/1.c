#include <stdio.h>
main()
{
  int a[5]; \\A
  
  for (int i = 0; i < 5; i++)
  {
    a[i] = i; \\B
  }
  
  printarr(a);
}
void printarr(int a[])
{
  for (int i = 0; i < 5; i++)
  {
    printf("value in array %d\n", a[i]);
  }
}
