#include <stdio.h>
#define SIZE  5
#define DEBUG 1
int main()
{
  int a[SIZE], i, key, rt;
  void bsort(int a[], int n);
  int bsearch(int a[], int n, int key);
  printf("\nEnter the elements here: ");
  
  for (i = 0; i <= SIZE - 1; i++) { scanf("%d", &a[i]); }
  
  bsort(a, SIZE);
  printf("\nSorted Elements are:\n");
  
  for (i = 0; i <= SIZE - 1; i++) { printf("%d\t", a[i]); }
  
  printf("\nElement to Search\n");
  
  do
  {
    rt = scanf("%d", &key);
    
    if (!rt) { printf("\nEnter an integer here:"); }
    
    while (getchar() != '\n');
  }
  while (!rt);
  
  if (DEBUG) { printf("\nCalling"); }
  
  rt = bsearch(a, SIZE, key);
  
  if (-1 == rt) { printf("\nElement was not in the array\n"); }
  else { printf("Element is existing at %d in the array", rt); }
  
  return 0;
}

void bsort(int *ptr, int n)
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

int bsearch(int *ptr, int n, int key)
{
  int mid, low = 0, high = (n - 1);
  
  if (DEBUG) { printf("\nHigh = %d\t, ptr[0] = %d\n", high, ptr[0]); }
  
  while (low < high)
  {
    mid = (low + high) / 2;
    
    if (key < ptr[mid]) { high = mid - 1; }
    
    if (DEBUG) { printf("\n%d", mid); }
    else if (key > ptr[mid]) { low = mid + 1; }
    else { return mid; }
  }
  
  return -1;
}


