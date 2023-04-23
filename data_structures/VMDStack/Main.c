#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void Print_Str(void *Data);
void Print_Int(void *Data);

int main(int argc, char *argv[])
{
  if (argc != ARGCOUNT)
  {
    fprintf(stderr, "\tUsage : %s <Maximum size of the stack >\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  int Choice, RetVal;
  int *N, Size = atoi(argv[1]);
  StackClass_t *IntStack = CreateStack(Size);
  
  do
  {
    printf("\n\n\t\t\tStack ADT Operations");
    printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit ");
    printf("\n\n\tEnter Ur choice here:");
    RetVal = 0;
    
    do
    {
      RetVal = scanf("%d", &Choice);
      
      if (!RetVal) { printf("\nEnter a valid choice here:"); }
      
      while (getchar() != '\n');
    }
    while (!RetVal);
    
    switch (Choice)
    {
      case PUSH:
        printf("\n\tEnter a value to push: ");
        N = malloc(sizeof(int));
        scanf("%d", N);
        RetVal =  PushStack(IntStack, (void *)N);
        
        if (RETVAL1 ==  RetVal)
        {
          printf("\n\tPush: Stack is overflown\n");
          break;
        }
        else { printf("\n\tElement Pushed\n"); }
        
        break;
        
      case POP:
        RetVal = *(int *)PopStack(IntStack);
        
        if (RetVal == -1) { printf("\n\tStack is underflown\n"); }
        else { printf("\n\tPopped Value : %d\n", RetVal); }
        
        break;
        
      case DISPLAY:
        RetVal = *(int *)DisplayStack(IntStack, &Print_Int);
        
        if (RETVAL1 == RetVal) { printf("\n\tDisplay: Stack is empty\n"); }
        
        break;
        
      case EXIT:
        DestroyStack(IntStack);
        exit(EXIT_SUCCESS);
        break;
        
      default:
        printf("\n\tEnter a valid choice here:\n");
        break;
    }
  }
  while (CONTINUE);
  
  return 0;
}

void Print_Int(void *Data)
{
  printf("\t%d", *(int *)Data);
}

void Print_Str(void *Data)
{
  printf("\t%s", (char *)Data);
}
