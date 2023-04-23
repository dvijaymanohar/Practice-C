#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main()
{
  struct link *res;
  int choice;
  int *val;
  int place;
  //  res = (struct link*)malloc(sizeof(struct link));
  res = link_create();
  
  if (res != NULL)
  {
    printf("\tlink is  created\n");
  }
  else
  {
    printf("\tlink is not created\n");
  }
  
  do
  {
    printf("\tenter a choice\n");
    printf("\t1.insert first node \t2. insert last node\n \t3. before insert \t4. after insert\n\t5. deleate first\t 6. deleate last\n\t 7. deleate after\t 8. deleate before 9 . print\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
      case 1:
        printf("\tenter a value\n");
        val = (int *)malloc(sizeof(int));
        scanf("%d", val);
        link_first_insert(res, val);
        //        printf("\tinsert first element :%d\n", *val);//*(int*)link_first_insert(res, val));
        break;
        
      case 2:
        printf("\tenter a value\n");
        val = (int *)malloc(sizeof(int));
        scanf("%d", val);
        link_last_insert(res, val);
        //        printf("%d", *val);//*(int*)link_last_insert(res, val));
        break;
        
      case 3:
        printf("\tenter a value and place value\n");
        val = (int *)malloc(sizeof(int));
        scanf("%d%d", val, &place);
        link_before_insert(res, val, place);
        //        printf("%d", *val);//*(int*)link_before_insert(res, val, place));
        break;
        
      case 4:
        printf("\tenter a value and place\n");
        val = (int *)malloc(sizeof(int));
        scanf("%d%d", val, &place);
        link_after_insert(res, val, place);
        //        printf("%d", *val);//*(int*)link_after_insert(res, val, place));
        break;
        
      case 5:
        val = (int *)link_delete_first(res);
        printf("%d", *val);
        free(val);
        break;
        
      case 6:
        val = (int *)link_delete_last(res);
        printf("%d", *val);
        free(val);
        break;
        
      case 7:
        printf("\tenter a place\n ");
        scanf("%d", &place);
        val = (int *)link_delete_after(res, place);
        printf("\t delete  node\t%d\n", *val);
        free(val);
        break;
        
      case 8:
        printf("\tenter a place\n");
        scanf("%d", &place);
        val = (int *)link_delete_before(res, place);
        printf("\t delete node\t%d\n", *val);
        free(val);
        break;
        
      case 9:
        link_print(res);
        break;
        
      case 10: link_destroy(res);
        break;
        
      default :
        printf("exit programm");
    }
  }
  while (choice != 11);
  
  return 0;
}

