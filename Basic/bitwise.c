/* Bitwise */
#include <stdio.h>

int main()
{
  unsigned int count, x;
  printf("\n Enter the value : ");
  scanf("%d", &x);
  
  for (count = 0; x != 0; x >>= 1)
  {
    if (x & 1)
    {
      count++;
    }
  }
  
  printf("The count is : %d", count);
  return 0;
}
