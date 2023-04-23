#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/* CREATING THE STACK WITH THE FIELD MEMORY ALLOCATED */

struct stack *stack_create(int sizeofstack)
{
  struct stack *mystack;
  mystack = malloc(sizeof(struct stack));
  mystack->stack_array = (void **)malloc(sizeofstack * sizeof(void *));
  //  for(i = 0; i < sizeofstack; i++)
  //  {
  //    mystack->stack_array[i] = (void *)malloc(sizeof(void *));
  //  }
  mystack->stack_maxsize = sizeofstack;
  mystack->stack_depth = 0;
  return mystack;
}

/*PUSHING THE ELEMENT INTO THE STACK */

int stack_push(struct stack *mystack, void *element)
{
  if (mystack->stack_depth < mystack->stack_maxsize)
  {
    mystack->stack_array[mystack->stack_depth] = element;
    mystack->stack_depth = mystack->stack_depth + 1;
    return 1;
    //    free(element);
  }
  
  return 0;
}

/* POPPING OUT AN ELEMENT FORM THE STACK AND RETURNING IT */

void *stack_pop(struct stack *mystack)
{
  void *element;
  
  if ((mystack->stack_depth - 1) >= 0)
  {
    mystack->stack_depth = mystack->stack_depth - 1;
    element = mystack->stack_array[mystack->stack_depth];
    return element;
  }
  else
  {
    return NULL;
  }
}

/* RETURNING THE TOP MOST ELEMENT IN THE STACK */

void *stack_top(struct stack *mystack)
{
  void *element;
  
  if (mystack->stack_depth != 0)
  {
    element = mystack->stack_array[mystack->stack_depth - 1];
    return element;
  }
  else
  {
    return NULL;
  }
}

void stack_print(struct stack *mystack, void (*printing)(void *))
{
  int i;
  
  for (i = mystack->stack_depth - 1; i >= 0; i--)
  {
    printing(mystack->stack_array[i]);
  }
}

void stack_destroy(struct stack *mystack)
{
  free(mystack->stack_array);
  free(mystack);
}


