main()
{
  char *s1 = “abcd”; \\ A
  char  s2[] = “efgh”;   \\ B
  printf(“ % s % 16lu \n, s1, s1);  \\ C
  printf(“ % s % 16lu \n, s2, s2);   \\ D
  s1 = s2;        \\ E
  printf(“ % s % 16lu \n, s1, s1);    \\ F
  printf(“ % s % 16lu \n, s2, s2);    \\ G
}

