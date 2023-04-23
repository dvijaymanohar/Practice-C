/* HEADER FILE FOR LINKED LIST */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node
{
  void *data;
  struct node *next;
};

struct node *ll_create();
int ll_insert_first(struct node *, void *);
int ll_insert_last(struct node *, void *);
int ll_insert_before(struct node *head, void *b4_data_ptr, void *new_data_ptr);
int ll_insert_after(struct node *head, void *aft_data_ptr, void *new_data_ptr);
void *ll_delete_first(struct node *head);
void *ll_delete_last(struct node *head);
void *ll_delete_before(struct node *head, void *b4_data_ptr);
void *ll_delete_after(struct node *head, void *aft_data_ptr);
void *ll_delete_element(struct node *head, void *data_ptr);
void ll_print(struct node *head, void (*func)(void *));
void ll_destroy(struct node *);

#endif



