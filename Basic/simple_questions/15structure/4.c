struct student    \\ A
{
  char name[30];  \\ B
  float marks;  \\ C
}  ;       \\ D

main()
{
  struct student *student1; \\ E
  struct student student2;  \\ F
  char s1[30];
  float  f;
  student1 = &student2; \\ G
  scanf(“ % s”, name); \\ H
  scanf(“ % f”, & f); \\ I
  *student1.name = s1;  \\ J  student1-> name = f;
  *student2.marks = f;  \\ K  student1-> marks = s1;
  printf(“ Name is % s \n”, *student1.name); \\ L
  printf(“ Marks are % f \n”, *student2.marks);  \\ M
}
