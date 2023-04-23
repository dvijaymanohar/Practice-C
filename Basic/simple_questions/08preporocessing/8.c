//file1.h
#define USD 1

//file2.h
#define UKP 1

//file3
#include <stdio.h>
#include <file1.h>         //A

#if !defined (USD) || !defined (UKP)    // B
  #error “ERROR: NO_CURRENCY rate is specified.”  //C
#endif

main()
{
  int rs;
  rs = 10 * currency_rate;      //D
  printf(“ % d\n”, rs);
}
