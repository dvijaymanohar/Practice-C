#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

struct linked_list *ll_create(void)
{
  struct linked_list *head;
  struct linked_list *node;
  head = (struct linked_list *) malloc(sizeof(struct linked_list));
  head->data = NULL;
  head->next = NULL;
  return (head);
}

void *insert_first(struct linked_list *head, void *data)
{
  struct linked_list *node;
  node = (struct linked_list *) malloc(sizeof(struct linked_list));
  head->next = node->next;
  node->data = data;
  return (node->data);
}

void *insert_last(struct linked_list *head, void *data)
{
  struct linked_list *nnode;
  struct linked_list *newnode;
  nnode = head;
  
  while (nnode->next != NULL)
  {
    nnode = nnode->next;
  };
  
  newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  
  newnode->data = data;
  
  nnode->next = newnode;
  
  newnode->next = NULL;
  
  return (newnode->data);
}

void *insert_before(struct linked_list *head, void *data, void *input)
{
  struct linked_list *nnode;
  struct linked_list *newnode;
  struct linked_list *prev_node;
  nnode = head;
  
  while (nnode->data != data)
  {
    nnode = nnode->next;
  };
  
  newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  
  prev_node = (struct linked_list *) malloc(sizeof(struct linked_list));
  
  newnode->data = data;
  
  prev_node->next = newnode;
  
  newnode->next = nnode;
  
  return (newnode->data);
}

void *insert_after(struct linked_list *head, void *data, void *input)
{
  struct linked_list *nnode;
  struct linked_list *newnode;
  nnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  nnode = head;
  
  while (nnode->data != data)
  {
    nnode = nnode->next;
  };
  
  newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  
  nnode->next = newnode;
  
  newnode->data = data;
  
  newnode->next = nnode->next;
  
  return (newnode->data);
}

void *delete_first(struct linked_list *head)
{
  struct linked_list *nnode;
  nnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  head = nnode;
  head->next = nnode->next;
  return (nnode->data);
}

void *delete_last(struct linked_list *head)
{
  struct linked_list *nnode;
  struct linked_list *prev_node;
  nnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  nnode = head;
  
  while (nnode->next != NULL)
  {
    nnode = nnode->next;
  };
  
  prev_node = (struct linked_list *) malloc(sizeof(struct linked_list));
  
  prev_node->next = NULL;
  
  return (prev_node->data);
}

void *delete_after(struct linked_list *head, void *data)
{
  struct linked_list *nnode;
  nnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  nnode = head;
  
  while (nnode->next == data)
  {
    nnode = nnode->next;
  };
  
  nnode->next = nnode->next->next;
  
  return (nnode->data);
}

void *delete_before(struct linked_list *head, void *data)
{
  struct linked_list *nnode;
  struct linked_list *prev1_node;
  struct linked_list *prev2_node;
  nnode = (struct linked_list *) malloc(sizeof(struct linked_list));
  nnode = head;
  
  while (nnode-> next == data)
  {
    nnode = nnode->next;
  }
  
  prev1_node = (struct linked_list *) malloc(sizeof(struct linked_list));
  prev2_node = (struct linked_list *) malloc(sizeof(struct linked_list));
  prev2_node->next = nnode->next;
  return (prev1_node);
}

void ll_destroy(struct linked_list *head)
{
  struct linked_list *nnode;
  struct linked_list *temp;
  
  while (nnode->next != NULL)
  {
    temp = nnode;
    nnode = nnode->next;
    free(temp);
  };
  
  free(temp);
  
  return NULL;
}
