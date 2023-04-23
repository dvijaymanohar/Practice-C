#include <stdio.h>
#include<stdlib.h>

main()
{
  int i,  n ;
  int *num, complexity = 0 ;
  printf("how many elements u want\n");
  scanf("%d", &n);
  num  = malloc(n * sizeof(int));
  printf("\tenter a elements\n");
  
  for (i = 0; i < n ; i++)
  {
    scanf("%d", &num[i]);
  }
  
  bubble(num, i, complexity);
}

bubble(int *num, int m, int complexity)
{
  int i, j, t;
  
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (num[j] > num[i])
      {
        t = num[i];
        num[i] = num[j];
        num[j] = t ;
        complexity++;
      }
    }
  }
  
  printf("\tBUBBLE SORT IS:\n");
  
  for (i = 0; i < m; i++)
  {
    printf("%d\t", num[i]);
  }
  
  printf("\tMY PROGRAMM COMPLEXITY IS :%d\n", complexity);
}
