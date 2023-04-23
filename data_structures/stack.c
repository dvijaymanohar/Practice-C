#include<stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

//-------------------------------------------------------------------------------------------------------------------------------------------------
struct stack *stack_create(int size)  //function prototype
{
  struct stack *node ;
  node = (struct stack *)malloc(sizeof(struct stack)) ;  // create a memory for node         /* STACK CREATION */
  node -> stack_maxsize = size ;
  node -> stack_depth = 0 ;       // initially depth is zero
  node->stack_array = (void **)malloc(node->stack_maxsize * sizeof(int)); // create a memory for array of pointer
  memset(node->stack_array, (node->stack_maxsize) * sizeof(int), 0);
  return node;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------

int stack_push(struct stack *node, void *val)    // function prototype
{
  if (node -> stack_maxsize == node -> stack_depth) // cheak stack max size and depth of stack equal or not
  {
    return 0 ;
  }
  else                                                              /* PUSU OPERATION */
  {
    node->stack_array[node->stack_depth] = val ;
    node->stack_depth++;
    return 1 ;
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------

void *stack_pop(struct stack *node) // function proto type
{
  if (node->stack_depth == 0)
  {
    return NULL;
  }                                                                     /* POP OPERATION */
  else
  {
    node->stack_depth-- ;
    return (node->stack_array[node->stack_depth]);
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------

void *stack_top(struct stack *node)  // function prototype
{
  if (node->stack_depth == 0)
  {
    return NULL ;                                                     /* TOP OPERATION */
  }
  else
  {
    return (node->stack_array[node->stack_depth - 1]);
  }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------

void stack_print(struct stack *node)   // function prototype
{
  if (node->stack_depth == 0)
  {
    printf("\tNO ELEMENTS\n");                                       /* PRINT STACK ELEMENTS */
  }
  else
    do
    {
      node->stack_depth-- ;
      printf("\tcurrent elements :\t%d\n", *(int *)(node->stack_array[(node->stack_depth)]));
    }
    while (node->stack_depth != 0);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------


void stack_destroy(struct stack *node) // function proto type
{
  free(node);
  free(node->stack_array);
}


