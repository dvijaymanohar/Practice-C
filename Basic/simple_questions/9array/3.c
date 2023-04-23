#include <stdio.h>
void printarr(int a[]);
void printdetail(int a[]);
main()
{
  int a[5];
  
  for (int i = 0; i < 5; i++)
  {
    a[i] = i;
  }
  
  printdetail(a);
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
    printf("value in array %d and address is %8u\n", a[i], &a[i]);
  }
}
void print_usingptr(int a[])  \\ A
{
  int *b; \\ B
  b = a;    \\ C
  
  for (int i = 0; i < 5; i++)
  {
    printf("value in array %d and address is %16lu\n", *b, b);  \\ D
    b = b + 2;  \\E
  }
}
