#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* CREATING THE queue WITH THE FIELD MEMORY ALLOCATED */

struct queue *queue_create(int sizeofqueue)
{
  struct queue *myqueue;
  myqueue = malloc(sizeof(struct queue));
  myqueue->queue_array = (void **)malloc(sizeofqueue * sizeof(void *));
  myqueue->queue_maxsize = sizeofqueue;
  myqueue->queue_head = -1;
  myqueue->queue_tail = -1;
  return myqueue;
}

/* ADDING THE ELEMENT INTO THE QUEUE */

int queue_add(struct queue *myqueue, void *element)
{
  if ((myqueue->queue_tail - myqueue->queue_head) > myqueue->queue_maxsize - 1)
  {
    return 0;
  }
  else
  {
    myqueue->queue_tail++;
    myqueue->queue_array[(myqueue->queue_tail) % (myqueue->queue_maxsize)] = element;
    return 1;
  }
}

/* DELETING OUT AN ELEMENT FORM THE QUEUE AND RETURNING IT */

void *queue_delete(struct queue *myqueue)
{
  void *element;
  
  if (myqueue->queue_tail != myqueue->queue_head)
  {
    myqueue->queue_head++;
    element = myqueue->queue_array[(myqueue->queue_head) % (myqueue->queue_maxsize)];
    return element;
  }
  else
  {
    return NULL;
  }
}

void queue_print(struct queue *myqueue, void (*printing)(void *))
{
  int i;
  
  for (i = myqueue->queue_head + 1; i <= myqueue->queue_tail ; i++)
  {
    printing(myqueue->queue_array[i]);
  }
}

void queue_destroy(struct queue *myqueue)
{
  free(myqueue->queue_array);
  free(myqueue);
}


