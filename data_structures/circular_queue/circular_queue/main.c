

#include "circular_que .h"
#include <stdio.h>
#include <stdlib.h>


int main() {
  struct queue *que_ptr = create_que(QUEUE_SIZE);
  int i = 0;

  data_buf_t buff = {NULL, 0};
  buff.data = (char *)calloc(QUE_DATA_ITEM_SIZE * sizeof(char), 1);
  buff.data_len = 0;

  if (NULL == que_ptr)
    return EXIT_FAILURE;

  for (i = 0; i <= QUEUE_SIZE + 1; i++) {
    buff.data[0] = i;
    buff.data_len = 1;

    if (!enqueue(que_ptr, &buff))
      printf("Element enqued: %d\n", i);
  }

  printf("Element enque done\n");

  for (i = 0; i < QUEUE_SIZE - 2; i++) {
    buff.data_len = 0;
    if (!dequeue(que_ptr, &buff))
      printf("Element dequeued: %d\n", buff.data[0]);
  }

  buff.data[0] = 6;
  if (!enqueue(que_ptr, &buff))
    printf("Element enqued: 6\n");

  buff.data[0] = 7;
  if (!enqueue(que_ptr, &buff))
    printf("Element enqued: 7\n");

  buff.data[0] = 8;
  if (!enqueue(que_ptr, &buff))
    printf("Element enqued: 8\n");

  printf("size = %d\n", get_que_size(que_ptr));

  if (!dequeue(que_ptr, &buff))
    printf("Element dequeued: %d\n", buff.data[0]);

  if (!dequeue(que_ptr, &buff))
    printf("Element dequeued: %d\n", buff.data[0]);

  if (!dequeue(que_ptr, &buff))
    printf("Element dequeued: %d\n", buff.data[0]);

  printf("Remaining items in the queue: %d\n", get_que_size(que_ptr));

  if (isEmpty(que_ptr)) {
    printf("The queue is empty\n");
  } else {
    printf("The queue is not empty\n");
  }

  free_queue(&que_ptr);

  buff.data[0] = 5;
  buff.data_len = 1;
  if (enqueue(que_ptr, &buff)) {
    printf("Init queue first\n");
  }

  if (!dequeue(que_ptr, &buff))
    printf("Element dequeued: %d\n", buff.data[0]);
  else
    printf("Init queue first\n");

  free(buff.data);
  buff.data = NULL;

  return EXIT_SUCCESS;
}
