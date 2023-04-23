#include<stdio.h>
#include<stdlib.h>
#include"list.h"

struct linklist *linklist_create()
{
  struct linklist *list;
  list = (struct linklist *) malloc(sizeof(struct linklist));
  
  if (list != NULL)
  {
    list->next = NULL;
    list->data = NULL;
  }
  
  return list;
}

void linklist_insert_frist(struct linklist *list, void *val)
{
  struct linklist *node;
  node = (struct linklist *) malloc(sizeof(struct linklist));
  node->data = malloc(sizeof(void *));
  node->data = val;
  node->next = list->next;
  list->next = node;
}

void linklist_insert_last(struct linklist *list, void *val)
{
  struct linklist *node;
  node = (struct linklist *) malloc(sizeof(struct linklist));
  node->data = malloc(sizeof(void *));
  
  while (list->next != NULL)
  {
    list = list->next;
  }
  
  node->data = val;
  node->next = list->next;
  list->next = node;
}

void linklist_insert_before(struct linklist *list, void *val, int position)
{
  int i = 0;
  
  while (i < position - 1)
  {
    list = list->next;
    i++;
  }
  
  struct linklist *node;
  
  node = (struct linklist *) malloc(sizeof(struct linklist));
  
  node->data = malloc(sizeof(void *));
  
  node->data = val;
  
  node->next = list->next;
  
  list->next = node;
}

void linklist_insert_after(struct linklist *list, void *val, int position)
{
  int i = 0;    printf("%d    %d", i, position);
  
  while (i < position)
  {
    list = list->next;
    i++;
    printf("%d    %d", i, position);
  }
  
  struct linklist *node;
  
  node = (struct linklist *) malloc(sizeof(struct linklist));
  
  node->data = malloc(sizeof(void *));
  
  node->data = val;
  
  node->next = list->next;
  
  list->next = node;
}

void *linklist_delete_frist(struct linklist *list)
{
  struct linklist *node;
  void *val;
  node = list->next;
  list->next = node->next;
  val = node->data;
  free(node);
  return val;
}

void *linklist_delete_last(struct linklist *list)
{
  struct linklist *node;
  void *val;
  
  while (list->next->next != NULL)
  {
    list = list->next;
  }
  
  node = list->next;
  list->next = node->next;
  val = node->data;
  free(node);
  return val;
}

void *linklist_delete_before(struct linklist *list, int position)
{
  int i = 0;
  
  while (i < position - 2)
  {
    list = list->next;
    i++;
  }
  
  struct linklist *node;
  
  void *val;
  
  node = list->next;
  
  list->next = node->next;
  
  val = node->data;
  
  free(node);
  
  return val;
}

void *linklist_delete_after(struct linklist *list, int position)
{
  int i = 0;
  
  while (i < position)
  {
    list = list->next;
    i++;
  }
  
  struct linklist *node;
  
  void *val;
  
  node = list->next;
  
  list->next = node->next;
  
  val = node->data;
  
  free(node);
  
  return val;
}

void linklist_print(struct linklist *list)
{
  while (list->next != NULL)
  {
    int *p;
    list = list->next;
    p = (int *)list->data;
    printf("%d\t", *p);
  }
  
  printf("\n");
}
