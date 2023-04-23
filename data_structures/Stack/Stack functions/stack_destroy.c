/* PROGRAM TO DESTROY THE STACK */

#include "stack.h"

void stack_destroy(struct stack *ptr)
{
  free(ptr->stack_array);
  free(ptr);
}
