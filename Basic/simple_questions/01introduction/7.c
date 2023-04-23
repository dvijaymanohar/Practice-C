#include <stdio.h>
main()
{
  int i, n; //the
  scanf("%d", &n); for (i = 1; i < n; i = i + 1)
  {
    switch (i % 2) // statement A
    {
      case 0 : printf("the number %d is even \n", i); // statement B
        break;   // statement C
        
      case 1 : printf("the number %d is odd \n", i);
        break;
    }
  }
}
