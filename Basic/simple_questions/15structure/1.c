struct student    \\ A
{
  char name[30];  \\ B
  float marks;  \\ C
}  student1, student2;   \\ D

main()
{
  struct student student3;  \\ E
  char s1[30];    \\ F
  float  f;     \\ G
  scanf(“ % s”, name); \\ H
  scanf(“ % f”, & f); \\ I
  student1.name = s1; \\ J
  student2.marks = f; \\ K
  printf(“ Name is % s \n”, student1.name);  \\ L
  printf(“ Marks are % f \n”, student2.marks); \\ M
}
