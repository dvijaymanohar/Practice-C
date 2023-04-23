/* CONTAINS THE FUNCTIONS USED IN ll_strings.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

extern int gen_print(void *);
extern int gen_cmp(void *, void *);


//INSERT FIRST

void insert_first(struct node *head_ptr)
{
  int status;
  char data[20], *data_ptr;
  printf("\nEnter the word to be stored at the begining : ");
  scanf("%s", data);
  
  while (getchar() != '\n');  //clear the input buffer
  
  data_ptr = (char *)malloc(sizeof(strlen(data) + 1));
  strcpy(data_ptr, data);
  status = ll_insert_first(head_ptr, (void *)data_ptr);
  
  if (status == 0)
  {
    printf("No linked list created\n");
  }
}


//INSERT LAST

void insert_last(struct node *head_ptr)
{
  int status;
  char data[20], *data_ptr;
  printf("\nEnter the word to be stored at the end : ");
  scanf("%s", data);
  
  while (getchar() != '\n');  //clear the input buffer
  
  data_ptr = (char *)malloc(sizeof(strlen(data) + 1));
  strcpy(data_ptr, data);
  status = ll_insert_last(head_ptr, (void *)data_ptr);
  
  if (status == 0)
  {
    printf("No linked list created\n");
  }
}


//INSERT BEFORE A GIVEN WORD

void insert_before(struct node *head_ptr, int (*cmpfunc)(void *, void *))
{
  int status;
  char cmp_data[20], temp_data[20], *data_ptr;
  printf("Enter the word before which a new word is to be inserted : ");
  scanf("%s", cmp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  printf("Enter the word to be stored before \'%s\' : ", cmp_data);
  scanf("%s", temp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  data_ptr = (char *)malloc(sizeof(strlen(temp_data) + 1));
  strcpy(data_ptr, temp_data);
  status = ll_insert_before(head_ptr, (void *)&cmp_data, (void *)data_ptr, cmpfunc);
  
  if (status == 0)
  {
    printf("\'%s\' does not exist\n", cmp_data);
  }
}


//INSERT AFTER A GIVEN WORD

void insert_after(struct node *head_ptr, int (*cmpfunc)(void *, void *))
{
  int status;
  char cmp_data[20], temp_data[20], *data_ptr;
  printf("Enter the word after which a new word is to be inserted : ");
  scanf("%s", cmp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  printf("Enter the word to be stored after \'%s\' : ", cmp_data);
  scanf("%s", temp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  data_ptr = (char *)malloc(sizeof(strlen(temp_data) + 1));
  strcpy(data_ptr, temp_data);
  status = ll_insert_after(head_ptr, (void *)&cmp_data, (void *)data_ptr, cmpfunc);
  
  if (status == 0)
  {
    printf("\'%s\' does not exist\n", cmp_data);
  }
}


//PRINT THE WORDS

void print(struct node *head_ptr, void (*func)(void *))
{
  ll_print(head_ptr, func);
}


//DELETE FIRST WORD

void delete_first(struct node *head_ptr)
{
  char *data_ptr;
  data_ptr = ll_delete_first(head_ptr);
  
  if (data_ptr == NULL)
  {
    printf("Delete failed\n");
  }
  else
  {
    free(data_ptr);
  }
}


//DELETE LAST WORD

void delete_last(struct node *head_ptr)
{
  char *data_ptr;
  data_ptr = ll_delete_last(head_ptr);
  
  if (data_ptr == NULL)
  {
    printf("Delete failed\n");
  }
  else
  {
    free(data_ptr);
  }
}


//DELETE A WORD BEFORE A GIVEN WORD

void delete_before(struct node *head_ptr, int (*cmpfunc)(void *, void *))
{
  char cmp_data[20], *data_ptr;
  printf("Enter the word whose previous word is to be deleted : ");
  scanf("%s", cmp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  data_ptr = ll_delete_before(head_ptr, (void *)cmp_data, cmpfunc);
  
  if (data_ptr == NULL)
  {
    printf("Delete failed\n");
  }
  else
  {
    free(data_ptr);
  }
}


//DELETE A WORD AFTER A GIVEN WORD

void delete_after(struct node *head_ptr, int (*cmpfunc)(void *, void *))
{
  char cmp_data[20], *data_ptr;
  printf("Enter the word whose next word is to be deleted : ");
  scanf("%s", cmp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  data_ptr = ll_delete_after(head_ptr, (void *)cmp_data, cmpfunc);
  
  if (data_ptr == NULL)
  {
    printf("Delete failed\n");
  }
  else
  {
    free(data_ptr);
  }
}


//DELETE A GIVEN WORD

void delete_word(struct node *head_ptr, int (*cmpfunc)(void *, void *))
{
  char cmp_data[20], *data_ptr;
  printf("Enter the word to be deleted : ");
  scanf("%s", cmp_data);
  
  while (getchar() != '\n'); //clear the input buffer
  
  data_ptr = ll_delete_element(head_ptr, (void *)cmp_data, cmpfunc);
  
  if (data_ptr == NULL)
  {
    printf("Delete failed\n");
  }
  else
  {
    free(data_ptr);
  }
}


//DELETE THE WORD(S)

void clear(struct node *head_ptr)
{
  ll_destroy(head_ptr);
  exit(1);
}
