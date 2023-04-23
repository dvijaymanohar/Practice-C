#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main(int argc, char *argv[])
{
  struct queue *res;
  int a, b;
  int choice ;
  int *str;
  res = (struct queue *)malloc(sizeof(struct queue));
  void *dq;
  
  do
  {
    printf("enter ur choce 1. queue created 2. add element 3. deleate element 4. print queeu 5.destroy queue 6.quit \n");
    scanf("%d", &choice);
    
    switch (choice)
    {
      case 1: a = atoi(argv[1]);
        res =  queue_create(a);
        
        if (res->queue_maxsize == a)
        {
          printf("\tqueue is created\n");                   /* QUEUE CREATED */
        }
        else
        {
          printf("\tqueue is not created\n");
        }
        
        break;
        
      case 2: while (1)
        {
          str = ((int *)malloc(sizeof(int)));
          printf("\tenter a elements\n");
          scanf("%d", str);
          
          if (*str == 0)
          {
            break;
          }
          
          b =  queue_add(res, (void *)str);
          
          if (b == 0)
          {
            printf("\tqueue is full\n");
          }
          else
          {
            printf("\tadd elemnts:\t%d\n", *(int *)res->queue_array[(res->queue_rear % res->queue_maxsize) - 1]) ;
          }
        }
        
        break;
        
      case 3: dq = queue_del(res);
      
        if (dq == NULL)
        {
          printf("\t queue empty\n");
        }
        else
        {
          printf("\tdeleate element is %d\n", *(int *)dq);
          //printf("\tdeleate element %d" ,*(int*) res->queue_array[(res->queue_front % res->queue_maxsize) ] );
        }
        
        break;
        
      case 4: queue_print(res);
        break;
        
      case 5: queue_destroy(res);
        break;
        
      default:
        printf("\tur program exit\n ");
    }
  }
  while (choice != 6);
  
  return 0 ;
}
