/*Functions to implement BST */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


struct node *bst_create()
{
  struct node *root;
  root = (struct node *)calloc(1, sizeof(struct node *));
  printf("%p\t%p\t%p", root->data, root->left, root->right);
  return root;
}


void bst_insert(struct node *pnode, void *insert_data, int (*cmpfunc)(void *, void *))
{
  static int status = 100;
  struct node *parent;
  
  while (pnode != NULL && pnode->data != NULL)
  {
    printf("\n%p", pnode->data);
    parent = pnode;
    status = cmpfunc(insert_data, pnode->data);
    
    if (status)
    {
      pnode = pnode->right;
    }
    else
    {
      pnode = pnode->left;
    }
  }
  
  if (pnode == NULL)
    if (status)
    {
      parent->right = calloc(1, sizeof(struct node *));
    }
    else
    {
      parent->left = calloc(1, sizeof(struct node *));
    }
    
  if (status == 1)
  {
    parent->right->data = insert_data;
  }
  else if (status == 0)
  {
    parent->left->data = insert_data;
  }
  else
  {
    pnode->data = insert_data;
  }
  
  printf("\n%p\t%d", pnode->data, *(int *)pnode->data);
}


void bst_inorder(struct node *pnode, void (*printfunc)(void *))
{
  //  struct node *pnode = root;
  if (pnode == NULL)
  {
    return;
  }
  
  bst_inorder(pnode->left, printfunc);
  printfunc(pnode->data);
  bst_inorder(pnode->right, printfunc);
}


void bst_preorder(struct node *root, void (*printfunc)(void *))
{
  struct node *pnode = root;
  
  if (pnode == NULL)
  {
    return;
  }
  
  printfunc(pnode->data);
  bst_preorder(pnode->left, printfunc);
  bst_preorder(pnode->right, printfunc);
}


void bst_postorder(struct node *root, void (*printfunc)(void *))
{
  struct node *pnode = root;
  
  if (pnode == NULL)
  {
    return;
  }
  
  bst_postorder(pnode->left, printfunc);
  bst_postorder(pnode->right, printfunc);
  printfunc(pnode->data);
}


void bst_destroy(struct node *root)
{
  if (root != NULL)
  {
    free(root);
  }
}


/*struct node *bst_delete(struct node *root, void *delete_data, int (*cmpfunc)(void *, void *))
{
}*/
