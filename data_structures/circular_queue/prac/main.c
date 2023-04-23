/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 * Todo:
 * - Array of pointers
 * - Multithreading support for enqueue and dequeue.
 */

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
#define QUE_OP_SUCCESS 0
#define QUE_OP_FAILURE -1

// Data structure to represent the circular queue
struct queue {
  int *items; // array to store queue elements

  int maxsize; // maximum capacity of the queue
  int front;   // front points to the front element in the queue (if any)
  int rear;    // rear points to the last element in the queue
  int size;    // current capacity of the queue
};

// Function to initialize the queue
struct queue *que_desc(int size) {
  struct queue *que_ptr = NULL;

  que_ptr = (struct queue *)calloc(sizeof(struct queue), 1);

  if (NULL == que_ptr)
    return NULL;

  que_ptr->items = (int *)calloc(size * sizeof(int), 1);

  if (NULL == que_ptr->items) {
    free(que_ptr);
    que_ptr = NULL;

    return NULL;
  }

  que_ptr->maxsize = size;
  que_ptr->front = 0;
  que_ptr->rear = -1;
  que_ptr->size = 0;

  return que_ptr;
}

// Function to return the size of the queue
int size(struct queue *que_ptr) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  return que_ptr->size;
}

// Function to check if the queue is empty or not
int isEmpty(struct queue *que_ptr) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  return !size(que_ptr);
}

void free_queue(struct queue **que_ptr) {
  if (NULL == que_ptr)
    return;

  if (NULL != *que_ptr) {
    if (NULL != (*que_ptr)->items) {
      free((*que_ptr)->items);

      (*que_ptr)->items = NULL;
    }

    free(*que_ptr);

    *que_ptr = NULL;
  }
}

// Function to add an element to the queue at the rear end
int enqueue(struct queue *que_ptr, int x) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  if (NULL == que_ptr->items)
    return QUE_OP_FAILURE;

  if (size(que_ptr) == que_ptr->maxsize) {
    printf("Queue Overflow\n");
  }

  que_ptr->rear = (que_ptr->rear + 1) % que_ptr->maxsize; // circular queue
  que_ptr->items[que_ptr->rear] = x;
  que_ptr->size++;

  printf("front = %d, rear = %d\n", que_ptr->front, que_ptr->rear);

  return QUE_OP_SUCCESS;
}

// Function to dequeue the element at the front end of the queue
int dequeue(struct queue *que_ptr, int *element) {
  if (NULL == que_ptr || NULL == element)
    return QUE_OP_FAILURE;

  if (NULL == que_ptr->items)
    return QUE_OP_FAILURE;

  if (isEmpty(que_ptr))
  {
    printf("Queue Underflow/Empty\n");
    return QUE_OP_FAILURE;
  }

  *element = que_ptr->items[que_ptr->front];
  que_ptr->front = (que_ptr->front + 1) % que_ptr->maxsize; // circular queue
  que_ptr->size--;

  printf("front = %d, rear = %d\n", que_ptr->front, que_ptr->rear);

  return QUE_OP_SUCCESS;
}

int main() {
  struct queue *que_ptr = que_desc(QUEUE_SIZE);
  int element = 0;
  int i = 0;

  if (NULL == que_ptr) return EXIT_FAILURE;

  for (i = 0; i <= QUEUE_SIZE; i++)
    enqueue(que_ptr, i);

  for (i = 0; i <= QUEUE_SIZE; i++)
    if (!dequeue(que_ptr, &element))
      printf("Element dequeued: %d\n", element);

  enqueue(que_ptr, 5);
  enqueue(que_ptr, 6);
  enqueue(que_ptr, 7);
  printf("size = %d\nDequeuing now", size(que_ptr));

  if (!dequeue(que_ptr, &element))
    printf("Element dequeued: %d\n", element);

  if (!dequeue(que_ptr, &element))
    printf("Element dequeued: %d\n", element);

  if (!dequeue(que_ptr, &element))
    printf("Element dequeued: %d\n", element);

  if (isEmpty(que_ptr)) {
    printf("The queue is empty\n");
  } else {
    printf("The queue is not empty\n");
  }

  free_queue(&que_ptr);

  if (enqueue(que_ptr, 5)) {
    printf("Init queue first\n");
  }

  if (!dequeue(que_ptr, &element))
    printf("Element dequeued: %d\n", element);
  else
    printf("Init queue first\n");

  return EXIT_SUCCESS;
}