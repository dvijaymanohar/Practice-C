#include <stdio.h>
#define SIZE    5
#define DEBUG   1

int main(void)
{
  int a[SIZE], i, x;
  void bubble(int *ptr, int n);
  int bsearch(int *ptr, int count, int x);
  printf("\nEnter the elements here :\n");
  
  for (i = 0; i < SIZE; i++)
  {
    scanf("%d", &a[i]);
  }
  
  bubble(a, SIZE);
#if DEBUG
  printf("\nSorted Elements\n");
  
  for (i = 0; i < SIZE; i++)
  {
    printf("%d\t", a[i]);
  }
  
#endif
  printf("\nEnter the element to search here:");
  scanf("%d", &x);
  i = bsearch(a, SIZE, x);
  
  if (-1 == i)
  {
    printf("\nElement was not there\n");
  }
  else
  {
    printf("The said element is at position %d\n\n", i);
  }
  
  return 0;
}

void bubble(int *ptr, int n)
{
  int i, j, temp;
  
  for (i = n - 1; i >= 0; i--)
    for (j = 1; j <= i; j++)
      if (ptr[j - 1] > ptr[j])
      {
        temp = ptr[j];
        ptr[j] = ptr[j - 1];
        ptr[j - 1] = temp;
      }
}

int bsearch(int *ptr, int n, int x)
{
  int Low = 0, High = n - 1, Mid;
  
  while (Low <= High)
  {
    Mid = (Low + High) / 2;
    
    if (ptr[Mid] > x) { High = Mid - 1; }
    else if (ptr[Mid] < x) { Low = Mid + 1; }
    else { return Mid; }
  }
  
  return -1;
}

