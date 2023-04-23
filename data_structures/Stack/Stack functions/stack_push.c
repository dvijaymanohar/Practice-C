/* Program to push the elements into the stack */

#include "stack.h"

int stack_push(struct stack *ptr, void *data_ptr)
{
  if (ptr->stack_depth < ptr->stack_maxsize)
  {
    ptr->stack_array[ptr->stack_depth] = data_ptr;
    ptr->stack_depth += 1 ;
    return 1;
  }
  else
  {
    return 0;
  }
}
