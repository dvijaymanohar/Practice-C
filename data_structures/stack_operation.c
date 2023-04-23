# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "stack.h"

void print(void *);

int main()
{
  int sizeofstack, result, i;
  char *pushchar, *pushchar1, *poppedchar, *topchar;
  void (*printing)(void *);
  printing = print;
  poppedchar = malloc(sizeof(char));
  topchar = malloc(sizeof(char));
  struct stack *mystack;
  pushchar = malloc(80 * sizeof(char));
  printf("Enter the string\n");
  scanf("%s", pushchar);
  sizeofstack = strlen(pushchar);
  mystack = (struct stack *)stack_create(sizeofstack);
  
  for (i = 0; i < sizeofstack; i++)
  {
    pushchar1 = pushchar;
    result = stack_push(mystack, pushchar1);
    pushchar++;
  }
  
  printf("The top element is\t");
  topchar = (char *)stack_top(mystack);
  printf("%s\n\n", topchar);
  printf("Printing the stack elements\n");
  stack_print(mystack, printing);
  printf("\nThe popped elements are\n");
  
  for (i = 0; i < sizeofstack; i++)
  {
    poppedchar = (char *)stack_pop(mystack);
    
    if (poppedchar != NULL)
    {
      printf("%c\n", *poppedchar);
    }
    else
    {
      printf("Stack is Empty\n");
    }
  }
  
  topchar = (char *)stack_top(mystack);
  
  if (topchar != NULL)
  {
    printf("The top element is\t");
    printf("%s\n\n", topchar);
  }
  else
  {
    printf("The stack is empty\n");
  }
  
  stack_destroy(mystack);
  return 0;
}


void print(void *element)
{
  char *element1;
  
  if (element != NULL)
  {
    element1 = (char *)element;
    printf("%c", *element1);
  }
}

