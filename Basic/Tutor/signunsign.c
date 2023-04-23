#include <stdio.h>

int main()
{
  int i;
  int arr[5] = {0, 1, 2, 3, 4};
  
  for (i = -1; i < (signed)(sizeof(arr) / sizeof(int) - 1); i++)
  {
    printf("%x\n", arr[i + 1]);
  }
  
  return 0;
}
