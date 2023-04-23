#include <stdio.h>

void *print(void *);
void *gen_print(void *(*)(void *));

int main()
{
  void *ptr;
  void (*func)(void *);
  ptr = "When you don't get what u want, experience is what u get.\nI am !joking, this is verymuch true";
  print(ptr);
  func = print;
  func(ptr);
  printf((char *)gen_print(func));
  return 0;
}


void *print(void *ptr)
{
  int i;
  void *ptr = &i;
  i = printf("%s\n", (char *)ptr);
  return ptr;
}


void *gen_print(void (*func)(void *))
{
  void *gen_ptr = "Success";
  void *ptr = "Be positive, Have fun, all the time around ur place";
  func(gen_ptr);
  return ptr;
}
