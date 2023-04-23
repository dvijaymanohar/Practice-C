/* PROGRAM TO IMPLEMENT MERGESORT */

#include <stdio.h>
#include <stdlib.h>

void mergesort(int *arr, int lpos, int rpos);
void merge(int *arr, int lpos, int rpos);

int main()
{
  int *arr, len, i;
  printf("\nEnter the no. of elements to be sorted : ");
  scanf("%d", &len);
  arr = (int *)malloc(len * sizeof(int));
  printf("Enter %d element(s):\n", len);
  
  for (i = 0; i < len; i++)
  {
    scanf("%d", (arr + i));
  }
  
  mergesort(arr, 0, len - 1);
  printf("The mergesorted %d element(s) is/are :\n", len);
  
  for (i = 0; i < len; i++)
  {
    printf("%d\t", arr[i]);
  }
  
  free(arr);
  printf("\n");
  return 0;
}



void mergesort(int *arr, int lpos, int rpos)
{
  if (rpos - lpos <= 1)
  {
    if (rpos - lpos == 1 && arr[lpos] > arr[rpos])
    {
      arr[lpos] = arr[lpos] + arr[rpos];
      arr[rpos] = arr[lpos] - arr[rpos];
      arr[lpos] = arr[lpos] - arr[rpos];
    }
    
    return;
  }
  
  mergesort(arr, lpos, (lpos + rpos) / 2);
  mergesort(arr, ((lpos + rpos) / 2) + 1, rpos);
  merge(arr, lpos, rpos);
}



void merge(int *arr, int lpos, int rpos)
{
  int lpos1 = lpos, lpos2, narrpos, i;
  int *narr;
  narr = (int *)malloc((rpos + 1) * sizeof(int));
  lpos2 = (lpos + rpos) / 2 + 1;
  narrpos = lpos2;    //store the location of next array
  
  //merge and copy into new array
  for (i = 0; lpos1 < narrpos && lpos2 <= rpos; i++)
  {
    if (arr[lpos1] < arr[lpos2])
    {
      narr[i] = arr[lpos1];
      lpos1++;
    }
    else
    {
      narr[i] = arr[lpos2];
      lpos2++;
    }
  }
  
  //copy the remaining part of array
  if (lpos1 == narrpos)
    for (; lpos2 <= rpos; i++, lpos2++)
    {
      narr[i] = arr[lpos2];
    }
  else
    for (; lpos1 < narrpos; i++, lpos1++)
    {
      narr[i] = arr[lpos1];
    }
    
  //copy back into the original array
  for (i = 0; lpos <= rpos; i++, lpos++)
  {
    arr[lpos] = narr[i];
  }
  
  free(narr);
}
