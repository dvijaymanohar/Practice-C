union marks   \\ A
{
  float perc; \\ B
  char grade; \\ C
}
main()
{
  union marks student1; \\ E
  student1.perc = 98.5; \\ F
  printf(“Marks are % f   address is  % 16lu\n”, student1.perc, &student1.perc);  \\ G
  student1.grade = ‘A’’;  \\ H
  printf(“Grade is  % c  address is  % 16lu\n”, student1.grade, &student1.grade); \\ I
}

