\\ Program in file extern1.c

#include <stdio.h>      \\ A
#include <d:\cbook\storage\f1.cpp>  \\ B
extern int i;       \\ C
main()
{
  i = 0;           \\ D
  printf("value of i %d\n", i);
}

\\ Program in file f1.cpp

int i = 7;         \\ E

