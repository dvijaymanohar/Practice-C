/* PROGRAM TO IMPLEMENT BUBBLE SORT */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int flag, i, j, n;
  int *a;
  printf("Enter the length of the array : ");
  scanf("%d", &n);
  a = malloc(n * sizeof(int));
  printf("Enter the elements of the array : ");
  
  for (i = 0; i < n; i++)
  {
    scanf("%d", (a + i));
  }
  
  flag = 1;
  
  for (j = 0; j < (n - 1) && flag == 1; j++)
  {
    flag = 0;
    
    for (i = 0; i < (n - 1 - j); i++)
      if (a[i] > a[i + 1])
      {
        flag = 1;
        //swap
        a[i] = a[i] + a[i + 1];
        a[i + 1] = a[i] - a[i + 1];
        a[i] = a[i] - a[i + 1];
      }
  }
  
  printf("The sorted array is\n");
  
  for (i = 0; i < n; i++)
  {
    printf("%d\n", a[i]);
  }
  
  return 0;
}
