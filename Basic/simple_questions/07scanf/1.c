#include <stdio.h>
main()
{
  int i = 0;
  int k, j = 10;
  i = scanf("%d%d%d", &j, &k, &i);
  printf("total values inputted %d\n", i);
  printf("The input values %d %d\n", j, k);
}
