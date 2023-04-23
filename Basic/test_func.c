#include "test_func.h"

int i;
static int j = 5;

static void other(void)
{
  j++;
  printf("i : %d\tj = %d\n", i, j);
}
