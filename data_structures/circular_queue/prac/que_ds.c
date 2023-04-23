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
 * + Pointer to a DS (Data and Len)
 * + Array of pointers
 * + Multithreading support for enqueue and dequeue.
 * + Analysis of enqueing and dequing needed.
 * - Memcpy to another area
 *
 */

/**
 * + Tests
 *   + Enque and deque in order
 *   + Enqueue more than the capacity
 *   + Dequeue less than the items
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#define QUEUE_SIZE 15

#define QUE_OP_SUCCESS 0
#define QUE_OP_FAILURE -1
#define QUE_OP_MEM_ALLOC_FAILURE -2
#define QUE_OP_ENQUE_FAILURE -3
#define QUE_OP_DEQUE_FAILURE -4

struct data_buf {
  int *data;
  unsigned int data_len; /** No of items */
};

typedef struct data_buf data_buf_t;

// Data structure to represent the circular queue
struct queue {
  /** List of data buffers */
  data_buf_t **items;

  /* Lock to protect the queue from concurrent access from multiple threads */
  pthread_mutex_t mutex;

  int max_que_size;       // maximum capacity of the queue
  int front;              // front points to the front element in the queue
  int rear;               // rear points to the last element in the queue
  unsigned int curr_size; // current queue capacity
};

// Function to return the size of the queue
static int get_que_size(const struct queue *const que_ptr) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  return que_ptr->curr_size;
}

// Function to check if the queue is empty or not
static int isEmpty(const struct queue *const que_ptr) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  return !get_que_size(que_ptr);
}

struct queue *create_que(const int size) {
  struct queue *que_ptr = NULL;
  int i = 0, j = 0;

  que_ptr = (struct queue *)calloc(sizeof(struct queue), 1);

  if (NULL == que_ptr) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  que_ptr->items = (data_buf_t **)calloc(size * sizeof(data_buf_t *), 1);

  if (NULL == que_ptr->items) {
    printf("Memory allocation failed\n");
    free((void *)que_ptr);
    que_ptr = NULL;

    return NULL;
  }

  for (i = 0; i < size; i++) {
    que_ptr->items[i] = (data_buf_t *)calloc(size * sizeof(data_buf_t), 1);

    if (NULL == que_ptr->items[i]) {
      printf("Memory allocation failed\n");
      for (j = 0; j < i; j++) {
        free((void *)que_ptr->items[j]->data);
        free((void *)que_ptr->items[j]);
      }

      free((void *)que_ptr->items);
      free(que_ptr);

      return NULL;
    }

    que_ptr->items[i]->data = (int *)calloc(257 * sizeof(int), 1);
    que_ptr->items[i]->data_len = 0;

    if (NULL == que_ptr->items[i]->data) {
      printf("Memory allocation failed\n");
      for (j = 0; j < i; j++) {
        free((void *)que_ptr->items[j]->data);
        free((void *)que_ptr->items[j]);
      }

      free((void *)que_ptr->items[i]);
      free((void *)que_ptr->items);
      free((void *)que_ptr);

      return NULL;
    }
  }

  que_ptr->max_que_size = size;
  que_ptr->front = 0;
  que_ptr->rear = -1;
  que_ptr->curr_size = 0;
  que_ptr->mutex = PTHREAD_MUTEX_INITIALIZER;

  return que_ptr;
}

void free_queue(struct queue **que_ptr) {
  if (NULL == que_ptr)
    return;

  if (NULL == *que_ptr)
    return;

  if (NULL != (*que_ptr)->items) {
    for (int i = 0; i < (*que_ptr)->curr_size; i++) {
      free((void *)(*que_ptr)->items[i]->data);
      free((*que_ptr)->items[i]);
    }

    free((void *)((*que_ptr)->items));

    (*que_ptr)->items = NULL;
  }

  free((void *)(*que_ptr));

  *que_ptr = NULL;
}

// Function to add an element to the queue at the rear end
// Enqueue is called by the task
int enqueue(struct queue *const que_ptr, const int x) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  if (NULL == que_ptr->items)
    return QUE_OP_FAILURE;

  if (get_que_size(que_ptr) == que_ptr->max_que_size) {
    printf("Queue Overflow detected\n");
    return QUE_OP_ENQUE_FAILURE;
  }

  que_ptr->rear = (que_ptr->rear + 1) % que_ptr->max_que_size;

  que_ptr->items[que_ptr->rear]->data[0] = x;
  que_ptr->items[que_ptr->rear]->data_len = 1;

  pthread_mutex_lock(&que_ptr->mutex);
  que_ptr->curr_size++;
  pthread_mutex_unlock(&que_ptr->mutex);

  // printf("front = %d, rear = %d\n", que_ptr->front, que_ptr->rear);

  return QUE_OP_SUCCESS;
}

// Function to dequeue the element at the front end of the queue
// Dequeue is called by the read function call.
int dequeue(
  struct queue *const que_ptr,
  int *const element) {
  if (NULL == que_ptr || NULL == element)
    return QUE_OP_FAILURE;

  if (NULL == que_ptr->items)
    return QUE_OP_FAILURE;

  if (isEmpty(que_ptr)) {
    printf("Queue Underflow/Empty\n");
    return QUE_OP_DEQUE_FAILURE;
  }

  *element = que_ptr->items[que_ptr->front]->data[0];
  que_ptr->items[que_ptr->front]->data_len = 0;

  que_ptr->front =
      (que_ptr->front + 1) % que_ptr->max_que_size; // circular queue

  pthread_mutex_lock(&que_ptr->mutex);
  que_ptr->curr_size--;
  pthread_mutex_unlock(&que_ptr->mutex);

  // printf("front = %d, rear = %d\n", que_ptr->front, que_ptr->rear);

  return QUE_OP_SUCCESS;
}

int main() {
  struct queue *que_ptr = create_que(QUEUE_SIZE);
  int element = 0;
  int i = 0;

  if (NULL == que_ptr)
    return EXIT_FAILURE;

  for (i = 0; i <= QUEUE_SIZE + 1; i++)
    if (!enqueue(que_ptr, i))
      printf("Element enqued: %d\n", i);

  printf("Element enque done\n");

  for (i = 0; i < QUEUE_SIZE - 2; i++)
    if (!dequeue(que_ptr, &element))
      printf("Element dequeued: %d\n", element);

  if (!enqueue(que_ptr, 6))
    printf("Element enqued: 6\n");

  if (!enqueue(que_ptr, 7))
    printf("Element enqued: 7\n");

  if (!enqueue(que_ptr, 8))
    printf("Element enqued: 8\n");

  printf("size = %d\n", get_que_size(que_ptr));

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
