/* Program to verify the BST functions */

#include <stdio.h>
#include "bst.h"

int gen_cmp(void *, void *);
void gen_print(void *);
int disp_menu(void);

int main()
{
  struct node *root;
  int choise;
  void (*printfunc)(void *) = gen_print;
  int (*cmpfunc)(void *, void *) = gen_cmp;
  //CREATE BST
  root = bst_create();
  
  //MENU DRIVEN CODE
  
  while (1)
  {
    choise = disp_menu();
    
    switch (choise)
    {
      case 1 : insert(root, cmpfunc);
        break;
        
      case 2 : inorder(root, printfunc);
        break;
        
      case 3 : preorder(root, printfunc);
        break;
        
      case 4 : postorder(root, printfunc);
        break;
        
      case 5 : destroy(root);
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
    printf("\n1 : Insert a element in the BST\
		\n2 : Print the elements in Inorder\
		\n3 : Print the elements in Preorder\
		\n4 : Print the elements in Postorder\
		\n5 : Destroy the BST and exit\
		\n0 : Exit the program\n");
    printf("\nEnter your choise : ");
    scanf("%d", &choise);
    
    while (getchar() != '\n');  //clear the input buffer
    
    if (choise >= 0 && choise <= 5)
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
  printf("%d\n", *(int *)data_ptr);
}



int gen_cmp(void *data1, void *data2) //return true on equal else return false
{
  if (*(int *)data1 > *(int *)data2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
