/* HEADER FILE CONTAINING THE PROTOTYPES OF FUNCTIONS PRESENT IN switch_func.c */

#ifndef SWITCH_FUNC_H
#define SWITCH_FUNC_H

void insert_first(struct node *head_ptr);
void insert_last(struct node *head_ptr);
void insert_before(struct node *head_ptr, int (*cmpfunc)(void *, void *));
void insert_after(struct node *head_ptr, int (*cmpfunc)(void *, void *));
void print(struct node *head_ptr, void (*func)(void *));
void delete_first(struct node *head_ptr);
void delete_last(struct node *head_ptr);
void delete_before(struct node *head_ptr, int (*cmpfunc)(void *, void *));
void delete_after(struct node *head_ptr, int (*cmpfunc)(void *, void *));
void delete_word(struct node *head_ptr, int (*cmpfunc)(void *, void *));
void clear(struct node *head_ptr);

#endif
