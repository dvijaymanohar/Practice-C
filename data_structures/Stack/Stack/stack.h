#ifndef STACK_H
#define STACK_H

struct stack
{
  int stack_maxsize;
  int stack_depth;
  void **stack_array;
};

struct stack *stack_create(int);
int stack_push(struct stack *, void *);
void *stack_pop(struct stack *);
void *stack_top(struct stack *);
void stack_print(struct stack *, void (*func)(void *));
void stack_destroy(struct stack *);
#endif
