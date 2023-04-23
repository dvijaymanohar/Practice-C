# include <stdio.h>
# include <stdlib.h>
# include "linkedlist.h"

int main()
{
  int count, *inp, i, *temp, *temp1;
  struct llist *mylist, *temp2, *temp3;
  printf("Enter the number of elements\n");
  scanf("%d", &count);
  inp = malloc(count * sizeof(int));
  
  for (i = 0; i < count; i++)
  {
    scanf("%d", &inp[i]);
  }
  
  mylist = llist_create();
  add_first(mylist, &inp[0]);
  
  for (i = 1; i < count; i++)
  {
    temp2 = mylist;
    
    while (temp2->next != NULL)
    {
      temp3 = temp2;
      temp = (int *)temp2->next->element;
      
      if (inp[i] >= *temp)
      {
        temp2 = temp2->next;
      }
      else
      {
        break;
      }
    }
    
    add_next(mylist, temp2->element, &inp[i]);
  }
  
  while (mylist->next != NULL)
  {
    mylist = mylist->next;
    temp = (int *)mylist->element;
    printf("%d", *temp);
  }
  
  return 0;
}



/*
  for(i = 0; i < count; i++)
  {
    printf("%d", inp[i]);
  }
*/
