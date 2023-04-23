#include <stdio.h>
#include <stdlib.h>
#include "link.h"

struct link *link_create()
{
  struct link *head;
  head  = (struct link *)malloc(sizeof(struct link)) ;
  
  if (head != NULL)
  {
    head->next = NULL;
    head->data = NULL;
  }
  
  return (head);
}

void link_first_insert(struct link *head, void *val)
{
  struct link *node;
  node = (struct link *)malloc(sizeof(struct link));
  node->data = malloc(sizeof(void *));
  node->data = val;
  node->next = head->next;
  head->next = node;
  //  return val;
}

void link_last_insert(struct link *head, void *val)
{
  struct link *node;
  node = (struct link *)malloc(sizeof(struct link));
  node->data = malloc(sizeof(void *));
  
  while (head->next != NULL)
  {
    head  = head->next;
  }
  
  node->data = val ;
  node->next = head->next;
  head->next = node;
  //  return val;
}

void link_before_insert(struct link *head, void *val, int place)
{
  int i = 0;
  
  while (i < place - 1)
  {
    head = head->next;
    i++;
  }
  
  struct link *node;
  
  node = (struct link *)malloc(sizeof(struct link));
  
  node->data = malloc(sizeof(void *));
  
  node->data = val;
  
  node->next = head->next;
  
  head->next = node;
  
  //  return val;
}

void link_after_insert(struct link *head, void *val, int place)
{
  int i = 0;
  
  while (i < place)
  {
    head =  head->next;
    i++;
  }
  
  struct link *node;
  
  node = (struct link *)malloc(sizeof(struct link));
  
  node->data = malloc(sizeof(void *));
  
  node->data = val;
  
  node->next = head->next;
  
  head->next = node;
  
  //  return (val);
}

void *link_delete_first(struct link *head)
{
  struct link *node;
  void *val;
  node = head->next;
  head->next = node->next;
  val = node->data ;
  free(node);
  return val;
}


void *link_delete_last(struct link *head)
{
  while (head->next->next != NULL)
  {
    head = head->next;
  }
  
  struct link *node;
  
  void *val;
  
  node = head->next;
  
  head->next = node->next;
  
  val = node->data;
  
  free(node);
  
  return val;
}

void *link_delete_after(struct link *head, int place)
{
  int i = 0;
  
  while (i <  place)
  {
    head = head->next;
    i++;
  }
  
  struct link *node;
  
  void *val;
  
  node = head->next;
  
  head->next = node->next;
  
  val = node->data;
  
  return val;
}

void *link_delete_before(struct link *head, int place)
{
  int i = 0;
  void *val;
  
  while (i < place - 2)
  {
    head = head->next;
    i++;
  }
  
  struct link *node;
  
  node = head->next;
  
  head->next = node->next;
  
  val = node->data;
  
  free(node);
  
  return val;
}
void link_print(struct link  *head)
{
  while (head->next != NULL)
  {
    int *num;
    head = head->next;
    num = (int *)head->data;
    printf("\t%d\t", *num);
  }
}

void link_destroy(struct link *head)
{
  while (head->next != NULL)
  {
    head = head->next;
  }
  
  link_destroy(head);
  free(head->next);
}



