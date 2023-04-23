#ifndef QUEUE_H
#define QUEUE_H

struct queue
{
  struct queue *llink;
  int priority;
  struct queue *rlink;
};

//Priority Queue ADT operations
int enqueue(int n);
int dequeue(void);
int disposeQueue(void);
void displayQueue(void);
void scheduleQueue(void);

#endif
