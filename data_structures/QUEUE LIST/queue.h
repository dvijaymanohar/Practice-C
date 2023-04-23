#ifndef QUEUE_H
#define QUEUE_H

struct queue
{
  int queue_maxsize;
  int queue_front;
  int queue_rear;
  void **queue_array;
};

struct queue *queue_create(int);
int queue_add(struct queue *, void *);
void *queue_del(struct queue *);
void queue_print(struct queue *);
void queue_destroy(struct queue *);

#endif

