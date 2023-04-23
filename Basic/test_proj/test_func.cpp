
#include <stdio.h>
#include "test_func.h"

int i = 19;
int j = 5;

void other (void) {
     j++;
     printf ("i : %d\tj = %d\n", i, j);
}
