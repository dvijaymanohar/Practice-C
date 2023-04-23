#ifndef LINK_H
#define LINK_H

struct link
{
  void **data;
  struct node  *next;
};

struct link *link_create();
void  *link_first_insert(struct link *, void *);
void  *link_last_insert(struct link *, void *);
void  *link_after_insert(struct link *, void *, int);
void  *link_beforer_insert(struct link *, void *, int);
void  *link_delete_first(struct link *);
void  *link_delete_last(struct link *);
void  *link_delete_after(struct link *, int);
void  *link_delete_before(struct link *, int);
void  *link_print(struct link *);
void  link_destroy(struct link *);

#endif
