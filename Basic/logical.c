/* Logical */
#include <stdio.h>
int main()
{
  int a = 1, b = 0;
  
  if (a || ++b)
  {
    printf("In first if a = %d, b = %d", a, b);
  }
  else
  {
    printf("In second if a = %d, b = %d", a, b);
  }
  
  return 0;
}
