#include <stdio.h>
main()
{
  int i, j, big; //variable declaration
  scanf("%d%d", &i, &j); big = i;
  
  if (big < j)  // statement A
  {
    // C
    big = j;      // Part Z , then part
  }     // D
  
  printf("biggest of two numbers is %d \n", big);
  
  if (i < j) // statement B
  {
    big = j;   // Part X
  }
  else
  {
    big = i;   // Part Y
  }
  
  printf("biggest of two numbers(using else) is %d \n", big);
}
