/* PROGRAM TO EVALUATE POSTFIX STRING AT COMMAND LINE */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
int get_priority(char);

int main(int argc, char *argv[])
{
  void *ptr;
  char *infix_ptr, *top_element;
  int infix_len, status, priority_in, priority_out, i;
  
  if (argc != 2)
  {
    printf("\nToo few or too many arguments at the command line\n");
    exit(0);
  }
  
  ptr = stack_create(50);
  infix_ptr = argv[1];
  infix_len = strlen(infix_ptr);
  
  for (i = 0; i < infix_len; i++)
  {
    priority_out = get_priority((char)infix_ptr[i]);
    
    if (priority_out == 0)
    {
      printf("%c", infix_ptr[i]);
      continue;
    }
    
    while (1)
    {
      top_element = stack_top(ptr);
      
      if (top_element == NULL)
      {
        status = stack_push(ptr, (void *)(infix_ptr + i));
        break;
      }
      else
      {
        priority_in = get_priority(*top_element);
        
        if (priority_out > priority_in)
        {
          status = stack_push(ptr, (void *)(infix_ptr + i));
          
          if (status == 0)
          {
            printf("Error: Stack overflow\n");
            stack_destroy(ptr);
            exit(1);
          }
          
          break;
        }
        else
        {
          top_element = stack_pop(ptr);
          printf("%c", *top_element);
        }
      }
    }
  }
  
  while (1)
  {
    top_element = stack_pop(ptr);
    
    if (top_element != NULL)
    {
      printf("%c", *top_element);
    }
    else
    {
      break;
    }
  }
  
  stack_destroy(ptr);
  printf("\n");
  return 0;
}

int get_priority(char c)
{
  if (c == '/' || c == '*' || c == '%')
  {
    return 2;
  }
  else if (c == '+' || c == '-')
  {
    return 1;
  }
  else if (c == ' ')
  {
    return (-1);
  }
  else
  {
    return 0;
  }
}

