# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "stack.h"

int checkp(char, char);
int check(char value);

int main()
{
  int sizeofstack, result, i, result1, result2, result3;
  char *pushchar, *pushchar1, *poppedchar, *topchar, temp, *topchar1, temp2;
  poppedchar = malloc(sizeof(char));
  topchar = malloc(sizeof(char));
  topchar1 = malloc(sizeof(char));
  struct stack *mystack;
  pushchar = malloc(80 * sizeof(char));
  printf("Enter the Infix Expression:\n");
  scanf("%s", pushchar);
  sizeofstack = strlen(pushchar);
  mystack = (struct stack *)stack_create(sizeofstack);
  
  for (i = 0; i < sizeofstack; i++)
  {
    pushchar1 = pushchar;
    temp = *pushchar1;
    
    if (!(temp <= 47 && temp >= 37 && temp != 38 && temp != 39 && temp != 44 && temp != 46))
    {
      printf("%c", temp);
    }
    else
    {
      topchar = (char *)stack_top(mystack);
      
      if (topchar != NULL)
      {
        if (temp == 40)
        {
          result = stack_push(mystack, pushchar1);
        }
        else if (temp == 41)
        {
          do
          {
            poppedchar = (char *)stack_pop(mystack);
            
            if (poppedchar != NULL)
            {
              temp2 = *poppedchar;
              
              if (temp2 != 40)
              {
                printf("%c", temp2);
              }
            }
            else
            {
              break;
            }
          }
          while (temp2 != 40);
        }
        else
        {
          result2 = checkp(temp, *topchar);
          
          switch (result2)
          {
            case 0:
              result = stack_push(mystack, pushchar1);
              break;
              
            case 1:
              poppedchar = (char *)stack_pop(mystack);
              printf("%c", *poppedchar);
              
              do
              {
                topchar1 = (char *)stack_top(mystack);
                
                if (topchar1 != NULL)
                {
                  result3 = checkp(temp, *topchar1);
                }
                
                if (result3 == 1)
                {
                  poppedchar = (char *)stack_pop(mystack);
                  
                  if (poppedchar != NULL)
                  {
                    printf("%c", *poppedchar);
                  }
                  
                  result = stack_push(mystack, pushchar1);
                  break;
                }
                else
                {
                  result = stack_push(mystack, pushchar1);
                }
              }
              while (result3 == 1);
              
              break;
          }
        }
      }
      else
      {
        result1 = stack_push(mystack, pushchar1);
      }
    }
    
    pushchar++;
  }
  
  do
  {
    poppedchar = (char *)stack_pop(mystack);
    
    if (poppedchar != NULL)
    {
      printf("%c", *poppedchar);
    }
  }
  while (poppedchar != NULL);
  
  printf("\tis the Postfix expression\n");
  return 0;
}




int checkp(char temp1, char temp2)
{
  int comp1, comp2;
  comp1 = check(temp1);
  comp2 = check(temp2);
  
  if ((comp2 > comp1) || (comp2 == comp1))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


int check(char value)
{
  if (value == 37 || value == 42 || value == 47)
  {
    return 1;
  }
  else if (value == 43 || value == 45)
  {
    return 0;
  }
  else if (value == 40)
  {
    return -1;
  }
  else { return 0; }
}
