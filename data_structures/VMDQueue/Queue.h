#ifndef QUEUE_H
#define QUEUE_H

#define REAR_INIT_VAL   -1      //Top initial value
#define FRONT_INIT_VAL  -1
#define RETVAL1         -1      //For Failure
#define RETVAL0          0      //For Success
#define ONE              1
#define ZERO             0
#define ARGCOUNT         2
#define CONTINUE         1

//Switch Cases

#define INSERT           1
#define DELETE           2
#define DISPLAY          3
#define EXIT             4

#define DEBUG0           0
#define DEBUG1           1



typedef struct QueueNode
{
  struct QueueNode *LLink;
  void *Data;
  struct QueueNode *Rlink;
} QueueNode_t;

typedef struct Queue
{
  QueueNode_t *Rear;
  QueueNode_t *Front;
} Queue_t;

//Function Operating on the Queue
void Initialise(Queue_t *Q)
void DestroyQueue(Queue_t *Q);
void *DisplayQueue(Queue_t *Q, void (*Print)(void *Data));
int Insert(Queue_t *Q, void *Element);
void *Delete(Queue_t *Q);
int CountNodes(Queue_t *Q);

#endif
