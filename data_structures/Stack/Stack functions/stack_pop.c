/* Program to pop from the stack */

#include "stack.h"
#include <stdlib.h>

void *stack_pop(struct stack *ptr)
{
  //  void *out_ptr = NULL;
  if (ptr->stack_depth != 0)
  {
    ptr->stack_depth -= 1;
    //out_ptr = (void *)ptr->stack_array[ptr->stack_array];
    return ((void *)ptr->stack_array[ptr->stack_depth]);
  }
  else
  {
    return (NULL);
  }
}
