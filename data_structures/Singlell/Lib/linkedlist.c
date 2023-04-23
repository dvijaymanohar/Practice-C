#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

/* CREATING THE HEAD OF THE LINKED LIST AND MAKING THE NEXT TO POINT NULL */

struct llist *llist_create(void)
{
  struct llist *myllist;
  myllist = malloc(sizeof(struct llist));
  myllist->element = (void *)malloc(sizeof(void *));
  myllist->next = NULL;
  return myllist;
}

/* ADDING AN ELEMENT AT THE FIRST */

void add_first(struct llist *myllist, void *element)
{
  myllist->next = malloc(sizeof(struct llist *));
  myllist->next->element = malloc(sizeof(void *));
  myllist->next->next = NULL;
  myllist->next->element = element;
}

/* ADDING AN ELEMENT AT THE LAST */

void add_last(struct llist *myllist, void *element)
{
  struct llist *temp;
  temp = myllist->next;
  
  while (temp != NULL)
  {
    myllist = myllist->next;
    temp = myllist->next;
  }
  
  myllist->next = malloc(sizeof(struct llist *));
  myllist->next->element = malloc(sizeof(void *));
  myllist->next->next = NULL;
  myllist->next->element = element;
}

/* ADDING AN ELEMENT NEXT TO A PARTICULAR ELEMENT */

void add_next(struct llist *myllist, void *pointing, void *to_be_added)
{
  struct llist *temp;
  myllist = myllist->next;
  
  while (myllist->element != pointing)
  {
    myllist = myllist->next;
  }
  
  temp = myllist->next;
  myllist->next = malloc(sizeof(struct llist *));
  myllist->next->element = to_be_added;
  myllist->next->next = temp;
}

/* ADDING AN ELEMENT BEFORE A PARTICULAR ELEMENT */

void add_before(struct llist *myllist, void *pointing, void *to_be_added)
{
  struct llist *temp;
  temp = myllist;
  myllist = myllist->next;
  
  while (myllist->element != pointing)
  {
    temp = myllist;
    myllist = myllist->next;
  }
  
  myllist = temp;
  temp = myllist->next;
  myllist->next = malloc(sizeof(struct llist *));
  myllist->next->element = to_be_added;
  myllist->next->next = temp;
}

/* REMOVING THE FIRST ELEMENT FROM THE LINKEDLIST */

void *delete_first(struct llist *myllist)
{
  struct llist *temp;
  temp = myllist->next;
  
  if (temp != NULL)
  {
    myllist->next = temp->next;
    return temp->element;
  }
  else
  {
    return NULL;
  }
}

/* REMOVING THE LAST ELEMENT FROM THE LINKEDLIST */

void *delete_last(struct llist *myllist)
{
  struct llist *temp;
  temp = myllist->next;
  
  if (temp == NULL)
  {
    return NULL;
  }
  
  while (temp->next != NULL)
  {
    myllist = myllist->next;
    temp = temp->next;
  }
  
  myllist->next = NULL;
  return temp->element;
}

/* REMOVING AN ELEMENT NEXT TO A PARTICULAR ELEMENT */

void *delete_next(struct llist *myllist, void *pointing)
{
  void *temp;
  myllist = myllist->next;
  
  while (myllist->element != pointing)
  {
    myllist = myllist->next;
  }
  
  temp = myllist->next->element;
  myllist->next = myllist->next->next;
  return temp;
}

/* REMOVING AN ELEMENT BEFORE A PARTICULAR ELEMENT */

void *delete_before(struct llist *myllist, void *pointing)
{
  struct llist *temp;
  
  if ((myllist->next->element == pointing) || (myllist->next == NULL))
  {
    return NULL;
  }
  
  while (myllist->next->next->element != pointing)
  {
    myllist = myllist->next;
  }
  
  temp = myllist->next->element;
  myllist->next = myllist->next->next;
  return temp;
}

/* REMOVING A PARTICULAR ELEMENT */

void delete_particular(struct llist *myllist, void *pointing)
{
  struct llist *temp;
  temp = myllist;
  myllist = myllist->next;
  
  if (myllist->element != pointing)
  {
    myllist = myllist->next;
    temp = temp->next;
  }
  
  myllist = temp;
  myllist->next = myllist->next->next;
}

/* DESTROYING THE COMPLETE LINKED LIST */

void destroy_complete(struct llist *myllist)
{
  while (myllist->next != NULL)
  {
    myllist = myllist->next;
    destroy_complete(myllist);
    free(myllist->next);
  }
}

void print_llist(struct llist *myllist, void (*printing)(*void))
{