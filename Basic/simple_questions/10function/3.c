main()
{
  int i;
  i = 0;
  printf(“ The value of i before call % d \n”, i);
  f1(i);
  printf(“ The value of i after call % d \n”, i);
}
void f1(int k)
{
  k = k + 10;
}
