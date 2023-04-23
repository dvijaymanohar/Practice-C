/* PROGRAM TO PRINT THE DATA IN THE STACK */

#include <stdio.h>
#include "stack.h"

void stack_print(struct stack *ptr)
{
  int i;
  
  if (ptr->stack_depth == 0)
  {
    printf("Stack is empty\n");
  }
  else
  {
    i = ptr->stack_depth;
    
    for (i -= 1; i >= 0; i--)
    {
      printf("%d\n", *(int *)(ptr->stack_array[i]));
    }
  }
}
