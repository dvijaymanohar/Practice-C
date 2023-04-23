
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char ch;
  char input_str[] =
    "Hello, \
     Paid hell lot of money for Hummer bike  \
     I am definetly a fool";
  FILE *fp = fopen("data_file.txt", "wb+");
  
  if (NULL == fp)
  {
    printf("FP is null\n");
    exit(EXIT_FAILURE);
  }
  
  fwrite(input_str, 1, sizeof(input_str), fp);
  rewind(fp);
#if 0
  fclose(fp);
  fp = fopen("data_file.txt", "rb+");
  
  if (NULL == fp)
  {
    printf("FP is null\n");
    exit(EXIT_FAILURE);
  }
  
#endif
  
  while ((ch = fgetc(fp)) != EOF)
  {
    printf("%c", ch);
  }
  
  puts("\n");
  
  if (1)
  {
    printf("");
  }
  
  return 0;
}
