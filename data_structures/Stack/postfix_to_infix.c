/* PROGRAM TO EVALUATE POSTFIX STRING AT COMMAND LINE */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("\nToo few or too many arguments at the command line\n");
    exit(0);
  }