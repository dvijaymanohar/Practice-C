#ifndef linklist_H
#define linklist_H

struct linklist
{
  void **data;
  struct linklist *next;
};

struct linklist *linklist_create();

void linklist_insert_frist(struct linklist *, void *);
void linklist_insert_last(struct linklist *, void *);
void linklist_insert_before(struct linklist *, void *, int position);
void linklist_insert_after(struct linklist *, void *, int position);

void *linklist_delete_frist(struct linklist *);
void *linklist_delete_last(struct linklist *);
void *linklist_delete_before(struct linklist *, int position);
void *linklist_delete_after(struct linklist *, int position);

void linklist_print(struct linklist *);
void linklist_destroy(struct linklist *);


#endif
