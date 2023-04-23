# include <stdio.h>
# include <stdlib.h>
# include "queue.h"

void print(void *);
int getinp(void);

int main()
{
  int *input, *output, maxsize, status, option, *temp;
  struct queue *myqueue;
  void (*printing)(void *);
  printf("Enter the size of the queue\n");
  scanf("%d", &maxsize);
  printing = print;
  myqueue = (struct queue *)queue_create(maxsize);
  
  if (myqueue != NULL)
  {
    printf("memory allocation success\n");
    
    while (1)
    {
      printf("Enter your choice\n1.Enqueue.\n2.Dequeue.\n3.Print.\n4.Exit.\n");
      option = getinp();
      
      switch (option)
      {
        case 1:
          printf("Enter the elements:\n");
          input = malloc(sizeof(int));
          scanf("%d", input);
          status = queue_add(myqueue, input);
          
          if (status == 0)
          {
            printf("Queue is full  and %d not included ! ! !\n", *input);
          }
          
          break;
          
        case 2:
          temp = queue_delete(myqueue);
          
          if (temp != NULL)
          {
            output = (int *)temp;
            printf("%d is the Dequeued element!\n", *output);
          }
          else
          {
            printf("The Queue is Empty\n");
          }
          
          break;
          
        case 3:
          printf("The elements inside the queue are:\n");
          queue_print(myqueue, printing);
          break;
          
        case 4:
          exit(0);
      }
    }
  }
  else
  {
    printf("memory allocation failure\n");
  }
  
  return 0;
}

void print(void *element)
{
  int *element1;
  
  if (element != NULL)
  {
    element1 = (int *)element;
    printf("%d\n", *element1);
  }
  else
  {
    printf("Nothing!\n");
  }
}

int getinp(void)
{
  int input;
  scanf("%d", &input);
  
  if (input <= 0 || input > 4)
  {
    printf("Not inside limit please enter again\n");
    input = getinp();
  }
  
  return input;
}
