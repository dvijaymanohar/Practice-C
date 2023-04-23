#include <stdio.h>
void printarr(int *a[]);
void printarr_usingptr(int *a[]);
int *a[5];   \\ A
main()
{
  int i1 = 4, i2 = 3, i3 = 2, i4 = 1, i5 = 0;   \\ B
  a[0] = &i1;         \\ C
  a[1] = &i2;
  a[2] = &i3;
  a[3] = &i4;
  a[4] = &i5;
  printarr(a);
  printarr_usingptr(a);
}
void printarr(int *a[])     \\ D
{
  printf("Address          Address in array           Value\n");
  
  for (int  j = 0; j < 5; j++)
  {
    printf("%16u             %16u                    %d\n", a[j], a[j], a[j]); \\E
  }
  
}
void printarr_usingptr(int *a[])
{
  int j = 0;
  printf("using pointer\n");
  
  for (j = 0; j < 5; j++)
  {
    printf("value of elements   %d %16lu %16lu\n", **a, *a, a);  \\ F
    a++;
  }
}

