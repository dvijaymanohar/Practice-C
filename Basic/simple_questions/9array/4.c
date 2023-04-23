#include <stdio.h>
void printarr(int a[]);
void printdetail(int a[]);
void print_usingptr(int a[]);
main()
{
  int a[5];
  
  for (int i = 0; i < 5; i++)
  {
    a[i] = i;
  }
  
  print_usingptr(a);
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
void print_usingptr(int a[])
{
  int *b;
  b = a;
  
  for (int i = 0; i < 5; i++)
  {
    printf("value in array %d and address is %16lu\n", *b, b);
    b++;      // A
  }
}

