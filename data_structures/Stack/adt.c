#include <stdio.h>
#include "stack.h"
//#define debug 0

int push(int n)
{
  if (isfull()) { return -1; }
  
  ptr->stak[++ptr->TOP] = n;
  return 1;
}

int pop(void)
{
  int ret;
  
  if (isempty()) { return 0; }
  
  ret = ptr->stak[ptr->TOP--];
  //    if (debug) printf("\n\tPopped Value :%d", ret);
  return ret;
}

int display_stack(void)
{
  int i;
  
  if (isempty()) { return 0; }
  
  //  if (debug)  printf("\nTOP : %d\n", ptr->TOP);
  for (i = ptr->TOP; i >= 0; i--)
  {
    printf("\t%d", ptr->stak[i]);
  }
  
  printf("\n\n");
  return 1;
}

int isfull(void)
{
  if (ptr->TOP == SIZE) { return 1; }
  else { return 0; }
}

int isempty(void)
{
  if (ptr->TOP == -1) { return 1; }
  else { return 0; }
}


