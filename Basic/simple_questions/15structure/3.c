struct student
{
  name char[30];
  marks float;
}
main()
{
  struct student student1;
  student1 = read_student()
             print_student(student1);
  read_student_p(student1);
  print_student(student1);
}
struct student read_student() \\ A
{
  struct student student2;
  gets(student2.name);
  scanf(“ % d”, &student2.marks);
  return (student2);
}
void print_student(struct student student2)  \\ B
{
  printf(“name is % s\n”, student2.name);
  printf(“marks are % d\n”, student2.marks);
}
void read_student_p(struct student student2)  \\ C
{
  gets(student2.name);
  scanf(“ % d”, &student2.marks);
  
}
