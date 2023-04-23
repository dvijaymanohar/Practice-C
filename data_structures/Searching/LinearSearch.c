#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
int main(int argc, char *argv[])
{
  int size = atoi(argv[1]);
  int a[size], i, ret, x;
  int lsearch(int *ptr, int n, int x);
  
  if (argc != 2)
  {
    printf("\n\tInvalid No of arguments");
    return 0;
  }
  
  printf("\n\tEnter the elements here:");
  
  for (i = 0; i < size; i++)
  {
    scanf("%d", &a[i]);
  }
  
  printf("\n\tElements in the array are here:\n");
  
  for (i = 0; i < size; i++)
  {
    printf("%d\t", a[i]);
  }
  
  printf("\n\tEnter the element to search:");
  scanf("%d", &x);
  ret = lsearch(a, size, x);
  
  if (-1 == ret) { printf("\n\tElement was not existing\n"); }
  else { printf("\n\t Said element is at postion %d in the array\n\n", ret); }
  
  return 0;
}

int lsearch(int *ptr, int n, int x)
{
  int i;
  
  for (i = 0; i < n; i++)
    if (x == ptr[i]) { return i; }
    
  return -1;
}
