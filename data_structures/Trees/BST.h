#ifndef _BST_H
#define _BST_H

typedef struct BST
{
  struct BST *LChild;
  int key;  //key is unique
  int data;
  struct BST *RChild;
} BST_t;

//int key_n;

BST_t *node, *newnode, *root, *temp;
//BST operations
void intialiseBST(void);
int BST_Insert(int n);
int BST_Delete(int key);
int BST_Search(int key);
void BST_Display(void);
