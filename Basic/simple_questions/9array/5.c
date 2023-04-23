#include <stdio.h>
void printarr(int a[]);
void printdetail(int a[]);
void print_usingptr_a(int a[]);
main()
{
  int a[5];
  int *b;
  int *c;
  
  for (int i = 0; i < 5; i++)
  {
    a[i] = i;
  }
  
  printarr(a);
  *b = 2;   \\ A
  b++;    \\ B
  *b = 4;   \\ C
  b++;
  *b = 6;   \\ D
  b++;
  *b = 8;   \\ E
  b++;
  *b = 10;
  b++;
  *b = 12;
  b++;
  a = c; //error  \\J
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
    printf("value in array %d and address is %16lu\n", a[i], &a[i]);
  }
}

void print_usingptr_a(int a[])
{
  for (int i = 0; i < 5; i++)
  {
    printf("value in array %d and address is %16lu\n", *a, a);  \\ F
    a++; // increase by 2 bytes   \\ G
  }
}

