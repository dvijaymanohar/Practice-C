//file1.h
#define USD 1

//file2.h
#define UKP 1

//file3
#include <stdio.h>
#include <file1.h>         //A

#if (defined (USD))           // B
  #define currency_rate 46
#elif (defined (UKP))
  #define currency_rate 100      //C
#else
  #define currency_rate 1    //D
#endif

main()
{
  int rs;
  rs = 10 * currency_rate;      //H
  printf(“ % d\n”, rs);
}

