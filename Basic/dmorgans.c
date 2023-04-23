#include <stdio.h>
int main()
{
  int a, b = 0, c;
  
  if ((!(a < b) && !(b < c)) == (!((a < b) || (b < c))))
  {
    printf("Hey it works ");
  }
  else
  {
    Printf("No it did'nt !!!!");
  }
}
