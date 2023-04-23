#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include<string.h>

struct queue *queue_create(int size)
{
  struct queue *node ;
  node = (struct queue *)malloc(sizeof(struct queue));
  node->queue_maxsize = size;
  node->queue_front = -1;
  node->queue_rear = -1;
  node->queue_array = (void **)malloc(node->queue_maxsize * sizeof(void *));
  memset(node->queue_array, (node->queue_maxsize)*sizeof(int), 0);
  return node;
}


int queue_add(struct queue *node, void *val)
{
  if (node->queue_rear - node->queue_front == node->queue_maxsize - 1)
  {
    return 0 ;
  }
  else
  {
    node->queue_array[node->queue_rear % node->queue_maxsize] = val ;
    node->queue_rear++;
    return 1 ;
  }
}

void *queue_del(struct queue *node)

{
  void *temp = NULL;
  
  if (node->queue_rear == node->queue_front)
  {
    return NULL;
  }
  else
  {
    temp = node->queue_array[(node->queue_front % node->queue_maxsize)];
    //node->queue_array[(node->queue_front % node->queue_maxsize )] = NULL;
    node->queue_front++;
    return temp ;
  }
}

void queue_print(struct queue *node)
{
  if (node->queue_rear == node->queue_front)
  {
    printf("\t queue is empty \n");
  }
  else
    do
    {
      node->queue_front++;
      printf("\t current elements in queue\t%d\n", *(int *)(node->queue_array[node->queue_front - 1 ]));
    }
    while (node->queue_front != node->queue_maxsize - 1);//node->queue_rear );
}

void queue_destroy(struct queue *node)
{
  free(node);
  free(node->queue_array);
}


