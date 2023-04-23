/* PROGRAM TO IMPLEMENT SELECTION SORT */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, min, pos, flag, i, j;
  int *a;
  printf("Enter the length of the array : ");
  scanf("%d", &n);
  a = malloc(n * sizeof(int));
  printf("Enter the elements of the array : ");
  
  for (i = 0; i < n; i++)
  {
    scanf("%d", (a + i));
  }
  
  for (i = 0; i < n - 1; i++)
  {
    min = a[i];
    flag = 0;
    
    for (j = i + 1; j < n; j++)
      if (min > a[j])
      {
        pos = j;
        min = a[j];
        flag = 1;
      }
      
    //swap
    if (flag == 1)
    {
      a[pos] = a[i];
      a[i] = min;
    }
  }
  
  printf("The sorted array is %d\n", i);
  
  for (i = 0; i < n; i++)
  {
    printf("%d\n", a[i]);
  }
  
  return 0;
}
