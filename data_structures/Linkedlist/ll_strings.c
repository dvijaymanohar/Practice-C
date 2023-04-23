/* PROGRAM TO MODIFY A TEXT STATMENT USING A LINKED LIST */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "switch_func.h"

void gen_print(void *);
int gen_cmp(void *, void *);
int disp_menu(void);

int main()
{
  int choise;
  struct node *head_ptr;
  void (*func)(void *) = gen_print;
  int (*cmpfunc)(void *, void *) = gen_cmp;
  //CREATE LINKED LIST
  head_ptr = ll_create();
  
  //MENU DRIVEN CODE
  
  while (1)
  {
    choise = disp_menu();
    
    switch (choise)
    {
      case 1 : insert_first(head_ptr);
        break;
        
      case 2 : insert_last(head_ptr);
        break;
        
      case 3 : insert_before(head_ptr, cmpfunc);
        break;
        
      case 4 : insert_after(head_ptr, cmpfunc);
        break;
        
      case 5 : delete_first(head_ptr);
        break;
        
      case 6 : delete_last(head_ptr);
        break;
        
      case 7 : delete_before(head_ptr, cmpfunc);
        break;
        
      case 8 : delete_after(head_ptr, cmpfunc);
        break;
        
      case 9 : delete_word(head_ptr, cmpfunc);
        break;
        
      case 10 : print(head_ptr, func);
        break;
        
      case 11 : clear(head_ptr);
        break;
        
      case 0 : return 0;
    }
  }
}



int disp_menu(void)
{
  int choise;
  
  while (1)
  {
    choise = 100; //any value other than required
    printf("\n1 : Insert a word at the begining\
		\n2 : Insert a word at the end\
		\n3 : Insert before a particular word\
		\n4 : Insert after a particular word\
		\n5 : Delete the first word\
		\n6 : Delete the last word\
		\n7 : Delete a word before a particular word\
		\n8 : Delete a word after a particular word\
		\n9 : Delete a particular word\
		\n10 : Print the word(s)\
		\n11 : Clear the word(s) and exit\
		\n0 : Exit the program\n");
    printf("\nEnter your choise : ");
    scanf("%d", &choise);
    
    while (getchar() != '\n');  //clear the input buffer
    
    if (choise >= 0 && choise <= 11)
    {
      return (choise);
    }
    else
    {
      printf("Please enter a valid digit\n");
    }
  }
}



void gen_print(void *data_ptr)
{
  printf("%s ", (char *)data_ptr);
}



int gen_cmp(void *data1, void *data2) //return true on equal else return false
{
  return (!(strcmp((char *)data1, (char *)data2)));
}
