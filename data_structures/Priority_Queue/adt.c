#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0

struct queue *head = NULL, *newnode = NULL, *temp = NULL, *rear = NULL, *front = NULL;


int enqueue(int n)
{
  newnode = (struct queue *) malloc(sizeof(struct queue));
  
  if (newnode == NULL) { return 0; } //If malloc couln't allocate enough memory for newnode
  
  newnode->data = n;
  
  if (head == NULL)
  {
    head = newnode;
    //Insertions at rear and Deletions at front -- FIFO
    rear = front = head;
    head->llink = rear->llink = NULL;
    head->rlink = rear->rlink = NULL;
  }
  else
  {
    temp = head;
    
    while (temp->rlink != NULL) { temp = temp->rlink; }
    
    temp->rlink = newnode;
    newnode->llink = temp;
    temp = newnode;
    temp->rlink = NULL;
    rear = temp;
  }
  
  return 1;
}


int dequeue(void)
{
  int ret;
  
  if (head == NULL) { return -1; }
  
  if (head->rlink == NULL)
  {
    ret = front->data;
    free(front);
    front = head = NULL;
    return ret;
  }
  
  head = head->rlink;
  ret = front->data;
  free(front);
  front = head;
  head->llink = NULL;
  return ret;
}

int dispose_queue(void)
{
  while (NULL == head) { return -1; }
  
  if (NULL == head->rlink)
  {
    free(head);
    front = temp = rear = head = NULL;
    return 1;
  }
  
  temp = head;
  
  while (temp != NULL)
  {
    front = temp;
    front->llink = front->rlink = NULL;
    free(front);
    temp = temp->rlink;
  }
  
  head->llink = head->rlink = NULL;
  temp = rear = front = head;
  return 1;
}



void display_queue(void)
{
  temp = rear;  //As we have to print from backside
  printf("\n\tQueued Elements\n");
  
  if (head == NULL) //If no elements are there in the queue
  {
    printf("\n\tEmpty Queue");
    return;
  }
  
  if (head->rlink == NULL)  //If only one node exits
  {
    printf("\t%d", temp->data);
    
    if (DEBUG) { printf("\n\tDisplay Queue\n"); }
    
    return ;
  }
  
  if (DEBUG) { printf("\n\tDisplay Queue: %d\n", rear->data); }
  
  if (DEBUG) { printf("\n\tDisplay Queue: %d\n", rear->llink->data); }
  
  while (temp != NULL)
  {
    printf("\t%d", temp->data);
    temp = temp->llink;
  }
}
