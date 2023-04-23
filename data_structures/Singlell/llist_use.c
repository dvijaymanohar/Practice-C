# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "linkedlist.h"

void print(void *element);

int main()
{
  int *input, status, *output, *temp1, *temp2;
  struct llist *myllist;
  void (*printing)(void *);
  printing = print;
  input = malloc(sizeof(int));
  myllist = llist_create();
  printf("Enter element to add to first\n");
  scanf("%d", input);
  temp1 = input;
  add_first(myllist, input);
  printf("Enter the element to add to last\n");
  input = malloc(sizeof(int));
  scanf("%d", input);
  add_last(myllist, input);
  
  while (*input != 0)
  {
    printf("Enter the element to add to last\n");
    input = malloc(sizeof(int));
    scanf("%d", input);
    add_last(myllist, input);
  }
  
  printf("Enter the element to add next to an element\n");
  input = malloc(sizeof(int));
  scanf("%d", input);
  add_next(myllist, temp1, input);
  printf("Enter the element to add before an element\n");
  input = malloc(sizeof(int));
  scanf("%d", input);
  add_before(myllist, temp1, input);
  output = (int *)delete_first(myllist);
  printf("%d is the deleted item: first\n", *output);
  output = delete_last(myllist);
  printf("%d is the deleted item: last\n", *output);
  output = delete_next(myllist, temp1);
  
  if (output != NULL)
  {
    temp2 = output;
    printf("%d is the deleted item: next\n", *temp2);
  }
  
  output = delete_before(myllist, temp1);
  
  if (output != NULL)
  {
    temp2 = output;
    printf("%d is the deleted item: before\n", *temp2);
  }
  else
  {
    printf("\n There is nothing to delete\n");
  }
  
  delete_particular(myllist, temp1);
  destroy_complete(myllist);
  return 0;
}

void print(void *element)
{
  int *element1;
  
  if (element != NULL)
  {
    element1 = (int *)element;
    printf("%d", *element1);
  }
}
