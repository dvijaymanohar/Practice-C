#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define DEBUG 0

int main(int argc, char *argv[])
{
  int i, j, open_brace = 0;
  char c;
  ptr = (stack *)malloc(sizeof(stack));
  ptr->TOP = -1;
  int get_priority(char);
  
  if (argc != 2)
  {
    printf("\nInalid no of arguments\n");
    return 0;
  }
  
  if (DEBUG)
  {
    for (i = 0; argv[1][i] != '\0'; i++)
    {
      printf("\nString: %c\n", argv[1][i]);
    }
  }
  
  int get_priority(char c)
  {
    if (c == '/' || c == '*' || c == '%')
    {
      return 2;
    }
    
    if (c == '+' || c == '-')
    {
      return 1;
    }
    
    if (c == ' ')
    {
      return -1;
    }
    
    return 0;
  }
  //  printf("\nVMD\n");
  //  printf("\n\t");
  /*  for (i = 0; argv[1][i] != '\0'; i++)
    {
      for (j = 0; Op[j] != '\0'; j++)
      {
        if (argv[1][i] == Op[j])
        {
            if ( isempty() )
            {
              push(argv[1][i]);
              continue;
            }
            else if (argv[1][i] == '(')
            {
              push(argv[1][i]);
              open_brace++;
            }
            else if (argv[1][i] == ')')
            {
              if (open_brace == 0)
                printf ("\n\tInvalid Expression\n");
              for (;;)
              {
                c = pop();
                if (c == '(')
                  break;
                else
                  printf("%c", c);
              }
              open_brace = 0;
            }
            else if ( get_priority (argv[1][i]) > get_priority (ptr -> TOP) )
            {
              push(argv[1][i]);
              printf("%c", argv[1][i]);
            }
            else
            {
              for (;get_priority (argv[1][i] <= get_priority (ptr ->TOP));)
              {
                printf("%c", pop());
              }
              push(get_priority(argv[1][i]));
            }
        }
        if (DEBUG)  display_stack();
  
      }
      printf("%c", argv[1][i]);
    }
  
    return 0;
  }
  
  */