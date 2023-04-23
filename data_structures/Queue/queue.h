#ifndef QUEUE_H
#define QUEUE_H

struct queue
{
  struct queue *llink;
  int priority;
  struct queue *rlink;
};

struct queue *rear, *front;

//Queue ADT operations
int enqueue(int n);
int dequeue(void);
int dispose_queue(void);
void display_queue(void);

#endif;



