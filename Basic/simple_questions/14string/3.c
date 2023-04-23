main()
{
  char s1[6] = “abcde ”;
  int cnt = 0;
  cnt = cnt_str(s1);  \\ A
  printf(“ total characters are % d \n”, cnt);
}
int cnt_str(char s1[]); \\ B
{
  int cn = 0;
  
  while ((cn < 6) && s1[cn]! = ‘\0’)
  {
    cn++;
  }
  
  return (cn);
}
