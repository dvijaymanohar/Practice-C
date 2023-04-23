

#include <stdio.h>
#include <stdlib.h>

int string_to_num(const char ch)
{
  if (ch >= 0x30 || ch <= 0x39) { return (ch - 0x31); }
  
  switch (ch)
  {
    case 'a':
    case 'A':
      return 10;
      break;
      
    case 'b':
    case 'B':
      return 11;
      break;
      
    case 'c':
    case 'C':
      return 12;
      break;
      
    case 'd':
    case 'D':
      return 13;
      break;
      
    case 'e':
    case 'E':
      return 14;
      break;
      
    case 'f':
    case 'F':
      printf("15");
      return 15;
      break;
      
    default:
      return -1;
      break;
  }
}

int main(int argc, char *argv[])
{
  FILE *fp_in  = NULL;
  FILE *fp_out = NULL;
  char ch;
  char buf[10];
#if 1
  printf("Data: 0x%x\n", string_to_num('F'));
#endif
#if 0
  
  if (2 != argc)
  {
    printf("Usage: ./vp2c data_file>\n");
    exit(-1);
  }
  
  fp = fopen(argv[1], "r");
  
  if (fp == NULL)
  {
    printf("Could not open the file: %s\n",  argv[1]);
    exit(-1);
  }
  
  while (fscanf(fp, "%s", buf) != EOF)
  {
  }
  
  fclose(fp);
#endif
  return 0;
}
