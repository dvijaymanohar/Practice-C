#include <stdio.h>

main()
{
  int i, a[20], n;
  printf("enter size of array");
  scanf("%d", &n);
  printf("\tenter a elements\n");
  
  for (i = 0; i < n ; i++)
  {
    scanf("%d", &a[i]);
  }
  
  bubble(a, i);
}

bubble(int a[], int m)
{
  int i, j, t;
  
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (a[j] > a[i])
      {
        t = a[i];
        a[i] = a[j];
        a[j] = t ;
      }
    }
  }
  
  printf("\tBUBBLE SORT IS:\n");
  
  for (i = 0; i < m; i++)
  {
    printf("%d\t", a[i]);
  }
}
