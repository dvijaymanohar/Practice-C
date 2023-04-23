/* FUNCTIONS FOR STACK OPERATIONS */

#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* PROGRAM TO CREATE A STACK */

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


/* PROGRAM TO PUSH DATA INTO THE STACK */

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


/* PROGRAM TO POP FROM THE STACK */

void *stack_pop(struct stack *ptr)
{
  if (ptr->stack_depth != 0)
  {
    ptr->stack_depth -= 1;
    return ((void *)ptr->stack_array[ptr->stack_depth]);
  }
  else
  {
    return (NULL);
  }
}


/* PROGRAM TO GET THE TOPMOST ELEMENT OF THE STACK */

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


/* PROGRAM TO PRINT THE DATA IN THE STACK */

void stack_print(struct stack *ptr, void (*func)(void *))
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
      func(ptr->stack_array[i]);
    }
  }
}


/* PROGRAM TO DESTROY THE STACK */

void stack_destroy(struct stack *ptr)
{
  free(ptr->stack_array);
  free(ptr);
}
