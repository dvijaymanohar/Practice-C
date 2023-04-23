/* STACK MAIN */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//-------------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])  // passing the arguments
{
  struct stack *res;
  int  a, b, i = 0, n;                                              /* VARIABLE DECLARATION */
  int *str ;
  void *p;
  void *pop, *top ;
  res = (struct stack *)malloc(sizeof(struct stack)); //  allocate memoty for structer pointer variable
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  a = atoi(argv[1]);       // convert asci to integer
  res = stack_create(a);
  
  if (res->stack_maxsize == a)    // cheaking stack created or not
  {
    printf("\tstack is created :\n");                                      /*  STACK CREATION */
  }
  else
  {
    printf("\tstack is not created :\n");
  }
  
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  
  while (1)
  {
    str = (int *)(malloc(sizeof(int)));
    printf("\tenter elements\n");
    scanf("%d", str);
    
    if (*str == 0)
    {
      break ;
    }
    
    b  =  stack_push(res, (void *)str);
    
    if (b == 0)
    {
      printf("\tstack over flow  :\n");                                     /* PUSH OPERATION */
    }
  }
  
  stack_print(res);
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  
  do
  {
    pop = stack_pop(res);
    
    //    printf("\tpopped element  :\t%d \n", pop); // print poping element
    
    if ((int *)pop == 2)
    {
      pop =  res->stack_array[res->stack_depth];   /* POP OPERATION */
      printf("\tpopped element  :\t%d \n", pop); // print poping element
      break ;
    }
  }
  while (res->stack_depth != 0);
  
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  top = stack_top(res);
  
  if ((int *)top  == NULL)  // cheak and print top of the stack element
  {
    printf("\tno elements in stack :");                /*TOP OPERATION */
  }
  else
  {
    printf("\ttop of the element :\t%d\n", res->stack_array[res->stack_depth - 1]);
  }
  
  //------------------------------------------------------------------------------------------------------------------------------------------------
  //  stack_print( res );                                  /*PRINT CURRENT ELEMENTS IN STACK */
  //------------------------------------------------------------------------------------------------------------------------------------------------
  stack_destroy(res);                                    // destroy stack
  return 0;
}

