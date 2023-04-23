#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define debug 0

int main(void)
{
  int choice, ret, n ;
  int count = 0;
  ptr = (stack *)malloc(sizeof(stack));
  ptr->TOP = -1;
  
  do
  {
    printf("\n\n\t\t\tStack ADT Operations");
    printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit ");
    printf("\n\n\tEnter Ur choice here:");
    
    do
    {
      ret = scanf("%d", &choice);
      
      if (!ret) { printf("\nEnter a valid choice here:"); }
      
      while (getchar() != '\n');
    }
    while (!ret);
    
    switch (choice)
    {
      case 1:
        printf("\n\tEnter a value to push: ");
        scanf("%d", &n);
        
        if (-1 == push(n))
        {
          printf("\n\tPush: Stack is overflown\n");
          break;
        }
        else { printf("\n\tElement Pushed\n"); }
        
        break;
        
      case 2:
        ret = pop();
        
        if (!ret)
        {
          printf("\tPop: Stack is underflown\n");
          break;
        }
        
        if (debug) { printf("\n\t\tCount = %d", count++); }
        
        printf("\n\t%d is popped from the stack\n", ret);
        break;
        
      case 3:
        //  ret = display_stack();
        printf("\n\tWitness the stack Elements here:\n");
        ret = display_stack();
        
        if (!ret)
        {
          printf("\n\tDisplay: Stack is empty\n");
          break;
        }
        
        break;
        
      case 4:
        exit(1);
        break;
        
      default:
        printf("\n\tEnter a valid choice.\n");
        break;
    }
  }
  while (1);
  
  return 0;
}

