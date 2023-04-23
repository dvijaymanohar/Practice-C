# include <stdlib.h>
# include "d_l_list.h"

struct d_l_list *d_l_list_create(void)
{
  struct d_l_list *mydllist;
  mydllist = malloc(sizeof(struct d_l_list));
  mydllist->element = malloc(sizeof(void *));
  mydllist->pre = NULL;
  mydllist->next = NULL;
  return mydllist;
}

void add_first(struct d_l_list *mydllist, void *element)
{
  struct d_l_list *temp;
  temp = malloc(sizeof(struct d_l_list));
  temp->element = element;
  temp->pre = mydllist;
  temp->next = NULL;
  mydllist->next = temp;
}

void add_last(struct d_l_list *mydllist, void *element)
{
  struct d_l_list *temp;
  temp = malloc(sizeof(struct d_l_list));
  temp->element = element;
  temp->next = NULL;
  
  if (mydllist->next != NULL)
  {
    mydllist = mydllist->next;
  }
  
  mydllist->next = temp;
  temp->pre = mydllist;
}


int add_next(struct d_l_list *mydllist, void *pointing, void *to_be_added)
{
  struct d_l_list *temp, *temp1;
  temp = malloc(sizeof(struct d_l_list));
  temp->element = to_be_added;
  mydllist = mydllist->next;
  
  while (mydllist->element != pointing)
  {
    if (mydllist->next == NULL)
    {
      return 0;
    }
    
    mydllist = mydllist->next;
  }
  
  temp1 = mydllist->next;
  temp->pre = mydllist;
  mydllist->next = temp;
  temp->next = temp1;
  temp1->pre = temp;
  return 1;
}

/*
void add_before(struct d_l_list *mydllist, void *pointing, void *to_be_added)
{
  struct d_l_list *temp;
  temp = malloc(sizeof(struct d_l_list));
  temp->element = to_be_added;


/*
void *delete_first(struct d_l_list *);
void *delete_last(struct d_l_list *);
void *delete_next(struct d_l_list *, void *);
void *delete_before(struct d_l_list *, void *);
void delete_particular(struct d_l_list *, void *);

void print_d_l_list(struct d_l_list *, void (*printing)(*void));

void destroy_complete(struct d_l_list *);

#endif
*/
