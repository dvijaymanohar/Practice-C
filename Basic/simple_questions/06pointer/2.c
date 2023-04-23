#include <stdio.h>
main()
{
  int i;    //A
  int *ia;    //B
  i = 10;   //C
  ia = &i;    //D
  printf(“ The address of i is % 8u \n”, ia);    //E
  printf(“ The value at that location is % d\n”, i); //F
  printf(“ The value at that location is % d\n”, *ia);  //G
  *ia = 50;         //H
  printf(“The value of i is % d\n”, i);      //I
}
