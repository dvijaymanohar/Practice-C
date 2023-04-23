#ifndef D_L_LIST_H
#define D_L_LIST_H
struct d_l_list
{
  struct d_l_list *pre;
  void **element;
  struct d_l_list *next;
};

struct d_l_list *d_l_list_create(void);

void add_first(struct d_l_list *, void *);
void add_last(struct d_l_list *, void *);
int add_next(struct d_l_list *, void *, void *);
void add_before(struct d_l_list *, void *, void *);

void *delete_first(struct d_l_list *);
void *delete_last(struct d_l_list *);
void *delete_next(struct d_l_list *, void *);
void *delete_before(struct d_l_list *, void *);
void delete_particular(struct d_l_list *, void *);

//void print_d_l_list(struct d_l_list *, void (*printing)(*void));

void destroy_complete(struct d_l_list *);

#endif
