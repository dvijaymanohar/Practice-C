#include <stdio.h>

//Program : 1 Finding the elements of the structure by dereferencing a poineter
#if 0
struct
{
  int i;
  char a[4];
} test;

int main(void)
{
  char *ptr = (char *)&test;
  test.i = 14;
  printf("\nEnter some text here: ");
  scanf("%s", &test.a);
  printf("\ni = %d", *(long *)ptr);
  printf("\nAdd of a : %u\t Ptr = %u", &test.a, ptr + 4);
  printf("\na[1] = %c", *(ptr + 5));
  getch();
  return 0;
}

//Program : 2 Dereferencing a NULL string
int main()
{
  char *c = NULL;
  c = NULL;
  printf("%d", strlen(c));
}
//Trying to dereference a location that is to search for '\0' characters in that.
//str[0] = '\0';


//Program :  3 Number to Char array
int main(void)
{
  char a[12];
  sprintf(a, "%d", 123456);
  printf("a: %s", a);
  getch();
  return 0;
}

//Program : 4 Printing into an array
int main(void)
{
  char a[45];
  sprintf(a, "\nMy name is Vijay Manohar");
  printf(a);
  getch();
  return 0;
}

//Program : 5 Access objects [functions and variable] from a different file
#include  "test_func.c"

int main(void)
{
  extern int i;// = 20;
  i = 10;
  other();
  getch();
  return 0;
}

//Program : 6 Insertion Sort
int main(void)
{
  void insertion(int a[], int);
  int a[10] = {1, 4, 35, 21, 78, 32, 8, 45, 87, 43};
  int index;
  printf("\nUnsorted Array: \n");
  
  for (index = 0; index < sizeof a / sizeof(int); index++) { printf("\t%d", a[index]); }
  
  putchar('\n');
  insertion(a, sizeof a / sizeof(int));
  printf("\nSorted Array: \n");
  
  for (index = 0; index < sizeof a / sizeof(int); index++) { printf("\t%d", a[index]); }
  
  putchar('\n');
  system("pause");
  return 0;
}

void insertion(int a[], int n)
{
  int i, j, item;
  
  for (i = 1; i < n; i++)
  {
    for (j = i - 1, item = a[i]; j >= 0 && item < a[j]; j--) { a[j + 1] = a[j]; }
    
    a[j + 1] = item;
  }
}

//Program 7: Prinf in for loop //Very good printing
int main(void)
{
  int i;
  
  for (i = 0; i < 10; printf("%8.4d Vijay Manohar\n", i + 1), i++);
  
  //This means, it has to print 5 digits where number printing and along with the
  //spaces count upto 8
  putchar('\n');
  system("pause");
  return 0;
}

//Program 8: int Array filled with zeroes
int main()
{
  int a[20] = {0};
  int i;
  
  for (i = 0; i < 20; i++) { printf("%d", a[i]); }
  
  putchar('\n');
  system("pause");
  return 0;
}

//Program 9 : Test
int main(void)
{
  char a[] = "";
  putchar(a[0]);
  printf("\n435345 / 25.4 = %f", 435345 / 25.4);
  putchar('\n');
  system("pause");
  return 0;
}

//Program 10 : =- 1
int main(void)
{
  int i = 1;
  i = - 1;
  printf("%d\n", i);
  system("pause");
  return 0;
}

//Program 11:
#define SQ(x) ((x) * (x))
int main(void)
{
  static int i;
  printf("%d Square : %ld", 16, SQ(16));
  printf("\ni = %d", i);
  system("pause");
  return 0;
}

//Program : 12 Generic pointer
int main(void)
{
  void *ptr;
  int i = 6;
  ptr = (void *) &i;
  printf("i = %d\n", *(int *) ptr);
  system("pause");
  return 0;
}

//Program : 13 To find whether the number is power of 2
char check_power(int);
void main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("\nVery few arguments:\nUsage: basic.exe <number>\n");
    return -1;
  }
  
  //  int n = atoi (argv[1]);
  check_power(atoi(argv[1])) ? printf("\nEntered number is a power of 2\n") : \
  printf("\nEntered number is not a power of 2\n");
  return 0;
}

char check_power(int n)
{
  n = 4;
  int num = ~n + 1;
  printf("num = %d", num);
  
  if ((num + 1) == n) { return 1; }
  else { return 0; }
}

//Program : Permutations and Combinations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(unsigned length, char *string)
{
  char save;
  save = *string;
  
  while (--length)
  {
    *string = *(string + 1);
    ++string;
  }
  
  *string = save;
}

void permute(unsigned length, char *string, unsigned depth)
{
  if (length == 0) { printf("%s\n", string - depth); }
  else
  {
    unsigned count;
    
    for (count = length ; count > 0; --count)
    {
      permute(length - 1, string + 1, depth + 1);
      rotate(length, string);
    }
  }
}


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Invalid no-of arguments\nUsage: basic.exe <word to be permuted>\n");
    return (-1);
  }
  
  while (--argc)
  {
    char *source = malloc(strlen(*++argv) + 1);
    
    if (source)
    {
      strcpy(source, *argv);
      printf("\nPermuting \"%s\"\n", source);
      permute(strlen(source), source, 0);
      free(source);
    }
  }
  
  return EXIT_SUCCESS;
}

//Program:Macro related
#define MAX() 20
int main()
{
  int i = MAX();
  printf("i = %d", i);
  getch();
  return 0;
}

//Program: char to long
int main()
{
  char a = -7;//0x87;
  long n;
  char *ptr = &a;
  n = *ptr;
  printf("%d", n);
  getch();
  return 0;
}

#endif

//Program : Converting float to int
#define DELTA 0.0005
int main()
{
  float f = 4353.3245;
  char flag;
  long n = 0;
  
  if (f < 0) { f = -f; flag = 1;}
  
  for (n = 0; f - n >= DELTA; n = f *= 10);
  
  if (flag) { n = -n; }
  
  printf("n = %d", n);
  getch();
  return 0;
}

