#ifndef STACK_H
#define STACK_H
struct queue
{
  unsigned int queue_maxsize;
  unsigned int queue_head;
  unsigned int queue_tail;
  void **queue_array;
};

struct queue *queue_create(int);
int queue_add(struct queue *, void *);
void *queue_delete(struct queue *);
void queue_print(struct queue *, void(*printing)(void *));
void queue_destroy(struct queue *);
#endif
