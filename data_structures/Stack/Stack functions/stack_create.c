/* Program to create a stack */

#include "stack.h"
#include <stdlib.h>
#include <string.h>

struct stack *stack_create(int size)
{
  struct stack *ptr;
  ptr = (struct stack *) malloc(sizeof(struct stack *));
  ptr->stack_maxsize = size;
  ptr->stack_depth = 0;
  ptr->stack_array = (void **) malloc(ptr->stack_maxsize * sizeof(void *));
  memset(ptr->stack_array, 0, (ptr->stack_maxsize * sizeof(void *)));
  return (ptr);
}
