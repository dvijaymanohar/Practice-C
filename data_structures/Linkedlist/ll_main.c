/* PROGRAM TO VERIFY THE LINKED LIST OPERATIONS */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void gen_print(void *);
int gen_cmp(void *, void *);

int main()
{
  int status;
  struct node *head_ptr;
  int *data_ptr, cmp_data;
  void (*func)(void *);
  int (*cmpfunc)(void *, void *);
  //CREATE LINKED LIST
  head_ptr = ll_create();
  
  //INSERTING AN ELEMENT AT THE BEGINING
  
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
  
  //INSERTING AN ELEMENT AT THE LAST
  
  while (1)
  {
    while (getchar() != '\n'); //clear the input buffer
    
    data_ptr = malloc(sizeof(int));
    printf("\nEnter the integer element to be stored at the end : ");
    scanf("%d", data_ptr);
    status = ll_insert_last(head_ptr, (void *)data_ptr);
    
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
  }
  
  //PRINT THE ELEMENTS IN THE LINKED LIST
  ll_print(head_ptr, func);
  //INSERT AN ELEMENT BEFORE A GIVEN ELEMENT
  cmpfunc = gen_cmp;
  
  while (1)
  {
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Enter the element before which a new element is to be inserted : ");
    scanf("%d", &cmp_data);
    
    while (getchar() != '\n'); //clear the input buffer
    
    data_ptr = malloc(sizeof(int));
    printf("Enter the integer element to be stored before %d : ", cmp_data);
    scanf("%d", data_ptr);
    status = ll_insert_before(head_ptr, (void *)&cmp_data, (void *)data_ptr, cmpfunc);
    
    if (status == 0)
    {
      printf("%d does not exist / No linked list created\n", cmp_data);
    }
    
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Do you want to continue (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
  }
  
  //PRINT THE ELEMENTS IN THE LINKED LIST
  ll_print(head_ptr, func);
  
  //INSERT AN ELEMENT AFTER A GIVEN ELEMENT
  
  while (1)
  {
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Enter the element after which a new element is to be inserted : ");
    scanf("%d", &cmp_data);
    
    while (getchar() != '\n'); //clear the input buffer
    
    data_ptr = malloc(sizeof(int));
    printf("Enter the integer element to be stored after %d : ", cmp_data);
    scanf("%d", data_ptr);
    status = ll_insert_after(head_ptr, (void *)&cmp_data, (void *)data_ptr, cmpfunc);
    
    if (status == 0)
    {
      printf("%d does not exist / No linked list created\n", cmp_data);
    }
    
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Do you want to continue (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
  }
  
  //PRINT THE ELEMENTS IN THE LINKED LIST
  ll_print(head_ptr, func);
  
  //DELETE AN ELEMENT BEFORE A GIVEN ELEMENT
  
  while (1)
  {
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Enter the element before which the element is to be deleted : ");
    scanf("%d", &cmp_data);
    data_ptr = ll_delete_before(head_ptr, (void *)&cmp_data, cmpfunc);
    
    if (data_ptr == NULL)
    {
      printf("Delete failed\n");
    }
    else
    {
      free(data_ptr);
    }
    
    ll_print(head_ptr, func); //print the elements in the linked list
    
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Do you want to continue (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
  }
  
  //DELETE AN ELEMENT AFTER A GIVEN ELEMENT
  
  while (1)
  {
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Enter the element after which the element is to be deleted : ");
    scanf("%d", &cmp_data);
    data_ptr = ll_delete_after(head_ptr, (void *)&cmp_data, cmpfunc);
    
    if (data_ptr == NULL)
    {
      printf("Delete failed\n");
    }
    else
    {
      free(data_ptr);
    }
    
    ll_print(head_ptr, func); //print the elements in the linked list
    
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Do you want to continue (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
  }
  
  //DELETE A GIVEN ELEMENT
  
  while (1)
  {
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Enter the element which is to be deleted : ");
    scanf("%d", &cmp_data);
    data_ptr = ll_delete_element(head_ptr, (void *)&cmp_data, cmpfunc);
    
    if (data_ptr == NULL)
    {
      printf("Delete failed\n");
    }
    else
    {
      free(data_ptr);
    }
    
    ll_print(head_ptr, func); //print the elements in the linked list
    
    while (getchar() != '\n'); //clear the input buffer
    
    printf("Do you want to continue (y/n) : ");
    
    if (getchar() != 'y')
    {
      break;
    }
  }
  
  //DESTROY THE LIST
  ll_destroy(head_ptr);
  return 0;
}



void gen_print(void *data_ptr)
{
  printf("%d\n", *(int *)data_ptr);
}



int gen_cmp(void *data1, void *data2) //return true on success else return false
{
  if (*(int *)data1 == *(int *)data2)
  {
    return 1;  //true
  }
  else
  {
    return 0;  //false
  }
}
