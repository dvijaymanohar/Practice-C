/* PROGRAM TO GET THE TOPMOST ELEMENT OF THE STACK */

#include "stack.h"
#include <stdlib.h>

void *stack_top(struct stack *ptr)
{
  int i;
  
  if (ptr->stack_depth != 0)
  {
    i = ptr->stack_depth;
    i -= 1;
    return ((void *)ptr->stack_array[i]);
  }
  else
  {
    return (NULL);
  }
}
