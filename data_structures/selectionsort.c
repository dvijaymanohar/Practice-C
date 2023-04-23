# include <stdio.h>
# include <stdlib.h>

int main()
{
  int inpnum, *input, i, j, k, temp, complexity = 0;
  printf("Enter the number of elements\n");
  scanf("%d", &inpnum);
  input = malloc(inpnum * sizeof(int));
  printf("Enter the elements\n");
  
  for (i = 0; i < inpnum; i++)
  {
    scanf("%d", &input[i]);
  }
  
  for (i = 0; i < inpnum; i++)
  {
    printf("%d", input[i]);
  }
  
  printf("\n");
  
  for (j = 0; j < inpnum - 1; j++)
  {
    for (i = 0; i < inpnum - 1; i++)
    {
      if (input[i] > input[i + 1])
      {
        temp = input[i];
        input[i] = input[i + 1];
        input[i + 1] = temp;
        complexity++;
      }
      else
      {
        for (k = i; k < inpnum - 1; k++)
        {
          if (input[k] > input[k + 1])
          {
            temp = input[k];
            input[k] = input[k + 1];
            input[k + 1] = temp;
            complexity++;
          }
        }
      }
    }
    
    for (k = 0; k < inpnum; k++)
    {
      printf("%d", input[k]);
    }
    
    printf("\n");
  }
  
  for (k = 0; k < inpnum; k++)
  {
    printf("%d", input[k]);
  }
  
  printf("\nThe complexity is %d\n", complexity);
  return 0;
}
