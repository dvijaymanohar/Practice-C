# include <stdio.h>
# include <stdlib.h>
# include "stack.h"

int main()
{
  int *input, *output;
  int size = 0, result, stacksize = 10;
  struct stack *mystack;
  mystack = (struct stack *)stack_create(stacksize);
  printf("Enter the numbers\n");
  
  do
  {
    input = malloc(sizeof(int));
    scanf("%d", input);
    
    if (*input == 0)
    {
      printf("End\n");
      break;
    }
    
    result = stack_push(mystack, input);
    
    if (result == 0)
    {
      printf("Stack overflow\n");
      break;
    }
    
    size++;
  }
  while (*input != 0);
  
  output = (int *)stack_pop(mystack);
  
  while (output != NULL)
  {
    if (output != NULL)
    {
      printf("%d", *output);
      output = (int *)stack_pop(mystack);
    }
  }
  
  return 0;
}


