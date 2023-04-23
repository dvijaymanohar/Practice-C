int i = 0;    //Global variable  /A
main()
{
  int i ;     // local variable for main   / B
  void f1(void)  ;    //C
  i = 0;    // D
  printf("value of i in main %d\n", i); // E
  f1();         // F
  printf("value of i after call%d\n", i); // G
}
void f1(void)       // H
{
  int i = 0;  //local variable for f1 // I
  i = 50;         // H
}
