#include "BST.h"
#include <stdio.h>
#define  DEBUG  0

void initialiseBST(void)
{
  node = NULL; root = NULL; newnode = NULL; temp = NULL;
}

int BST_Insert(int n)
{
  static int key_n = 0;
  temp = root;
  newnode = (BST_t *)malloc(sizeof(BST_t));
  
  if (newnode == NULL)
  {
    printf("\n\tFatal Error : Out of Space\n");
    return 0;   //If malloc couln't allocate enough memory for newnode
  }
  
  newnode -> key = key_n++;     //Automatically gives a key: root with 0
  newnode->data = n;
  
  if (root == NULL)
  {
    root = newnode;
    root -> LChild = root -> RChild = NULL;
  }
  else
  {
    if (n < temp -> data)
    {
      temp = head;
    }
    
    while (temp->rlink != NULL) { temp = temp->rlink; }
    
    temp->rlink = newnode;
    newnode->llink = temp;
    temp = newnode;
    temp->rlink = NULL;
    rear = temp;
  }
  
  return 1;
}




