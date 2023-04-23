#include<stdio.h>

main()
{
  int a, b, c, d;
  printf("ENTER VALUES OF a,b, c, d");
  scanf("%d%d%d", &a, &b, &c);
  a  += b * c + d;
  printf("\n a = %d", a);
}
