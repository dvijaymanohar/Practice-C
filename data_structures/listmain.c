#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
  struct linklist *list;
  list = linklist_create();
  
  if (list == NULL)
  {
    printf("List is not Cteate\n");
    return 0;
  }
  else
  {
    printf("List is Create\n");
  }
  
  while (1)
  {
    int ch;
    printf("Enter ur Choice\n");
    printf(" 1 -- Insert_Frist\n 2 -- Insert_Last\n 3 -- Insert Before\n 4 -- Insert After\n 5 -- Delete_Frist\n 6 -- Delete_Last\n 7 -- Delete Before\n 8 -- Delete After\n 9 -- Print\n");
    scanf("%d", &ch);
    
    switch (ch)
    {
      case 1:
        {
          int *val;
          printf("Enter the value\n");
          val = (int *) malloc(sizeof(int));
          scanf("%d", val);
          linklist_insert_frist(list, val);
        } break;
        
      case 2:
        {
          int *val;
          printf("Enter the value\n");
          val = (int *) malloc(sizeof(int));
          scanf("%d", val);
          linklist_insert_last(list, val);
        } break;
        
      case 3:
        {
          int *val;
          int position;
          printf("Enter the value of Data and Position\n");
          val = (int *) malloc(sizeof(int));
          scanf("%d %d", val, &position);
          linklist_insert_before(list, val, position);
        } break;
        
      case 4:
        {
          int *val;
          int position;
          printf("Enter the value of Data and Position\n");
          val = (int *) malloc(sizeof(int));
          scanf("%d %d", val, &position);
          linklist_insert_after(list, val, position);
        } break;
        
      case 5:
        {
          int *val;
          val = (int *) linklist_delete_frist(list);
          printf("Delete Operation is Successfull and value is %d\n", *val);
          free(val);
        } break;
        
      case 6:
        {
          int *val;
          val = (int *) linklist_delete_last(list);
          printf("Delete Operation is Successfull and value is %d\n", *val);
          free(val);
        } break;
        
      case 7:
        {
          int *val;
          int position;
          printf("enter the position \n");
          scanf("%d", &position);
          val = (int *) linklist_delete_before(list, position);
          printf("Delete Operation is Successfull and value is %d\n", *val);
          free(val);
        } break;
        
      case 8:
        {
          int *val;
          int position;
          printf("enter the position \n");
          scanf("%d", &position);
          val = (int *) linklist_delete_after(list, position);
          printf("Delete Operation is Successfull and value is %d\n", *val);
          free(val);
        } break;
        
      case 9:
        {
          printf("\n");
          linklist_print(list);
        } break;
    }
  }
  
  return 0;
}
