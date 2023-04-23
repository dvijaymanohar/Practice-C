/* Author       :   Vijay Manohar .D
   Program Description  : Priority Queue Implementation
   Date         : 31 May '07
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define DEBUG 1
int main(void)
{
  int choice, ret, val;
  
  while (1)
  {
    ret = 0;
    printf("\n\n\tQueue ADT operations\n\n\t1. Enqueue\n\t2. Dequeue\n\t3. Dispose Queue");
    printf("\n\t4. Display Queue\n\t5. Exit");
    printf("\n\n\tEnter a valid Choice here:");
    
    do
    {
      ret = scanf("%d", &choice);
      
      if (!ret) { printf("\n\tEnter a valid integer:"); }
      
      while (getchar() != '\n');
    }
    while (!ret);
    
    switch (choice)
    {
      case 1:
        printf("\n\tEnter the value to enter here:");
        scanf("%d", &val);
        ret = enqueue(val);
        
        if (!ret) { printf("\n\tEnqueue: Error inserting the element"); }
        else { printf("\n\tEnqueue: Element Sucessfully inserted"); }
        
        break;
        
      case 2:
        ret = dequeue();
        
        if (-1 == ret) { printf("\n\tDequeue: Queue is empty"); }
        else { printf("\n\tDequeue: %d is deleted from the queue", ret); }
        
        break;
        
      case 3:
        ret = dispose_queue();
        
        if (-1 == ret) { printf("\n\tDispose Queue: Queue is empty!, What to dispose here"); }
        else { printf("\n\tQueue Disposed"); }
        
        break;
        
      case 4:
        display_queue();
        break;
        
      case 5:
        exit(1);
        
      default:
        printf("\n\tInvalid Choice");
        break;
    }
  }
  
  return 0;
}
