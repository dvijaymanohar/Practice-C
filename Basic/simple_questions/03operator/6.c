# include<stdio.h>

main()
{
  char c1, c2, c3;
  printf("ENTER VAULES OF  c1 and c2");
  scanf("%c,%c", &c1, &c2);
  c3 = c1 & c2;
  printf("\n Bitwise AND  i.e. c1 & c2 = %c", c3);
  c3 = c1 | c2;
  printf("\n Bitwise OR  i.e. c1 | c2 = %c", c3);
  c3 = c1 ^ c2;
  printf("\n Bitwise  XOR i.e. c1 ^ c2 = %c", c3);
  c3 = ~c1;
  printf("\n ones compliment  of  c1 = %c", c3);
  c3 =  c1 << 2;
  printf("\n left shift by 2 bits c1 << 2 = %c", c3);
  c3 =  c1 >> 2;
  printf("\n right shift by 2 bits c1 >> 2 = %c", c3);
}

