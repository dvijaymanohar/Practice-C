#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
  struct tree *root;
  //  root = bst_create();
  root = NULL;
  
  while (1)
  {
    int ch;
    printf("Enter ur choice\n");
    printf(" 1 -- Insert\n 2 -- Print_preorder\n 3 -- Print_postorder\n 4 -- Print_inorder\n 5 -- Delete\n");
    scanf("%d", &ch);
    
    switch (ch)
    {
      case 1:
        {
          int *val;
          val = (int *) malloc(sizeof(int));
          printf("Enter a value \n");
          scanf("%d", val);
          root = bst_insert(root, val);
          
          if (root == NULL)
          {
            printf("value is not inserted \n");
          }
          else
          {
            printf("Value is inserted \n");
          }
        }
        break;
        
      case 2:
        {
          bst_print_preorder(root);
          printf("\n");
        }
        break;
        
      case 3:
        {
          bst_print_postorder(root);
          printf("\n");
        }
        break;
        
      case 4:
        {
          bst_print_inorder(root);
          printf("\n");
        }
        break;
        
      case 5:
        {
          int flag;
          int *val;
          val = (int *) malloc(sizeof(int));
          printf("Enter a value \n");
          scanf("%d", val);
          flag = bst_delete(root, val);
          
          if (flag == 1)
          {
            printf("Delete successfull\n");
          }
          else
          {
            if (flag == 0)
            {
              printf("Value not Found\n");
            }
            else
            {
              printf("Tree Empty\n");
            }
          }
        }
    }
  }
  
  return 0;
}
