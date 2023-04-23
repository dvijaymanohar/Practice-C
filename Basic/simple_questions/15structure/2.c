Struct address    \\ A
{
  plot char [30], struc char[30];
  city char[30]
}
struct student    \\ B
{
  name char[30];
  marks float;
  struct address adr;   \\ C
}
main()
{
  struct student student1;  \\ D
  struct student class[20]; \\ E
  class[1].marks = 70;  \\ F
  class[1].name = “ Anil “;
  class[1].adr.plot = “7 ”;   \\ G
  class[1].adr.street = “ Mg Road”;
  class[1].adr.city = “mumbai”;
  printf(“ Marks are % d\n”, class[1].marks);
  printf(“ name are % s\n”, class[1].name);
  printf(“ adr.plot is % s\n”, class[1].adr.plot);
  printf(“ adr.street is % s\n”, class[1].adr.stret);
  printf(“ adr.city is % s\n”, class[1].adr.city);
}
