/**
 * @file circular_que.h
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

#define QUEUE_SIZE 15

#define QUE_OP_SUCCESS 0
#define QUE_OP_FAILURE -1
#define QUE_OP_MEM_ALLOC_FAILURE -2
#define QUE_OP_ENQUE_FAILURE -3
#define QUE_OP_DEQUE_FAILURE -4
#define QUE_DATA_ITEM_SIZE 258

struct data_buf {
  char *data;
  unsigned int data_len; /** No of items */
};

typedef struct data_buf data_buf_t;

// Data structure to represent the circular queue
struct queue {
  /** List of data buffers */
  data_buf_t **items;

  /* Lock to protect the queue from concurrent access from multiple threads */
  pthread_mutex_t mutex;

  int max_que_size;       // maximum queue capacity
  int front;              // front points to the front element in the queue
  int rear;               // rear points to the last element in the queue
  unsigned int curr_size; // current queue capacity
};

struct queue *create_que(const int size);
unsigned int get_que_size(const struct queue *const que_ptr);
int is_queue_empty(const struct queue *const que_ptr);
void free_queue(struct queue **que_ptr);
int enqueue(struct queue *const que_ptr, data_buf_t *const buff);
int dequeue(struct queue *const que_ptr, data_buf_t *const buff);

