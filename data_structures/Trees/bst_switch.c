/* CONTAINS THE FUNCTIONS USED IN bst_main.c */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

extern void gen_print(void *);
extern int gen_cmp(void *, void *);


//INSERT THE ELEMENTS IN BST

void insert(struct node *root, int (*cmpfunc)(void *, void *))
{
  int *data_ptr;
  data_ptr = (int *)malloc(sizeof(int));
  printf("\nEnter the element to be stored in the bst : ");
  scanf("%d", data_ptr);
  
  while (getchar() != '\n');  //clear the input buffer
  
  bst_insert(root, (void *)data_ptr, cmpfunc);
}



//PRINT THE ELEMENTS IN INORDER

void inorder(struct node *root, void (*printfunc)(void *))
{
  bst_inorder(root, printfunc);
}



//PRINT THE ELEMENTS IN PREORDER

void preorder(struct node *root, void (*printfunc)(void *))
{
  bst_preorder(root, printfunc);
}



//PRINT THE ELEMENTS IN POSTORDER

void postorder(struct node *root, void (*printfunc)(void *))
{
  bst_postorder(root, printfunc);
}



//DESTROY THE TREE
void destroy(struct node *root)
{
  bst_destroy(root);
  exit(1);
}
