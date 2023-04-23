#include <stdio.h>

/*int main()
{
  unsigned char c;

  for(c = 0; c < 255; c++)
    printf("\n%d", c);
return 0;
}*/



/*int main()
{
  int i;

  for(i = 10; i > 0; i--)
  {
    printf("%d", i);
    if(i % 2 == 0)
    {
      i--;
      printf("%d", i);
    }
  }
  return 0;
}*/



/*int main()
{
  unsigned char j = 100;

  while(j < 200)
  {
    j--;
    printf("\n%d", j);
  }

  return 0;
}*/



/*int main()
{
  int i, j, k, l;
  int arr[i][j];

  printf("Enter the no of rows and columns of matrix : ");
  scanf("%d %d", &i, &j);

  for(k = 0; k < i; k++)
  {
    for(l = 0; l < j; l++)
    {
      arr[i][j] = 5;
      printf("\t%d", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}*/



/*int main()
{
  int arr1[2] = {1,2}, arr2[2];

  arr2 = arr1;

  return 0;
}*/


#include <string.h>

int main()
{
  char a[] = "abc\0xyz";
  printf("%d", sizeof(a));
  printf("%d", strlen(a));
  return 0;
}
