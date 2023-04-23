# include <stdio.h>

int main()
{
  int inpnum, *input;
  printf("Enter the number of elements\n");
  scanf("%d", &inpnum);
  printf("Enter the elements\n");
  
  for (i = 0; i < inpnum; i++)
  {
    scanf("%d", input[i]);
  }
}
