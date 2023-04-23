# include <stdio.h>
# include <stdlib.h>
# include "d_l_list.h"

int main()
{
  int *input, *output, *temp, status;
  struct d_l_list *mydllist;
  output = malloc(sizeof(int));
  mydllist = d_l_list_create();
  printf("Enter the input\n");
  input = malloc(sizeof(int));
  scanf("%d", input);
  temp = input;
  add_first(mydllist, input);
  printf("Enter the input\n");
  input = malloc(sizeof(int));
  scanf("%d", input);
  add_last(mydllist, input);
  printf("Enter the input\n");
  input = malloc(sizeof(int));
  scanf("%d", input);
  status = add_next(mydllist, temp, output);
  
  if (status == 0)
  {
    printf("Element not found\n");
  }
  else
  {
    printf("Element found\n");
  }
  
  while (mydllist->next != NULL)
  {
    mydllist = mydllist->next;
    output = (int *)mydllist->element;
    printf("%d\n", *output);
  }
  
  return 0;
}
