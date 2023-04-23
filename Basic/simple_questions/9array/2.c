#include <stdio.h>
void printarr(int a[]);
main()
{
  int a[5];
  
  for (int i = 0; i < 5; i++)
  {
    a[i] = i;
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
void printdetail(int a[])
{
  for (int i = 0; i < 5; i++)
  {
    printf("value in array %d and address is %16lu\n", a[i], &a[i]);  \\ A
  }
}
