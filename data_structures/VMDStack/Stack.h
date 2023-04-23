#ifndef STACK_H
#define STACK_H

#define STACK_INIT_VAL   0    //Top initial value
#define RETVAL1     -1    //For Failure
#define RETVAL2      0    //For Success
#define ONE        1
#define ZERO       0
#define ARGCOUNT     2
#define CONTINUE     1

//Switch Cases

#define PUSH         1
#define POP          2
#define DISPLAY      3
#define EXIT       4

#define DEBUG0       0
#define DEBUG1       1

typedef struct
{
  int Top;      /*  Top of the Stack. That is fixed. it can't be float  */
  int MaxSize;    /*  Maximum Size of the Stack */
  void **StackArray;  /*  This points to the array of void *s */
} StackClass_t;

//Function Operating on the Stack
StackClass_t *CreateStack(int MaxSize);
void DestroyStack(StackClass_t *StackDest);
void *DisplayStack(StackClass_t *Stack, void (*PrintTop)(void *Data));
int PushStack(StackClass_t *Stack, void *Element);
void *PopStack(StackClass_t *Stack);  //This return the pooped out value
void *StackTop(StackClass_t *Stack);  //This gives the value that the top of the Stack holds

#endif
