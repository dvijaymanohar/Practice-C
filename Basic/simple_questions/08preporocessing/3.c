//file1.h

#define USD 1

//file2.h
#define UKP 1

//file3
#include <stdio.h>
#include <file1.h>       //A

#ifdef USD            // B
  #define currency_rate 46     //C
#endif              //D

#ifdef UKP        // E
  #define currency_rate 100 //F
#endif                //G
main()
{
  int rs;
  rs = 10 * currency_rate;  //H
  printf(“ % d\n”, rs);
}
