/* PROGRAM TO IMPLEMENT INSERTION SORT */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void gen_print(void *);

int main()
{
  struct node *head_ptr, *nxt_node, *pnode, *ptr1, *ptr2;
  int *data_ptr;
  int status;
  void (*func)(void *);
  //CREATE THE LINKED LIST
  head_ptr = ll_create();
  
  //INSERT THE ELEMENTS AT THE BEGINING OF THE LINKED LIST
  
  while (1)
  {
    data_ptr = malloc(sizeof(int));
    printf("\nEnter the integer element to be stored at the begining : ");
    scanf("%d", data_ptr);
    status = ll_insert_first(head_ptr, (void *)data_ptr);
    
    if (status == 0)
    {
      printf("No linked list created\n");
    }
    
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Do you want to continue (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
    
    while (getchar() != '\n'); //clear the input buffer
  }
  
  //PRINT THE ELEMENTS IN THE LINKED LIST
  func = gen_print;
  ll_print(head_ptr, func);
  
  if (head_ptr == NULL || head_ptr->next == NULL)
  {
    printf("Linked list not created/empty");
    exit(1);
  }
  
  nxt_node = head_ptr->next;
  
  while (nxt_node->next != NULL)
  {
    pnode = head_ptr;
    
    while (pnode != nxt_node)
    {
      if (pnode->next->data > nxt_node->next->data)
      {
        //swap
        ptr1 = nxt_node->next;
        nxt_node->next = nxt_node->next->next;
        ptr1->next = pnode->next;
        pnode->next = ptr1;
        break;
      }
      else
      {
        pnode = pnode->next;
      }
    }
    
    nxt_node = nxt_node->next;
  }
  
  //PRINT THE ELEMENTS IN THE LINKED LIST
  ll_print(head_ptr, func);
  return 0;
}



void gen_print(void *data_ptr)
{
  printf("%d\n", *(int *)data_ptr);
}
