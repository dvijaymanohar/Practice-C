#include <stdio.h>
main()
{
  int a[2][3][4]; \\ A
  int b[3][4];  \\ B
  int c[4];   \\ C
  int cnt = 0;
  
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 4; k++)
      {
        a[i][j][k] = cnt;
        cnt;
      }
}
void print_onedim(int a[])  \\ D
{
  for (int i = 0; i < 4; i++)
  {
    printf("%d ", a[i]);
  }
}
void print_twodim(int a[][4])   \\ E
{
  for (int j = 0; j < 3; j++)
  {
    print_onedim(a[j]);
  }
  
  printf("\n");
}
void print_threedim(int a[][3][4])    \\ F
{
  printf("Each two dimension matrix\n");
  
  for (int j = 0; j < 2; j++)
  {
    print_twodim(a[j]);
  };
  
}
