/* PROGRAM TO VERIFY THE STACK OPERATIONS */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void gen_print(void *);

int main()
{
  struct stack *ptr;
  int size = 0, status;     //helps in input checking
  int *data_ptr;
  void (*func)(void *);
  printf("\nEnter the stack size in the range 1 to 100: ");
  scanf("%d", &size);
  
  if (size < 1 || size > 100)
  {
    printf("Not a valid input / Out of range\n");
    exit(1);
  }
  
  //CREATE STACK
  ptr = stack_create(size);
  
  //PUSH ONTO THE STACK
  while (1)
  {
    fflush(stdin);
    //    while(getchar() != '\n');   //clear the input buffer
    data_ptr = (void *) malloc(sizeof(int));
    printf("Enter the integer data to be pushed on stack : ");
    scanf("%d", data_ptr);
    status = stack_push(ptr, (void *)data_ptr);
    
    if (status == 1)
    {
      while (getchar() != '\n');  //clear the input buffer
      
      printf("Push successful\nDo you want to continue (y/n) : ");
      
      if (getchar() != 'y')
      {
        break;
      }
    }
    else
    {
      printf("Error: Stack overflow\n");
      break;
    }
  }
  
  //POP FROM THE STACK
  while (1)
  {
    data_ptr = stack_pop(ptr);
    
    if (data_ptr == NULL)
    {
      printf("Stack is empty\n");
      break;
    }
    else
    {
      printf("Data popped out is : %d\n", *data_ptr);
      free(data_ptr);
      
      while (getchar() != '\n');  //clear the input buffer
      
      printf("Do you want to continue (y/n) : ");
      
      if (getchar() != 'y')
      {
        break;
      }
    }
  }
  
  //GET THE TOPMOST ELEMENT FROM THE STACK
  data_ptr = stack_top(ptr);
  
  if (data_ptr == NULL)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Topmost element of the stack is : %d\n", *data_ptr);
  }
  
  //PRINT THE ELEMENTS IN THE STACK
  func = gen_print;
  stack_print(ptr, func);
  //DESTROY THE STACK
  stack_destroy(ptr);
  return 0;
}



void gen_print(void *data_ptr)
{
  printf("%d\n", *(int *)(data_ptr));
}
