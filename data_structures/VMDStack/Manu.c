#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  void *Ptr = malloc(4);
  Ptr = (void *)5;
  printf("\n\tThe content of the pointer : %d\n", (int *)Ptr);
  return 0;
}
