#ifndef STACK_H
#define STACK_H

#define SIZE  15
typedef struct
{
  int TOP;
  int stak[SIZE];
} stack;

int push(int n);
int pop(void);
int display_stack(void);
int isfull(void);
int isempty(void);

stack *ptr;

#endif


