#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct tree *bst_create()
{
  struct tree *root;
  root = (struct tree *) malloc(sizeof(struct tree));
  
  if (root == NULL)
  {
    printf("Root is not Created \n");
    return NULL;
  }
  else
  {
    root->info = (void **) malloc(sizeof(void *));
    root-> info = NULL;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
}

struct tree *bst_insert(struct tree *root, void *val)
{
  struct tree *nnode, *cur;
  nnode = (struct tree *) malloc(sizeof(struct tree));
  
  if (nnode == NULL)
  {
    printf("Node is not Created \n");
    return NULL;
  }
  else
  {
    nnode->info = (void **) malloc(sizeof(void *));
    nnode-> info = val;
    nnode->left = NULL;
    nnode->right = NULL;
  }
  
  if (root == NULL)
  {
    root = nnode;
    return root;
  }
  else
  {
    cur = root;
    
    while (cur->left != NULL || cur->right != NULL)
    {
      if (val == cur->info)
      {
        printf(" U r enter Duplicate value\n");
        free(nnode);
        return root;
      }
      else
      {
        if ((*(int *)val < * (int *)cur->info) && (cur->left != NULL))
        {
          cur = cur->left;
        }
        else
        {
          if ((*(int *)val > *(int *)cur->info) && (cur->right != NULL))
          {
            cur = cur->right;
          }
          else
          {
            break;
          }
        }
      }
    }
  }
  
  if (*(int *)val < * (int *)cur->info)
  {
    cur->left = nnode;
  }
  else
  {
    cur->right = nnode;
  }
  
  return root;
}

void bst_print_preorder(struct tree *root)
{
  if (root != NULL)
  {
    printf("%d\t", *((int *)root->info));
    bst_print_preorder(root->left);
    bst_print_preorder(root->right);
  }
  
  /*  else
    {
      printf("Tree is Empty \n");
    }*/
}

void bst_print_postorder(struct tree *root)
{
  if (root != NULL)
  {
    bst_print_postorder(root->left);
    bst_print_postorder(root->right);
    printf("%d\t", *((int *)root->info));
  }
  
  /*  else
    {
      printf("Tree is Empty \n");
    }*/
}

void bst_print_inorder(struct tree *root)
{
  if (root != NULL)
  {
    bst_print_inorder(root->left);
    printf("%d\t", *((int *)root->info));
    bst_print_inorder(root->right);
  }
  
  /*  else
    {
      printf("Tree is Empty \n");
    }*/
}

int bst_delete(struct tree *root, void *val)
{
  struct tree  *cur, *prev, *temp;
  
  if (root == NULL)
  {
    return (-1);
  }
  else
  {
    int flag;
    cur = root;
    
    while (cur->left != NULL || cur->right != NULL)
    {
      if ((*(int *)val) == (*(int *)cur->info))
      {
        temp  = large_element_lst(cur);
        
        if (temp == NULL)
        {
          temp = small_element_rst(cur);
        }
        else
        {
          if (flag == 1)
          {
            prev->left = temp;
            
            if (temp->left == NULL)
            {
              temp->left = cur->left;
            }
            
            temp->right = cur->right;
          }
          else
          {
            prev->right = temp;
            
            if (temp->right == NULL)
            {
              temp->right = cur->right;
            }
            
            temp->left = cur->left;
          }
        }
        
        free(cur);
        return 1;
      }
      else
      {
        prev = cur;
        
        if ((*(int *)val < * (int *)cur->info) && (cur->left != NULL))
        {
          cur = cur->left;
          flag = 1;
        }
        else
        {
          if ((*(int *)val > *(int *)cur->info) && (cur->right != NULL))
          {
            cur = cur->right;
            flag = 0;
          }
          else
          {
            break;
          }
        }
      }
    }
  }
  
  if (*(int *)cur->info == *(int *)val)
  {
    if (*(int *)prev->info < * (int *)cur->info)
    {
      prev->right = NULL;
    }
    else
    {
      prev->left = NULL;
    }
    
    free(cur);
    return 1;
  }
  else
  {
    return 0;
  }
}

struct tree *large_element_lst(struct tree *cur)
{
  struct tree *prev;
  int flag = 0;
  
  if (cur->left == NULL)
  {
    return NULL;
  }
  else
  {
    prev = cur;
    cur = cur->left;
    
    while (cur->left != NULL && cur->right != NULL)
    {
      cur = cur->right;
      flag = 1;
      prev = cur;
    }
  }
  
  if (flag == 1)
  {
    prev->right = cur->right;
  }
  else
  {
    prev->left = cur->left;
  }
  
  return cur;
}

struct tree *small_element_rst(struct tree *cur)
{
  struct tree *prev;
  int flag = 0;
  prev = cur;
  cur = cur->right;
  
  while (cur->left != NULL && cur->right != NULL)
  {
    cur = cur->left;
    prev = cur;
    flag = 1;
  }
  
  if (flag == 1)
  {
    prev->left = cur->right;
  }
  else
  {
    prev->right = cur->right;
  }
  
  return cur;
}
