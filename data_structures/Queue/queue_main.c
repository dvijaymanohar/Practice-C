/* PROGRAM TO VERIFY THE QUEUE OPERATIONS */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void gen_print(void *);

int main()
{
  struct queue *ptr;
  int size = 0, status;     //helps in input checking
  int *data_ptr;
  void (*func)(void *);
  printf("\nEnter the queue size in the range 2 to 100: ");
  scanf("%d", &size);
  
  if (size < 2 || size > 100)
  {
    printf("Not a valid input / Out of range\n");
    exit(1);
  }
  
  //CREATE QUEUE
  ptr = queue_create(size);
  
  while (1)
  {
    //ADD ELEMENT ONTO THE QUEUE
    while (1)
    {
      //fflush(stdin);    //clear the input buffer
      while (getchar() != '\n');
      
      data_ptr = (void *) malloc(sizeof(int));
      printf("Enter the integer data to be pushed on queue : ");
      scanf("%d", data_ptr);
      status = queue_enqueue(ptr, (void *)data_ptr);
      
      if (status == 1)
      {
        printf("Element added to the queue successfully\n");
        printf("Do you want to continue (y/n) : ");
        
        //fflush(stdin);    //clear the input buffer
        while (getchar() != '\n');
        
        if (getchar() != 'y')
        {
          break;
        }
      }
      else
      {
        printf("Error: Queue overflow\n");
        break;
      }
    }
    
    //GET ELEMENT FROM THE QUEUE
    while (1)
    {
      data_ptr = queue_dequeue(ptr);
      
      if (data_ptr == NULL)
      {
        printf("Queue is empty\n");
        break;
      }
      else
      {
        printf("Data from the queue is : %d\n", *data_ptr);
        free(data_ptr);
        
        //fflush(stdin);    //clear the input buffer
        while (getchar() != '\n');
        
        printf("Do you want to continue (y/n) : ");
        
        if (getchar() != 'y')
        {
          break;
        }
      }
    }
    
    while (getchar() != '\n');  //clear the input buffer
    
    printf("\nDo you want to continue Push n Pop (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
  }
  
  //PRINT THE ELEMENTS IN THE QUEUE
  func = gen_print;
  queue_print(ptr, func);
  //DESTROY THE queue
  //queue_destroy(ptr);
  return 0;
}



void gen_print(void *data_ptr)
{
  printf("%d\n", *(int *)(data_ptr));
}
