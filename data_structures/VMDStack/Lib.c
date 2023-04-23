#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include <stdio.h>

StackClass_t *CreateStack(int MaxSize)
{
  StackClass_t *NewStack = (StackClass_t *) malloc(sizeof(StackClass_t));
  NewStack -> Top = STACK_INIT_VAL;
  NewStack -> MaxSize = MaxSize;
  NewStack -> StackArray = (void **) malloc(MaxSize * sizeof(void *));
  return NewStack;
}

int PushStack(StackClass_t *Stack, void *Element)
{
  if (Stack -> Top == Stack -> MaxSize) { return RETVAL1; } //Return failure
  else { Stack -> StackArray[(Stack -> Top)++] = Element; }
  
  return RETVAL2 ;  //Return Success
}

void *PopStack(StackClass_t *Stack)
{
  int i = RETVAL1;
  
  if (Stack -> Top == STACK_INIT_VAL) { return (void *) &i ; } //Return Failure
  else { return (Stack -> StackArray[ -- Stack -> Top]); }
}

void *StackTop(StackClass_t *Stack)
{
  if (Stack -> Top == STACK_INIT_VAL) { return (void *)RETVAL1; } //Return Failure
  else { return Stack -> StackArray [(Stack -> Top)]; } // Return the Stack Top Value
}

void *DisplayStack(StackClass_t *Stack, void (*PrintTop)(void *Data))
{
  int i = RETVAL1;
  
  if (Stack -> Top == STACK_INIT_VAL) { return (void *) &i; } //Return Failure
  else
  {
    printf("\n\tWitness the stack elements here :\n");
    
    for (i = ZERO; i < Stack -> Top; i++) { PrintTop(Stack -> StackArray[i]); }
  }
  
  return (void *) &i;
}

void DestroyStack(StackClass_t *Stack)
{
  int i;
  
  for (i = ZERO; i < Stack -> MaxSize; i++)
  {
    free(Stack -> StackArray[i]);
    Stack -> StackArray[i] = NULL;
  }
  
  free(Stack -> StackArray);
  free(Stack);
  Stack = NULL;
}
