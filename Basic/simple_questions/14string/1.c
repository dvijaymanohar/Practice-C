main()
{
  char s1[6]; \\ A
  char s2[6];
  char ch;
  int cnt = 0;
  s1 = “Hello”;   \\ B
  printf(“ % s \n”, s1);   \\ C
  s2 = {‘H’, ‘e’, ‘l’, ‘l’, ‘o’}  \\ D
       printf(“ % s \n”, s2);       \\ E
       
  while ((ch = getchar())! = ‘#’ && (cnt < 6 - 1))    \\ F
    s1[cnt++] = ch;    \\ G
    
  s1[cnt] = ‘\0’;    \\ H
}
