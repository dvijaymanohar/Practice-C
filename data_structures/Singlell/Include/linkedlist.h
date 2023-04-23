#ifndef LLIST_H
#define LLIST_H
struct llist
{
  void **element;
  struct llist *next;
};

struct llist *llist_create(void);

void add_first(struct llist *, void *);
void add_last(struct llist *, void *);
void add_next(struct llist *, void *, void *);
void add_before(struct llist *, void *, void *);

void *delete_first(struct llist *);
void *delete_last(struct llist *);
void *delete_next(struct llist *, void *);
void *delete_before(struct llist *, void *);
void delete_particular(struct llist *, void *);

void print_llist(struct llist *, void (*printing)(*void));

void destroy_complete(struct llist *);

#endif
