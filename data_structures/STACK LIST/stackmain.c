/* STACK MAIN */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//-------------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])  // passing the arguments
{
  struct stack *res;
  int  a, b  ;                                             /* VARIABLE DECLARATION */
  int i = 0 ;
  int  str[10];
  //  void *p;
  void *pop, *top ;
  res = (struct stack *)malloc(sizeof(struct stack)); // create memoty for structer pointer variable
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
    printf("\tenter elements\n");
    scanf("\t%d", &str[i]);
    b = stack_push(res, (void *)&str[i]);
    
    if (b == 1)
    {
      printf("pushed elements :%d\n", *(int *)res->stack_array[res->stack_depth - 1]);
    }
    
    if (b == 0) // cheak stack full or not
    {
      printf("\tstack over flow  :");                                     /* PUSH OPERATION */
    }
    
    while (getchar() != '\n');
    
    printf("do u want to push elements further(y/n): ");
    //scanf("%d " );
    
    if (getchar() != 'y')
    {
      break;
    }
    
    i++;
  }
  
  //stack_print(res );
  
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  
  do
  {
    pop = stack_pop(res);
    
    //printf("\tpopped element  :\t%d \n", *(int*)pop); // print poping element
    if (*(int *)pop == 1)
    {
      printf("\tpopped element  :\t%d \n", *(int *)pop); // print poping element
      break;
    }
  }
  while (res->stack_depth != 0);
  
  //-------------------------------------------------------------------------------------------------------------------------------------------------
  top = stack_top(res);
  
  if (top  == NULL)   // cheak and print top of the stack element
  {
    printf("\tno elements in stack :");                /*TOP OPERATION */
  }
  else
  {
    printf("\ttop of the element :\t%d\n", *(int *)res->stack_array[res->stack_depth - 1]);
  }
  
  //------------------------------------------------------------------------------------------------------------------------------------------------
  stack_print(res);                                     /*PRINT CURRENT ELEMENTS IN STACK */
  //------------------------------------------------------------------------------------------------------------------------------------------------
  stack_destroy(res);                                    // destroy stack
  return 0;
}

