#include<stdio.h>
#include<stdlib.h>
#include "link.h"
#include <string.h>

struct link *link_create()
{
  struct link *head;
  head  = (struct link *)malloc(sizeof(struct link)) ;
  head->next = NULL;
  head->data = NULL;
  return (head);
}

void *link_first_insert(struct link *head, void *val)
{
  struct link *node;
  node = (struct link *)malloc(sizeof(struct link));
  node->data = (void *)malloc(sizeof(int));
  node->data = val;
  node->next = head->next;
  return val;
}

void *link_last_insert(struct link *head, void *val)
{
  struct link *node;
  node = (struct link *)malloc(sizeof(struct link));
  node->data = (void *)malloc(sizeof(int));
  /*  while(head->next != NULL);
    {
      head = head->next;
    }*/
  node->data = val ;
  node->next = head->next;
  //  head->next = node;
  node->next = NULL;
  return val;
}

void *link_after_insert(struct link *head, void *val, int a)
{