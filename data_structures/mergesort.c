# include <stdio.h>
# include <stdlib.h>

int main()
{
  int inpnum, *input, i, j = 0, k = 0, temp, complexity = 0, left = 0, *output, pri;
  printf("Enter the number of elements\n");
  scanf("%d", &inpnum);
  input = malloc(inpnum * sizeof(int));
  output = malloc(inpnum * sizeof(int));
  printf("Enter the elements\n");
  
  for (i = 0; i < inpnum; i++)
  {
    scanf("%d", &input[i]);
  }
  
  for (i = 0; i < (inpnum / 2); i++)
  {
    if (j < inpnum)
    {
      if (input[j] > input[j + 1])
      {
        temp = input[j];
        input[j] = input[j + 1];
        input[j + 1] = temp;
      }
    }
    
    j = j + 2;
  }
  
  for (i = 0; i < inpnum; i++)
  {
    printf("%d", input[i]);
  }
  
  printf("\n");
  i = 0;
  
  while (i <= 1)
  {
    k = 0;
    
    for (j = 0; j < inpnum / 2 - 1; j++)
    {
      printf("\n%d,%d \n", input[i], input[k + 2]);
      
      if (input[i] > input[k + 2])
      {
        temp = input[i];
        input[i] = input[k + 2];
        input[k + 2] = temp;
      }
      
      k = k + 2;
    }
    
    for (pri = 0; pri < inpnum; pri++)
    {
      printf("%d", input[pri]);
    }
    
    printf("\n");
    i++;
  }
  
  for (i = 0; i < inpnum; i++)
  {
    printf("%d", input[i]);
  }
}
