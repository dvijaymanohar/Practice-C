#ifndef LINK_H
#define LINK_H

struct link
{
  void **data;
  struct link *next;
};

struct link *link_create();
void  link_first_insert(struct link *, void *);
void  link_last_insert(struct link *, void *);
void  link_before_insert(struct link *, void *, int place);
void  link_after_insert(struct link *, void *, int place);

void *link_delete_first(struct link *);
void *link_delete_last(struct link *);
void *link_delete_after(struct link *, int place);
void *link_delete_before(struct link *, int place);

void  link_print(struct link *);
void  link_destroy(struct link *);

#endif
