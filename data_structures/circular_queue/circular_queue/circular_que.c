/**
 * @file circular_que.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#include "circular_que .h"

// Function to return the size of the queue
unsigned int get_que_size(const struct queue *const que_ptr) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  return que_ptr->curr_size;
}

// Function to check if the queue is empty or not
int is_queue_empty(const struct queue *const que_ptr) {
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

    que_ptr->items[i]->data =
        (char *)calloc(QUE_DATA_ITEM_SIZE * sizeof(int), 1);
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
int enqueue(struct queue *const que_ptr, data_buf_t *const buff) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  if (NULL == que_ptr->items)
    return QUE_OP_FAILURE;

  if (NULL == buff)
    return QUE_OP_ENQUE_FAILURE;

  if (get_que_size(que_ptr) == que_ptr->max_que_size) {
    printf("Queue Overflow detected\n");
    return QUE_OP_ENQUE_FAILURE;
  }

  if (NULL == buff->data)
    return QUE_OP_ENQUE_FAILURE;

  que_ptr->rear = (que_ptr->rear + 1) % que_ptr->max_que_size; // circular queue

  // Copy the data to the Circular buffer
  memcpy(que_ptr->items[que_ptr->rear]->data, buff->data, buff->data_len);
  que_ptr->items[que_ptr->rear]->data_len = buff->data_len;

  pthread_mutex_lock(&que_ptr->mutex);
  que_ptr->curr_size++;
  pthread_mutex_unlock(&que_ptr->mutex);

  // printf("front = %d, rear = %d\n", que_ptr->front, que_ptr->rear);

  return QUE_OP_SUCCESS;
}

// Function to dequeue the element at the front end of the queue
// Dequeue is called by the read function call.
int dequeue(struct queue *const que_ptr, data_buf_t *const buff) {
  if (NULL == que_ptr)
    return QUE_OP_FAILURE;

  if (NULL == que_ptr->items)
    return QUE_OP_FAILURE;

  if (NULL == buff)
    return QUE_OP_DEQUE_FAILURE;

  if (is_queue_empty(que_ptr)) {
    printf("Queue Underflow/Empty\n");
    return QUE_OP_DEQUE_FAILURE;
  }

  if (NULL == buff->data)
    return QUE_OP_DEQUE_FAILURE;

  // Copy the data to the supplied buffer
  buff->data_len = que_ptr->items[que_ptr->front]->data_len;
  memcpy(buff->data, que_ptr->items[que_ptr->front]->data, buff->data_len);

  /* Make the data len in the buffer to 0 once, dequed */
  que_ptr->items[que_ptr->front]->data_len = 0;

  que_ptr->front =
      (que_ptr->front + 1) % que_ptr->max_que_size; // circular queue

  pthread_mutex_lock(&que_ptr->mutex);
  que_ptr->curr_size--;
  pthread_mutex_unlock(&que_ptr->mutex);

  // printf("front = %d, rear = %d\n", que_ptr->front, que_ptr->rear);

  return QUE_OP_SUCCESS;
}


