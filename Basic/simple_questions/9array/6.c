#include <stdio.h>
void printarr(int a[][]);
void printdetail(int a[][]);
void print_usingptr(int a[][]);
main()
{
  int a[3][2];  \\ A
  
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2 ; j++)
    {
      {
        a[i] = i;
      }
    }
    
  printdetail(a);
}
void printarr(int a[][])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
    {
      {
        printf("value in array %d\n", a[i][j]);
      }
    }
}
void printdetail(int a[][])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
    {
      {
        printf("value in array %d and address is %8u\n", a[i][j], &a[i][j]);
      }
    }
}
void print_usingptr(int a[][])
{
  int *b; \\ B
  b = a;    \\ C
  
  for (int i = 0; i < 6; i++)  \\ D
  {
    printf("value in array %d and address is %16lu\n", *b, b);
    b++; // increase by 2 bytes \\ E
  }
}
