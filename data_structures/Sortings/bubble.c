#include <stdio.h>
#include <stdlib.h>
#define VER1  0
#define VER2  1

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <number of the elments to sort>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  int size = atoi(argv[1]);
  int a[size], i;
  void bubble(int *ptr, int n);
  printf("\nEnter the elements here :\n");
  
  for (i = 0; i < size; i++) { scanf("%d", &a[i]); }
  
  bubble(a, size);
  printf("\nSorted Elements\n");
  
  for (i = 0; i < size; i++) { printf("%d\t", a[i]); }
  
  printf("\n\n");
  return 0;
}

#if VER1
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
#endif

#if VER2
void bubble(int *ptr, int n)
{
  int i, j, temp;
  
  for (i = 1; i < n; ++i)
    for (j = n - 1; j >= i; --j)
      if (ptr[j - 1] > ptr[j])
      {
        temp = ptr[j];
        ptr[j] = ptr[j - 1];
        ptr[j - 1] = temp;
      }
}
#endif
