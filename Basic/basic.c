
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b)     (((a) > (b)) ? a : b)
#define MAX_2(a, b)     (MAX(a, b) == 0)
#define CALCP1(NUM_CH) (MAX(NUM_CH >> 6, 256 >> 7) - 1)
#define CALCP2(CH_INDEX, SA_INDEX) MAX(CH_INDEX >> 6, SA_INDEX >> 7) - 1
#define CALCP_2(CH_INDEX, SA_INDEX) (CALCP2(CH_INDEX >> 6, SA_INDEX >> 7)

//max((NUM_CH>>6), (NUM_SA >> 7)) – 1

int main(int argc, char *argv[])
{
  int ch_no = atoi(argv[1]);
  //unsigned int address = CALCP1(ch_no);
  unsigned int address = 0;
  address = CALCP2(ch_no, 125);
  printf("NUM_CH >> 6 : 0x%x\n", ch_no >> 6);
  printf("SA_INDEX >> 7 : 0x%x\n", 125 >> 7);
  printf("Address for Channel: %u is 0x%x\n", ch_no, address);
  return 0;
}