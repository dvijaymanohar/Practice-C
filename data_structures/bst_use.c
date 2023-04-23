# include <stdio.h>
# include <stdlib.h>
# include "bst.h"

int compare(void *, void *);

int main()
{
  int (*comp)(void *)(void *);
  comp = compare;
  return 0;
}

int compare(void *element, void *element1)
{