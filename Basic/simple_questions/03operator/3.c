#include<stdio.h>

main()
{
  int c1, c2, c3;
  printf("ENTER VALUES OF c1, c2 AND c3");
  scanf("%d%d%d", &c1.&c2, &c3);
  
  if ((c1 < c2) && (c1 < c3))
  {
    printf("\n c1 is less than c2 and c3");
  }
  
  if (!(c1 < c2))
  {
    printf("\n c1 is greater than c2");
  }
  
  if ((c1 < c2) || (c1 < c3))
  {
    printf("\n c1 is less than c2 or c3 or both");
  }
}

