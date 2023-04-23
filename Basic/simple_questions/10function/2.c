main()
{
  printf(“1 \n”);   // 1
  printf(“2 \n”);   // 2
  printf(“3 \n”);   // 3
  printf(“4 \n”);   // 4
  printf(“5 \n”);   // 5
  f1();
  printf(“6 \n”);   // 6
  printf(“7 \n”);   // 7
  printf(“8 \n”);   // 8
}
void f1(void)
{
  printf(“f1 - 9 \n”); // 9
  printf(“f1 - 10 \n”); // 10
  f2();
  printf(“f1 - 11 \n”); // 11
  printf(“f1 - 12 \n”); // 12
}
void f2(void)
{
  printf(“f2 - 13 \n”); // 13
  printf(“f2 - 14 \n”); // 14
  printf(“f3 - 15 \n”); // 15
}
