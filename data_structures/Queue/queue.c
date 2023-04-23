/* FUNCTIONS FOR CIRCULAR QUEUE OPERATIONS */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


//FUNCTION TO CREATE A QUEUE

struct queue *queue_create(int size)
{
  struct queue *ptr;
  ptr = (void *) malloc(sizeof(struct queue));
  ptr->queue_maxsize = size;
  ptr->queue_head = 0;
  ptr->queue_tail = 0;
  ptr->queue_array = (void *) calloc(ptr->queue_maxsize, sizeof(void *));
  return (ptr);
}


//FUNCTION TO ADD ELEMENTS INTO A QUEUE

int queue_enqueue(struct queue *ptr, void *data_ptr)
{
  if (ptr->queue_tail - ptr->queue_head == ptr->queue_maxsize - 1)
  {
    return 0;
  }
  else
  {
    ptr->queue_array[ptr->queue_tail % ptr->queue_maxsize] = data_ptr;
    ptr->queue_tail += 1;
    return 1;
  }
}


//FUNCTION TO GET ELEMENTS FROM THE QUEUE

void *queue_dequeue(struct queue *ptr)
{
  void *data_ptr;
  
  if (ptr->queue_head == ptr->queue_tail)
  {
    return (NULL);
  }
  else
  {
    data_ptr = (void *)ptr->queue_array[ptr->queue_head % ptr->queue_maxsize];
    ptr->queue_head += 1;
    return (data_ptr);
  }
}


//FUNCTION TO PRINT THE ELEMENTS IN THE QUEUE

void queue_print(struct queue *ptr, void (*func)(void *))
{
  int i;
  
  if (ptr->queue_head == ptr->queue_tail)
  {
    printf("Error: Queue is empty.\n");
    return;
  }
  
  printf("The element(s) in the queue is/are :\n");
  
  for (i = ptr->queue_head; i != ptr->queue_tail; i++)
  {
    func(ptr->queue_array[i % ptr->queue_maxsize]);
  }
}


//DESTROY THE QUEUE

void queue_destroy(struct queue *ptr)
{
  free(ptr->queue_array);
  free(ptr);
}
