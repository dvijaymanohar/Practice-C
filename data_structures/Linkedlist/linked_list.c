/* FUNCTIONS TO IMPLEMENT LINKED LIST OPERATIONS */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


//FUNCTION TO CREATE A LINKED LIST

struct node *ll_create()
{
  struct node *head;
  head = calloc(1, sizeof(struct node *));
  return (head);
}


//FUNCTION TO INSERT AN ELEMENT AT THE BEGINING

int ll_insert_first(struct node *head, void *data_ptr)
{
  struct node *new_node;
  
  if (head == NULL)
  {
    return 0;
  }
  
  new_node = malloc(sizeof(struct node *));
  new_node->data = data_ptr;
  new_node->next = head->next;
  head->next = new_node;
  return 1;
}


//FUNCTION TO INSERT A GIVEN ELEMENT AT THE END OF THE LINKED LIST

int ll_insert_last(struct node *head, void *data_ptr)
{
  struct node *inode = head, *new_node;
  
  if (head == NULL)
  {
    return 0;
  }
  
  while (inode->next != NULL) //get the last node
  {
    inode = inode->next;
  }
  
  new_node = malloc(sizeof(struct node *));
  new_node->data = data_ptr;
  new_node->next = NULL;
  inode->next = new_node;
  return 1;
}


//FUNCTION TO INSERT AN ELEMENT BEFORE A GIVEN ELEMENT

int ll_insert_before(struct node *head, void *b4_data_ptr, void *new_data_ptr, int (*cmpfunc)(void *, void *))
{
  struct node *new_node, *bef2_node = head;
  
  if (head == NULL)
  {
    return 0;
  }
  
  while (bef2_node->next != NULL)
    if (!(cmpfunc(bef2_node->next->data, b4_data_ptr)))
    {
      bef2_node = bef2_node->next;
    }
    else
    {
      new_node = malloc(sizeof(struct node));
      new_node->data = new_data_ptr;
      new_node->next = bef2_node->next;
      bef2_node->next = new_node;
      return 1;
    }
    
  return 0;
}


//FUNCTION TO INSERT AN ELEMENT AFTER A GIVEN ELEMENT

int ll_insert_after(struct node *head, void *aft_data_ptr, void *new_data_ptr, int (*cmpfunc)(void *, void *))
{
  struct node *new_node, *aft_node = head;
  
  if (head == NULL)
  {
    return 0;
  }
  
  while (aft_node->next != NULL)
    if (!(cmpfunc(aft_node->next->data, aft_data_ptr)))
    {
      aft_node = aft_node->next;
    }
    else
    {
      aft_node = aft_node->next;
      new_node = malloc(sizeof(struct node));
      new_node->data = new_data_ptr;
      new_node->next = aft_node->next;
      aft_node->next = new_node;
      return 1;
    }
    
  return 0;
}


//FUNCTION TO DELETE THE FIRST ELEMENT FROM THE LINKED LIST

void *ll_delete_first(struct node *head)
{
  struct node *dnode;
  void *data_ptr;
  
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  
  dnode = head->next;
  head->next = dnode->next;
  data_ptr = dnode->data;
  free(dnode);
  return data_ptr;
}


//FUNCTION TO DELETE THE LAST ELEMENT FROM THE LINKED LIST

void *ll_delete_last(struct node *head)
{
  struct node *dnode = head;
  void *data_ptr;
  
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  
  while (dnode->next->next != NULL) //get the last but one node
  {
    dnode = dnode->next;
  }
  
  data_ptr = dnode->next->data;
  free(dnode->next);
  dnode->next = NULL;
  return data_ptr;
}


//FUNCTION TO DELETE AN ELEMENT BEFORE A GIVEN ELEMENT

void *ll_delete_before(struct node *head, void *b4_data_ptr, int (*cmpfunc)(void *, void *))
{
  struct node *bef2_node, *bef2bef_node;
  
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  
  bef2_node = head->next;
  bef2bef_node = head;
  
  while (bef2_node->next != NULL)
    if (!(cmpfunc(bef2_node->next->data, b4_data_ptr)))
    {
      bef2bef_node = bef2_node;
      bef2_node = bef2_node->next;
    }
    else
    {
      b4_data_ptr = bef2_node->data;
      bef2bef_node->next = bef2_node->next;
      free(bef2_node);
      return b4_data_ptr;
    }
    
  return NULL;
}


//FUNCTION TO DELETE AN ELEMENT AFTER A GIVEN ELEMENT

void *ll_delete_after(struct node *head, void *aft_data_ptr, int (*cmpfunc)(void *, void *))
{
  struct node *aft_node;
  void *nxt_ptr;
  
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  
  aft_node = head->next;
  
  while (aft_node->next != NULL)
    if (!(cmpfunc(aft_node->data, aft_data_ptr)))
    {
      aft_node = aft_node->next;
    }
    else
    {
      aft_data_ptr = aft_node->next->data;
      nxt_ptr = aft_node->next->next;
      free(aft_node->next);
      aft_node->next = nxt_ptr;
      return aft_data_ptr;
    }
    
  return NULL;
}


//FUNCTION TO DELETE A GIVEN ELEMENT

void *ll_delete_element(struct node *head, void *data_ptr, int (*cmpfunc)(void *, void *))
{
  struct node *dnode = head;
  void *nxt_ptr;
  
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }
  
  while (dnode->next != NULL)
    if (!(cmpfunc(dnode->next->data, data_ptr)))
    {
      dnode = dnode->next;
    }
    else
    {
      data_ptr = dnode->next->data;
      nxt_ptr = dnode->next->next;
      free(dnode->next);
      dnode->next = nxt_ptr;
      return data_ptr;
    }
    
  return NULL;
}


//FUNCTION TO PRINT THE ELEMENTS IN THE LINKED LIST

void ll_print(struct node *head, void (*func)(void *))
{
  struct node *pnode = head;
  
  if (pnode == NULL || pnode->next == NULL)
  {
    printf("Error: Linked list is empty / Linked list not created.\n");
    return;
  }
  
  printf("The element(s) in the linked list is/are :\n");
  
  do
  {
    func(pnode->next->data);
    pnode = pnode->next;
  }
  while (pnode->next != NULL);
}


//DESTROY THE LINKED LIST

void ll_destroy(struct node *head)
{
  struct node *dnode;
  
  while (head != NULL)
  {
    dnode = head->next;
    free(head);
    head = dnode;
  }
}
