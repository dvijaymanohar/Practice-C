#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST
#define DEBUG 1
/*
// Program : 1
int main (int argc, char *argv[]) {
  int i = atoi (argv[1]) ;
  printf("\n%c", i);
  return 0;
}

//Program : 2 Pointer and ordinary Variable assignments

  unsigned int a;
  char *c = "Manu";
  a = c;
  printf("%u", c);
  c++;
  printf("\n%u\t%c\t%s", c, *c, c);
  c = a;
  printf("\n%u\t%s", c, c);

//  Program 3: scanf function

  int b = 5;;
  int *ptr = &b;
  unsigned int a = ptr;
  scanf("%d", a);
  printf("\n%d\t%d", *ptr, b);

// Now 'a' contains the adress of b, so we are passing the address the address to
//the scanf function to read the value with that address. if we enter the value
//with scanf fucntion, whatever the value we entered, that will be assigned to 'b'

//Program 4 : scanf function

  scanf("%d", 5);

//  Seg Fault: We are to change the value at the adress not allocated for us.

//Program 5:

  struct xx
  {
    int x = 3;
    char name[] = "Hell0";
  }

  struct xx *s;
  printf("%d", s->x);
  printf("%s", s->name);

  //Initialisato is not possible in struct itself

//Program 6:

  char *p = "Hai Friends", *ptr;
  ptr = p;
  while (*p != '\0') ++ *ptr;

  // We are trying to change the readonly value, so would get seg fault

//Notes: Ascci value of \n is 10.

//Program 7:

  int a = 5;
  printf("%d", * &a);

//  output:5

//Program 8:

  char *ptr = "Vijay Manohar";
  printf("%c", *&*ptr);
// Derefercing and address operator gets cancelled

//Program : 9

  main(); //Calling the main
  //  Stack overflow. So we would get seg fault

//Program : 10
  int i = 8;
  printf("%d", i++ + ++i);

  // Compiler dependent

//Program : 11

  int i;
  printf("%d", scanf("%d", i));
  //output: 1


//Program: 12
int main()
{
  char str[] = "Vijay Manohar";
  display(str);
  // output: Vijay Manohar
  return 0;
}
void display(char *str)
{
  printf("%s", str);
}


//Program :13
  printf("%d\t%d", sizeof("vmd"), sizeof('a'));
  //Output: 4 4. This is so because, by default each string is terminated with \0 character.
  // so we get first 4. In the second case, it is checking the ascii value for 97

//Program :14

  if (!TEST)
    printf("\n%d",TEST);
  else
    printf("Get Lost");
  //Output: Error

//Program:15

  static int i =5;
  if( --i )
  {
    main();
    printf("%d\t", i);
  }
  //Output: 0 0 0 0


//Program: 16

  signed char i = 0;
  for (; i >= 0; i++);
    printf("%d\n", i);
  //output: -128


//Program: 17 Passing the total array to a function

int main()
{
  char a[] = "VMD";
  void display(char a[], int);
  display(a, 3);
  return 0;
}

void display(char a[], int n)
{
  int i;
  for(i = 0; i < n; i++)
    putchar(a[i]);
}

//Program: 18 Sample Command Line arguments

int main(int argc, char *argv[])
{
  int i;
  if (argc < 2)
  {
    printf("Hey! Did U forgot to type Ur name in the above line ?\n");
    exit(0);
  }
  for(i = 0; i <= argc + 7; i++)
    printf("%s\t", argv[i]);
  return 0;
}

//output : We would get null and then some environmental variables

//Program 19. Coutn down program from command line

int main (int argc, char *argv[])
{
  int count, display = 0;

  if (argc < 2){
    printf("\n Too few arguments");
    exit(1);
  }

  if ( (argc == 3) && !(strcmp("display", argv[2])) )
    display = 1;
//  printf("argv[1] = %d", atoi(argv[1]));

  for (count = atoi(argv[1]); count > 0; count--)
    if (display)  printf("%d\n", count);

  putchar('\a');
  return 0;
}


//Program: 20 Environmental Variables

int main(int argc, char *argv[], char *envp[])
{
  while (*envp) {
    if ( !(strcmp(*envp, "Vijay")) )  printf("\nFound\n\n\n\n\n\n\n");
    printf("%s\n", *envp++);
  }
  return 0;

}

//Program :21 Swapping the odd and even indexing characters in an array

int main(void)
{
  int i, temp;
  char a[] = "VijayManohar";
  printf("\n%s\n", a);
  for (i = 0; a[i + 1] != '\0'; i++)
  {
    if (i % 2 == 0)
    {
      temp = a[i];
      a[i] = a[i + 1];
      a[i + 1] = temp;
    }

  }
  printf("\n%s\n", a);
  return 0;
}



//Program: 22 Preprocessors

#define X 5
#define Y 10
#define AND
#define PRINT printf("\nVijay Manohar\n");
#define VMD int
VMD main()
{
  if(X < Y)AND PRINT;
  return 0;
}


//Program: 23 Invalid Arguments to Macro call

#define COPY(src, des)  strcpy(des, src)
int main()
{
  char *src = "Vijay Manohar", des[25];
  COPY(src, des);
  printf("\nSource String: %s\nDestination String: %s\n", src, des);
  return 0;
}

//Program: 24 Finding maximum of 3 numbers

#define MAX(x, y) x > y ? x : y
int main(void)
{
  int x, y, z;
  printf("\nMaximum of three numbers, %d, %d and %d is %d\n", x, y, z, MAX(x, MAX(y, z)));
  return 0;
}



//Program:24  Undefining a Macro

#define VMD 65
int main()
{
  #undef VMD
  int i = printf("\nVMD = %c", VMD);
  printf("\ni : %d", i);
  return 0;
}


//Program:25  Conditional Compilation

#define VMD 14
int main(void)
{
  int a = 5, b = 10;
  #if a > b
    printf("Hi!, This is VMD\n");
  #else
    printf("This is Vijay Manohar\n");
  #endif
  return 0;
}



//Program:26  Fibinacci Series

#include <stdio.h>

int main(void)
{
  unsigned long fibinacci(int);
  int a = 0, b = 1;
  printf("%d\t%d", a, b);
  fibinacci(b);
  return 0;
}

unsigned long fibinacci(int sum)
{
  static int count = 0, a = 0, b = 1;
  if (count <= 30)
    return b;
  else
  {
    a = b;
    b = sum;
    count++;
    printf("%ld", fibinacci(b));
  }
  return;
}


//Get the relation for e power of x and sinx


//Program :27 Array out of bounds

#include <stdio.h>


int main(void)
{
  int a[] = {1, 2, 3, 4, 5, };
  int i, n = sizeof(a)/sizeof(int);
  for (i = 0; i <= n; i++)
    printf("%d\t", a[i]);
  return 0;
}

//Program : 28 Size of pointer

#include <stdio.h>

int main()
{
  char ptr[] = "Vijay Manohar";
  printf("\n%d\n", sizeof((char *)ptr));
  return 0;
}


//Output : 4 bytes

//Program: 29

#include <stdio.h>

int main()
{
  int j,i = 5;
  j = -i++;
  printf("\nj:  %d\n", j);
  printf("\ni:  %d\n", i);
  return 0;
}

//Output: ++ got higher precedence than -. So -5 gets assigned to j {Post increamentation}.
//Minus sign is not effecting the value of i. So, when we are printing the value of i,
//we are getting as 6
// When the same variable got operated on the same variable twice, the result can be compiler dependant.



//Program:30 Double Recursive Calls, Expect the output

#include <stdio.h>

int main()
{
  void foo(char ch[]);
  foo("123");
  return 0;
}

void foo(char ch[])
{
  static unsigned long int count = 0;
  count++;
  if (ch[1] == '\0')
  {
    printf("\nVijay Manohar\n");
    return;
  }
  foo(ch + 1);
  foo(ch + 200);
  printf("%c", ch[1]);
  printf("\nCount: %ld\n", count);
  return;
}

//Output: This depends upon the contents of the memory location

//Program : 32  After calling the main for some time, it will generate seg faults

#include <stdio.h>

int main()
{
  static unsigned long count = 0;
  count++;
//  if (count == 30) return ;
  printf("\nVMD Count = %ld\n", count);
  printf("%p", main());
  return 0;
}



//Program:33  Observe the usage of stack by the compiler
//Trace the culprit

#include <stdio.h>

int main()
{
  void reverse(void);
  reverse();
  return 0;
}

void reverse(void)
{
  static char ch;
  if ( (ch = getchar()) != '0') reverse();
  putchar(ch);
}
// TOH, sinx, cosx, e power of x

//Program: 34 Sum of the digits

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int sum, i = atoi(argv[1]);
  int sumdigit(int);
//  printf("\nargv:%d", atoi(argv[1]) );
  sum = sumdigit(i);
  printf("\nSum of digits : %d", sum);
  return 0;
}

int sumdigit(int n)
{
  int sum = 0, rem;

  while (n > 0)
  {
    rem = n % 10;
    n = n / 10;
    sum += rem;
  }
  return sum;
}

//Note: we have to supply the number, for which we have to find the sum of digits.
//otherwise we would getr seg fault


//Program: 35 Sum of n numbers using recursion

#include <stdio.h>

int main(int argc, char *argv[])
{
  int sum(int);
  if (argc < 2)
  {
    printf("\nInvalid no of arguments\n");
    return 0;
  }
  return printf("\nSum of %d numbers is %d\n", (int)atoi(argv[1]), sum(atoi(argv[1])) );
}

int sum(int n)
{
  int s = 0;
  if (n == 0) return 0; //In subsequent calls, if sum recieves the value 0, then return 0
  else s += n + sum(n -1);
  return s;
}


//Program: 36 x1 + x2 + x3 +x4...............+xn

#include <stdio.h>
#define n 5
#define debug 1
int main(void)
{
  int a[n];
  int i;
  int sum(int*);
  for (i = 0; i <= 4; i++)  a[i] = i + 1;
  printf("\nExpr: %d\n", sum(&a[0]));
  return 0;
}

int sum(int *ptr)
{
  static int i = 0, s = 0;
  if (debug) printf("\n%d\t%d\t\n", i, ptr[i]);
  printf("%d\t", ptr[i+1]);
  if (i == n - 1) return 0;
  else
  {
    printf("\ns = %d\n", s);i++;
    s += *(ptr+ i)+ sum(ptr + i+1);
  }
  return s;
}

// Note: Error

//Program: 37 Fibinacci Series

#include <stdio.h>
#define debug 1
int main(void)
{
  int n, ret = 0;
  int fibinacci(int);
  printf("\nHow many fibinacci numbers U want:");
  do{
    ret = scanf("%d", &n);
    if (!ret) printf("\nEnter an integer here:");
    while(getchar() != '\n');
  }while (!ret);
  printf("\nCalling fibinacci\n");
  fibinacci(n);
  return 0;
}
int fibinacci(int n)
{
  int sum = 0;
  if (n == 1) return 1;
  if (n == 0) return 0;
  printf("%d\t", fibinacci(n - 1) + fibinacci(n - 2));
  return;
}


//Program : 38 Finding the two largest elements in the array

#include <stdio.h>
#define SIZE  5
int main(void)
{
  int a[SIZE], i, BIG1, BIG2;
  printf("\nEnter the elements into the array here");
  for (i = 0; i < SIZE; i++)
    scanf("%d", a + i);
  BIG1 = BIG2 = a[0];
  for (i = 0; i < SIZE; i++)
    if (BIG1 < a[i])  BIG1 = a[i];
  for (i = 0; i < SIZE; i++)
    if ( (BIG2 < a[i]) && (BIG1 != a[i])) BIG2 = a[i];
  printf("\nFirst Biggest element in the array is %d", BIG1);
  printf("\nSecond Biggest element in the array is %d", BIG2);
  return 0;
}

//Program: 39 Preporcessor

#include <stdio.h>
#define VAR
int main()
{
  VAR;
  if (1)
  printf("%d", 1);
  return 0;
}

//Check output
//Program: 40 Elegant Binary Search

#include <stdio.h>
#define SIZE  5
#define Debug 1
int main(void)
{
  int a[SIZE], i, x;
  void bubble(int *ptr, int n);
  int bsearch(int *ptr, int count, int x);
  printf("\nEnter the elements:");
  for (i = 0; i < SIZE; i++)
    scanf("%d", &a[i]);
  bubble(a, SIZE);
  #if Debug
    printf("\nSorted Elements");
    for (i = 0; i < SIZE; i++)
      printf("%d\t", a[i]);
  #endif;
  printf("\nEnter the element to search here:");
  scanf("%d", &x);
  i = bsearch(a, SIZE, x);
  if (-1 == i)
    printf("\nElement was not there");
  else
    printf("\nThe said element is at position %d", i);
  return 0;
}

void bubble(int *ptr, int n)
{
  register int i, j;
  int temp;
  for (i = n - 1; i >= 0; i--)
    for (j = 1; j <= i; j++ )
      if (ptr[j - 1] > ptr[j])
      {
        temp = ptr[j];
        ptr[j] = ptr[j - 1];
        ptr[j - 1] = temp;
      }
}

int bsearch(int *ptr, int n, int x)
{
  int High = n - 1, Low = 0, Mid;
  while (Low <= High)
  {
    if (ptr[Mid] > x) High = Mid - 1;
    else if (ptr[Mid] < x)  Low = Mid + 1;
    else return Mid;
  }
  return -1;
}

//Program: 41 Function Pointers

#include <stdio.h>
int main()
{
  int (*foo)(void);
  int fool(void);
  foo = &fool;
  printf("This is the value returned from by the function foo is %d\n", foo());
  return 0;
}

int fool(void)
{
  int fool = 0;
  return fool;
}
//Program: 42 Stucture containing Function Pointers

#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  struct Name {
    void (*foo1)(void);
    void (*foo2)(char *envp[]);
  };
  struct Name *VMD = (struct Name*)malloc(sizeof(struct Name)) ;
  void display(void);
  void printEnvp (char *envp[]);

  VMD->foo1 = display;
  VMD->foo2 = printEnvp;

  VMD->foo1();
//  getchar();
  VMD->foo2(envp);
  return 0;
}

void display() {
  printf("\nVijay Manohar Dogiparthi\n");
  return;
}

void printEnvp(char *envp[]) {
  int i;
  while (*envp[i]) {
    printf ("\nNo of environment Variables : %d\n", i - 1);
      printf ("\n\t%s",envp[i++]);
    }
}

//Program:43 scanf function

#include <stdio.h>

int main(void)
{
  char ch[25], i = 0;
  printf("Enter Ur Name here:");
  scanf("%[^\n]", &ch[i++]);
  printf("\nValue of i: %d\n", i);
  printf(ch);
  for(i = 0; ch[i] != '\0'; i++);
  printf("\nValue of i: %d\n", i);
}

//Program: 44 Program for Calculating the money required to take xerox of a book

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf ("\n\tInvalid no. of arguments\n");
    return  0;
  }
  if (0 == (strcmp("b2b", argv[2])) )
    printf ("\n\tPrice to take xerox of your book : %lf rupees\n\n", 0.4 * atoi (argv[1]) / 2 );
  else
    printf ("\n\tPrice to take xerox of your book : %lf rupees\n\n", 0.4 * atoi (argv[1]) );
  return 0;
}


//Program : 45 Prg that differentiates the difference between Windows and Unix/Linux

#include <stdio.h>

int main (argc, argv)
int argc;
char *argv[];
{
  int i;
  printf ("\nArguments:\n");
  for (i = 0; i < argc; i++)  printf ("%s\n", argv[i]);
  return 0;
}


//Program: 46 Prg that redefines a variable

#include <stdio.h>
#define X 1
#define X X - 1
int main()
{
  printf ("VMD");
  return 0;
}

//Program: 47 Prg that prints a size of a type without using sizeof


#include <stdio.h>
int main()
{
  int i;
  int *ptr = &i;
  printf ("\n\tSize of int i is %d\n", (char *)(ptr + 1) - (char *)ptr );
  return 0;
}

//Program 48 Bit Fields 1

#include <stdio.h>

int main(int argc, char *argv[]) {
  typedef struct {
    unsigned bit0 : 1;
    unsigned bit1 : 1;
    unsigned bit2 : 1;
    unsigned bit3 : 1;
    unsigned bit4 : 1;
    unsigned bit5 : 1;
    unsigned bit6 : 1;
    unsigned bit7 : 1;
  } vmd_t;
  vmd_t word1, word2;


  word1.bit0 = 1; //Enabling a particular bit leaving remaining

  word2 = word1;  //Fun: structure variable assignment is possible

  if (word2.bit0) printf ("Bit0 is set\n");
  else printf ("Bit0 is not set\n");

  vmd_t *word3;
  word3->bit6 = 1;  //Accessing through a pointer

  return 0;
}

//Program 49 A mix of Bit Fields and Unions

#include <stdio.h>
int main(int argc, char *argv[]) {

  typedef union {
    char ch;
    struct status_type {
      unsigned bit0 : 1;
      unsigned bit1 : 1;
      unsigned bit2 : 1;
      unsigned bit3 : 1;
      unsigned bit4 : 1;
      unsigned bit5 : 1;
      unsigned bit6 : 1;
      unsigned bit7 : 1;
    }byte;
  }state;

  state *vmd = (state *) malloc (sizeof(state));
  vmd->ch = 4;
  if (vmd->byte.bit0) printf ("\n\tBit0 is set\n");
  if (vmd->byte.bit1) printf ("\n\tBit1 is set\n");
  if (vmd->byte.bit2) printf ("\n\tBit2 is set\n");
  return 0;
}

//Program 50 A structure containing bitfields

#include <stdio.h>
int main() {
  int working;
  typedef struct {
    char name[25];
    int roll;
    unsigned working :  1;  //Whether employed
    unsigned Married :  1;  //Even without this field we would get 36 bytes. Think of address bus
  }student_t;

  student_t *vmd;
  vmd = (student_t *) malloc (sizeof (student_t));
  printf ("\n\tEnter the Student Name here:");
  scanf ("%s", vmd->name);
  printf ("\n\tEnter the Student roll number here:");
  scanf ("%d", &vmd->roll);
  printf ("\n\tWhehter Student is working currenlty say yes (1) or No (0):");
  scanf ("%d", &working);
  vmd->working = working;

  printf ("\n\tStudent Name entered: %s", vmd->name);
  printf ("\n\tStudent Roll Number: %d", vmd->roll);
  printf ("\n\tWorking: %d\n", vmd->working);
  printf ("\n\n\tSize of the total Structure: %d\n", sizeof(student_t));
//  printf ("\n\n\tSize of int: %d Bytes\n", sizeof(int));
  return 0;
}

//Program 51  Enumeration and Bitfields
#include <stdio.h>
int main(int argc, char *argv[]) {
  typedef union {
    enum work {idle, working} manu;
    unsigned working;
  }task_t;
  task_t *vmd;

  vmd = (task_t *) malloc (sizeof(task_t));
  vmd->manu = working;
  vmd->working = vmd->manu;
  if (vmd->working) printf ("\n\tVMD is working to learn the miscellaneous issues in C currently\n");
  else printf ("\n\tvmd is idle\n");
  return 0;
}

//Program 52  Enumerations
#include <stdio.h>
int main(int argc, char *argv[]) {
  int i;
  if (argc != 2) {
    printf ("\n\tInvalid no of arguments\n");
    exit (1);
  }
  enum coin {penny, dime, dollar};
  enum coin money;
  printf ("Money = %d", dollar);
  i = atoi(argv[1]);
//  dollar = i;
  money = i;
  printf ("Money = %d", money);
  return 0;
}

//Program 53 Swapping two integers using exclusive OR operator
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
  if (argc != 3) {
    printf ("\n\tUsage : %s <first value> <Second integer>\n", argv[0]);
    exit (EXIT_FAILURE);
  }
  int a = atoi (argv[1]), b = atoi (argv[2]);
  a ^= b ^= a ^= b;
  printf ("\ta = %d\tb = %d\n", a, b);
  return 0;
}

//Program 54 Size of
#include <stdio.h>
#define VMD_sizeof(n) (n *)0 + 1
#define VMD(n) n
int main (int argc, char *argv[]) {
  printf ("%d", VMD_sizeof(argv[1]) );
  return 0;
}


//Program 55 Sorting Multiple Data Types
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VMD_sizeof(n) (n *)0 + 1
#define MAX_BUF 256

void bubble(void *p, int width, int N, int(*fptr)(const void *, const void *));
int compare_str(const void *m, const void *n);
int compare_long(const void *m, const void *n);

int main(int argc, char *argv[]) {
  int i, size = atoi (argv[1]);
  long a[size];
  char Names[5][20];

  printf ("\n\tEnter the elements in to the array here:");
  for (i = 0; i < size; i++)  scanf ("%ld", &a[i]);

  puts("\nWitness Ur numbers before Sorting:\n");
  for (i = 0; i < size; i++) printf("%ld ",a[i]);

  printf ("\n\tEnter some strings to sort:");
  for (i = 0; i < 5; i++) scanf ("%s", Names[i]);

  puts("\n");
  for (i = 0; i < 5; i++) printf("%s\t", Names[i]);
  bubble(a, VMD_sizeof (long), size, compare_long);
  bubble(Names, 20, 5, compare_str);

  puts("\n\nAfter Sorting:\n");

  for (i = 0; i < size; i++)  printf("%ld\t", a[i]);
  puts("\n");

  for (i = 0; i < 5; i++) printf("%s\t", Names[i]);
  return 0;
}

void bubble(void *p, int width, int N, int(*fptr)(const void *, const void *)) {
  int i, j, k;
  unsigned char buf[MAX_BUF];
  unsigned char *bp = p;
  for (i = N-1; i >= 0; i--)
    for (j = 1; j <= i; j++) {
      k = fptr((void *)(bp + width*(j-1)), (void *)(bp + j*width));
      if (k > 0) {
        memcpy(buf, bp + width*(j-1), width);
        memcpy(bp + width*(j-1), bp + j*width , width);
        memcpy(bp + j*width, buf, width);
      }
    }
}

int compare_str(const void *m, const void *n) {
    char *m1 = (char *)m;
    char *n1 = (char *)n;
    return (strcmp(m1,n1));
}

int compare_long(const void *m, const void *n) {
  long *m1, *n1;
  m1 = (long *)m;
  n1 = (long *)n;
  return (*m1 > *n1);
}


//Program 56
#include <stdio.h>
int main(){
  char *str = "I am Vijay Manohar";
  strtok(str, 'a');
  return 0;
}

//Program 57

#include <stdio.h>
#include <string.h>

int  main(void)
{
  char s1[] = "Vijay", s2[] = "VijayManohar";
  int cmp = strcmp(s1,s2);
  if (!(cmp))   printf("\nStrings are equal\n");
  else if (cmp < 0) printf("\nfirst string is {asciily} smaller than string 2 : %d", cmp);
  else    printf("First string is greater than string 2 : %d", cmp);
  return 0;
}


//Program 58
#include <stdio.h>
#include <stdarg.h>
int main(){
  double calc_mean(int num, int print, ...);
  double mean1, mean2, mean3;
  mean1 = calc_mean (4, 5, 2.5, 3.0, 4.6, 4.3, 3.5 );
  printf("\nMean of 5 values is %lf", mean1);
  mean2 = calc_mean (3, 4, 4.6, 5.3, 4.3, 3.5 );
  printf("\nMean of 4 values is %lf\n", mean2);
  mean3 = calc_mean (2, 3, 4.6, 4.3, 3.5 );
  printf("\nMean of 3 values is %lf\n", mean3);
  return 0;
}

double calc_mean(int print,  int num, ...){
  va_list ap;
  double val = 0;
  int i;
  va_start(ap, num);
  for (i = 0; i < num; i++) val = val + va_arg(ap, double);
  va_end(ap);
  for (i = 0; i < print; i++)   printf("%lf\n", val);
  return (val / num);
}


//Program 59

#include <stdio.h>
int main(void)
{
  float  b, c, d, n;
  double a = 4;
  int i;
  printf("\n\t Enter the value to find its square root here:");
  scanf("%f", &n);
  for (i = 0; i < 10; i++) {
    b = n /a;
    c = b + a;
    d = c / 2.0  ;
    a = d;
  }
  printf("Square root of n = %.10lf", a);
  return 0;
}

//Program 60
nt printf(const char *format, ...)
{
        va_list args;
        va_start( args, format );
        return print( 0, format, args );
}

static int print(char **out, const char *format, va_list args )
{
    int width, pad;
    int pc = 0;
    char scr[2];

    for (; *format != 0; ++format)
  {
        if (*format == '%')
    {
          ++format;
            width = pad = 0;

      if (*format == '\0') break;
            if (*format == '%') goto out;
            if (*format == '-')
      {
              ++format;
                pad = PAD_RIGHT;
            }
            while (*format == '0')
      {
                ++format;
                pad |= PAD_ZERO;
            }

      for ( ; *format >= '0' && *format <= '9'; ++format)
      {
                width *= 10;
                width += *format - '0';
            }

      if( *format == 's' )
      {
                register char *s = (char *)va_arg( args, int );
                pc += prints (out, s?s:"(null)", width, pad);
                continue;
            }

      if( *format == 'd' )
      {
                pc += printi (out, va_arg( args, int ), 10, 1, width, pad, 'a');
               continue;
            }

      if( *format == 'x' )
      {
                pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'a');
                continue;
            }

      if( *format == 'X' )
      {
                pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'A');
                continue;
            }

      if( *format == 'u' )
      {
                pc += printi (out, va_arg( args, int ), 10, 0, width, pad, 'a');
                continue;
            }

      if( *format == 'c' )
      {
                // char are converted to int then pushed on the stack
                scr[0] = (char)va_arg( args, int );
                scr[1] = '\0';
                pc += prints (out, scr, width, pad);
                continue;
            }
        }
        else
    {
        out:
              printchar (out, *format);
              ++pc;
        }
    }
    if (out) **out = '\0';
    va_end( args );
    return pc;
}

//Program 61
#include <stdio.h>
int  main()
{
  char ch;
  int i;
  i = scanf("%[^,]", &ch);
  printf("\ni = %d", i);
  return 0;
}

//Program 62

#include <stdio.h>
#include <stdlib.h>
typedef union {
  int num;
  char ch[2];
}word_t;

int main(int argc, char *argv[2]) {
  FILE *fp = fopen("Sai.txt", "wb+");
  int n;
  int putInteger (int n, FILE *fp);
  if (argc != 2)  {
    printf ("\nInvalid no of arguments\n");
    exit(1);
  }
  n = atoi (argv[1]);
  putInteger (n, fp);

  while(!feof(fp))  printf ("%d",getc(fp));
  fclose(fp);
  return 0;
}

int putInteger (int n, FILE *fp){
  word_t word;
  word.num = n;
  putc (word.ch[0], fp);
  return putc (word.ch[1], fp);
}

//Program 63

#include<stdio.h>
int main()
{
  char *ptr="National Institute of Technology";
  printf("\n\n%c", *ptr);
  printf("\n\n%s\n\n", ptr);
  return 0;
}

//Program 64

#include<stdio.h>
//#include<alloc.h>

int main()
{
  int *ptr, size;
  int Small, Big;
  float Avg;
  static int i;
  printf("\n\nEnter the size of the array here:");
  scanf("%d", &size);
  ptr=malloc(size*sizeof(int));
  printf("\n\nEnter the elements into the array here:");
  for(;i<size;)
    scanf("%d",&ptr[i++]);
  Small=ptr[0];Big=ptr[0];
  for(i=0;i<size;i++)
  {
    if(Small>ptr[i])
      Small=*(ptr+i);
    if(Big<ptr[i])
      Big=ptr[i];
  }
  Avg=(float)(Small+Big)/2;
  printf("\n\nAverage of Smallest and Largest numbers in the array is  %f\n\n", Avg);
  return 0;
}

//Program 65

#include<stdio.h>
int main()
{
  int a[5], *ptr1, i=0;
  char c, *ptr2;
  void *ptr3;
  c='a';ptr2=&c;
  ptr1=a;
  printf("Enter the elements in to the array:");
  for(;i<5;)
    scanf("%d", &i++[a]);
  for(i=0;i<5;i++)
  printf("\n%d", *ptr1++);
  printf("\n\n%u    %d\n\n", ptr1, sizeof(ptr1));
  printf("\n\n%u          %d\n\n", ptr2, sizeof(ptr2));
  printf("\n\n%u          %d\n\n", c, sizeof(c));
  ptr3=&c;
  printf("\n\n%u          %d\n\n", ptr3, sizeof(ptr3));
  ptr3=&i;
  printf("\n\n%u          %d\n\n", ptr3, sizeof(ptr3));
  return 0;
}

//Program 66


#include <stdarg.h>

static void printchar(char **str, int c)
{
  extern int putchar(int c);

  if (str) {
    **str = c;
    ++(*str);
  }
  else (void)putchar(c);
}

#define PAD_RIGHT 1
#define PAD_ZERO 2

static int prints(char **out, const char *string, int width, int pad)
{
  register int pc = 0, padchar = ' ';

  if (width > 0) {
    register int len = 0;
    register const char *ptr;
    for (ptr = string; *ptr; ++ptr) ++len;
    if (len >= width) width = 0;
    else width -= len;
    if (pad & PAD_ZERO) padchar = '0';
  }
  if (!(pad & PAD_RIGHT)) {
    for ( ; width > 0; --width) {
      printchar (out, padchar);
      ++pc;
    }
  }
  for ( ; *string ; ++string) {
    printchar (out, *string);
    ++pc;
  }
  for ( ; width > 0; --width) {
    printchar (out, padchar);
    ++pc;
  }

  return pc;
}

// the following should be enough for 32 bit int
#define PRINT_BUF_LEN 12

static int printi(char **out, int i, int b, int sg, int width, int pad, int letbase)
{
  char print_buf[PRINT_BUF_LEN];
  register char *s;
  register int t, neg = 0, pc = 0;
  register unsigned int u = i;

  if (i == 0) {
    print_buf[0] = '0';
    print_buf[1] = '\0';
    return prints (out, print_buf, width, pad);
  }

  if (sg && b == 10 && i < 0) {
    neg = 1;
    u = -i;
  }

  s = print_buf + PRINT_BUF_LEN-1;
  *s = '\0';

  while (u) {
    t = u % b;
    if( t >= 10 )
      t += letbase - '0' - 10;
    *--s = t + '0';
    u /= b;
  }

  if (neg) {
    if( width && (pad & PAD_ZERO) ) {
      printchar (out, '-');
      ++pc;
      --width;
    }
    else {
      *--s = '-';
    }
  }

  return pc + prints (out, s, width, pad);
}

static int print(char **out, const char *format, va_list args )
{
  register int width, pad;
  register int pc = 0;
  char scr[2];

  for (; *format != 0; ++format) {
    if (*format == '%') {
      ++format;
      width = pad = 0;
      if (*format == '\0') break;
      if (*format == '%') goto out;
      if (*format == '-') {
        ++format;
        pad = PAD_RIGHT;
      }
      while (*format == '0') {
        ++format;
        pad |= PAD_ZERO;
      }
      for ( ; *format >= '0' && *format <= '9'; ++format) {
        width *= 10;
        width += *format - '0';
      }
      if( *format == 's' ) {
        register char *s = (char *)va_arg( args, int );
        pc += prints (out, s?s:"(null)", width, pad);
        continue;
      }
      if( *format == 'd' ) {
        pc += printi (out, va_arg( args, int ), 10, 1, width, pad, 'a');
        continue;
      }
      if( *format == 'x' ) {
        pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'a');
        continue;
      }
      if( *format == 'X' ) {
        pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'A');
        continue;
      }
      if( *format == 'u' ) {
        pc += printi (out, va_arg( args, int ), 10, 0, width, pad, 'a');
        continue;
      }
      if( *format == 'c' ) {
        // char are converted to int then pushed on the stack
        scr[0] = (char)va_arg( args, int );
        scr[1] = '\0';
        pc += prints (out, scr, width, pad);
        continue;
      }
    }
    else {
    out:
      printchar (out, *format);
      ++pc;
    }
  }
  if (out) **out = '\0';
  va_end( args );
  return pc;
}

int printf(const char *format, ...)
{
        va_list args;

        va_start( args, format );
        return print( 0, format, args );
}

int sprintf(char *out, const char *format, ...)
{
        va_list args;

        va_start( args, format );
        return print( &out, format, args );
}

#ifdef TEST_PRINTF
int main(void)
{
  char *ptr = "Hello world!";
  char *np = 0;
  int i = 5;
  unsigned int bs = sizeof(int)*8;
  int mi;
  char buf[80];

  mi = (1 << (bs-1)) + 1;
  printf("%s\n", ptr);
  printf("printf test\n");
  printf("%s is null pointer\n", np);
  printf("%d = 5\n", i);
  printf("%d = - max int\n", mi);
  printf("char %c = 'a'\n", 'a');
  printf("hex %x = ff\n", 0xff);
  printf("hex %02x = 00\n", 0);
  printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
  printf("%d %s(s)%", 0, "message");
  printf("\n");
  printf("%d %s(s) with %%\n", 0, "message");
  sprintf(buf, "justif: \"%-10s\"\n", "left"); printf("%s", buf);
  sprintf(buf, "justif: \"%10s\"\n", "right"); printf("%s", buf);
  sprintf(buf, " 3: %04d zero padded\n", 3); printf("%s", buf);
  sprintf(buf, " 3: %-4d left justif.\n", 3); printf("%s", buf);
  sprintf(buf, " 3: %4d right justif.\n", 3); printf("%s", buf);
  sprintf(buf, "-3: %04d zero padded\n", -3); printf("%s", buf);
  sprintf(buf, "-3: %-4d left justif.\n", -3); printf("%s", buf);
  sprintf(buf, "-3: %4d right justif.\n", -3); printf("%s", buf);

  return 0;
}

#if DEBUG
 * if you compile this file with
 *   gcc -Wall $(YOUR_C_OPTIONS) -DTEST_PRINTF -c printf.c
 * you will get a normal warning:
 *   printf.c:214: warning: spurious trailing `%' in format
 * this line is testing an invalid % at the end of the format string.
 *
 * this should display (on 32bit int machine) :
 *
 * Hello world!
 * printf test
 * (null) is null pointer
 * 5 = 5
 * -2147483647 = - max int
 * char a = 'a'
 * hex ff = ff
 * hex 00 = 00
 * signed -3 = unsigned 4294967293 = hex fffffffd
 * 0 message(s)
 * 0 message(s) with %
 * justif: "left      "
 * justif: "     right"
 *  3: 0003 zero padded
 *  3: 3    left justif.
 *  3:    3 right justif.
 * -3: -003 zero padded
 * -3: -3   left justif.
 * -3:   -3 right justif.
#endif

//Program  67
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  initscr();
  move(43,15);
  printw("%s", "V");
  exit(EXIT_SUCCESS);
}

//Program 68
#include <stdio.h>
#define COLS  5
int main(void)
{
  printf("\nCOLS = %d", COLS);
  COLS++;
  printf("\nCOLS = %d", COLS);
  return 0;
}

//Program 69

#include <stdio.h>
int main()
{
  int i = 1, j = 2;
  bool condition = i > j;
  if (! condition)  printf("\nj is greater than i\n");
  return 0;
}

//Program 70

#include <stdio.h>
int main(int argc, char *argv[]) {
  typedef struct {
    unsigned bit0 : 1;
    unsigned bit1 : 1;
    unsigned bit2 : 1;
    unsigned bit3 : 1;
    unsigned bit4 : 1;
    unsigned bit5 : 1;
    unsigned bit6 : 1;
    unsigned bit7 : 1;
  }byte_t;

  byte_t vmd;
  vmd.bit0 = 1;

  if (vmd.bit0)  printf ("\n\tBit 0 is Set");
  vmd.bit4 = 1;

  if (vmd.bit4)  printf ("\n\tBit 4 is Set");
  else printf ("\n\tU didn't Bit-Field concept distinctly");
  return 0;
}

//Program 71
#include<stdio.h>
#define Test 1
int main()
{
  int i;
  printf("\n\nEnter a number here:");
  scanf("%d", &i);

  while(i != -1)
  {
    if((i & Test)!=0)
      printf("\nEntered no is odd");
    else
      printf("\nEntered no is even");
    printf("\n\nEnter a no to test:");
    scanf("%d", &i);
  }
  return 0;
}
//Program 72

#include<stdio.h>
#define Test 4
int main()
{
  int Flag=10;
  if((Flag & Test)!=0)  //To test whether 3 bit is set..
    printf("\n\nBit is set\n\n");
  else
    printf("\n\nBit is not set\n\n");
  return 0;
}

//Program 73

#include <stdio.h>

int main()
{
  int printint();
  printf("\nValue of a:%d ", printint());
  printf("\nValue of a: %d ", printint());
  return 0;
}

int printint()
{
  int i = 10;
  return (&i);
}


//Program 74

int main () {
  float f;
  printf ("\n\tEnter a float value here: ");
  scanf ("%lf", &f);
//  void *ptr;
  printf ("Float Value : %d", f);
  return 0;
}

//Program 75 Stack overflow Recursion
int main (void) {
  int foo (int n, int v);
  return foo (1000000, 100);
}
int foo (int n, int v) {
  printf ("\n\tVijay Manohar");
  if (0 == n) return v;
  else return foo (n - 1, n + v);
}

//Program 76 Merge Sort

void MergeSort (int a[], int N);
void MSort (int a[], int TmpArray[], int Left, int Right);

int main (int argc, char *argv[]) {
  int i, Size = atoi (argv[1]);
  int A[Size];
  printf ("\n\tEnter the elements here :\n");
  for (i = 0; i < Size; i++)  scanf ("%d", A + i);

  printf ("\n\tEntered elements are here :\n\t");
  for (i = 0; i < Size; i++)  printf ("%d\t", A + i);

  MergeSort (A, Size);

  printf ("\n\tSorted elements are here :\n\t");
  for (i = 0; i < Size; i++)  printf ("%d\t", A + i);

  return 0;
}

void MergeSort (int A[], int N) {
  int* TmpArray;
  TmpArray = malloc (N * sizeof (int));

  if (TmpArray != NULL) {
    MSort (A, TmpArray, 0, N - 1);
    free (TmpArray);
  }
  else printf ("\n\tFatal error: No space for temprary array\n");
}

void MSort (int A[], int TmpArray[], int Left, int Right) {
  int Center;
  if (Left < Right) {
    Center = (Left + Right) / 2;
    MSort (A, TmpArray, Left, Center);
    MSort (A, TmpArray, Center + 1, Right);
    Merge (A, TmpArray, Left, Center + 1, Right);
  }
}

//Program 78: To reverse a string
int main () {
  void foo (void);
  foo();
  return 0;
}

void foo (void) {
  char ch;
  if ( (ch  = getchar()) != '\n') foo();
  putchar (ch);
}

//Program 79 Towers of Hanoi
int main() {
  int n;  //no of disks
  printf ("\n\tEnter no of disks here :\n");
  scanf ("%d", &n);
  void transfer (int n, char from, char to, char center);
  transfer (n, 'L', 'R', 'C');
  return 0;
}

void transfer (int n, char from, char to, char center) {
  static int count = 0;;
  if (n > 0) {
    transfer (n - 1, from, center, to);
    count++;
    printf ("%d :Disk %d is moved from %c to %c\n", count, n, from, to);
    transfer (n - 1, center, to, from);
  }
}

//Note: Think of 3 disks and then try solving this problem.


//Program 80 Generic Insertion Sort
#define VMD_sizeof(N) (N *)0 + 1
#define MAX_BUF 256

void Insertion (void *P, int Width, int N, int(*Fptr)(const void *, const void *));
int CompareStr (const void *M, const void *N);
int CompareLong (const void *M, const void *N);

int main (int argc, char *argv[]) {
  int i, Size = atoi (argv[1]);
  long A[Size];
  char Names[Size][20];

  printf ("\n\tEnter the elements in to the array here:");
  for (i = 0; i < Size; i++)  scanf ("%ld", &A[i]);

  puts("\nWitness Ur numbers before Sorting:\n");
  for (i = 0; i < Size; i++) printf ("%ld\t", A[i]);

  printf ("\n\tEnter some strings to sort:");
  for (i = 0; i < Size; i++)  scanf ("%s", Names[i]);

  puts ("\n");
  for (i = 0; i < Size; i++) printf ("%s\t", Names[i]);
  Insertion (A, VMD_sizeof (long), Size, CompareLong);
  Insertion (Names, 20, Size, CompareStr);

  puts ("\n\nAfter Sorting:\n");

  for (i = 0; i < Size; i++)  printf ("%ld\t", A[i]);
  puts ("\n");

  for (i = 0; i < Size; i++)  printf ("%s\t", Names[i]);
  return 0;
}

void Insertion (void *P, int Width, int N, int (*Fptr) (const void *, const void *)) {
  int i, j;
  unsigned char Buf[MAX_BUF];
  unsigned char *Bp = P;
  for (i = 1; i < N; i++) {
    memcpy (Buf, Bp + Width * i, Width);
    for (j = i; j > 0 && Fptr ((void *)(Bp + (j - 1) * Width), (void *)Buf); j--)
        memcpy (Bp + Width * j, Bp + (j - 1) * Width , Width);
    memcpy (Bp + Width * j, Buf, Width);
  }
}

int CompareStr(const void *m, const void *n) {
    char *m1 = (char *)m;
    char *n1 = (char *)n;
    return (strcmp(m1,n1));
}

int CompareLong(const void *m, const void *n) {
  long *m1, *n1;
  m1 = (long *)m;
  n1 = (long *)n;
  return (*m1 > *n1);
}


//Program 81 Insertion Sort

int main (int argc, char *argv[]) {
  int i, Size = atoi (argv[1]);
  int A[Size];
  void Insertion (int A[], int N);

  puts("\nEnter the elements here:");
  for (i = 0; i < Size; i++) scanf ("%d", A +i);
  puts("\nWitness Ur numbers before Sorting:\t");
  for (i = 0; i < Size; i++) printf ("%d\t",A[i]);

  Insertion (A, Size);
  puts ("\nWitness Ur numbers after Sorting:\t");
  for (i = 0; i < Size; i++) printf ("%d\t", A[i]);
  putchar ('\n');
  return 0;
}

void Insertion (int A[], int N) {
  int i, j, temp;
  for (i = 1; i < N; i++) {
    temp = A[i];
    for (j = i; j > 0 && A[j - 1] > temp; j--)  A[j] = A[j - 1];
    A[j] = temp;
  }
}
//Program 82 Assignment Statement
int main () {
  int i, j, k;
  k = (i = 5, j = 6, i + j);
  printf (" i = %d\tj = %d\tk = %d", i, j, k);
  return 0;
}

//Program 83 Environment Varaibles

int main (int argc, char *argv[], char *envp[]) {
  int i = 0;
  while (*envp[i])  printf ("%s\n", envp[i++]);
  return 0;
}

//Program 84 Max and Min of an array

int main (int argc, char *argv[]) {
  if (argc != 2) {
    fprintf (stderr, "Usage: %s <number of the elements in the array>\n", argv[0]);
    exit (EXIT_FAILURE);
  }
  int Size = atoi (argv[1]), i, Min, Max;
  int *A = (int *) malloc (Size * sizeof (int) );

  printf ("\n\tEnter the elements here:");
  for (i = 0; i < Size; i++)  scanf ("%d", A + i);

  printf ("\n\tWitness the elements entered :\t");
  for (i = 0; i < Size; i++)  printf ("%d\t", A[i]);

  Min = Max = A[0];
  for (i = 1; i < Size; i++) {
      if (Min > A[i]) Min = A[i];
      if (Max < A[i]) Max = A[i];
  }

  printf ("\n\tMin of the array : %d\n\tMax of the array : %d\n", Min, Max);
  return 0;
}


//Program 84 Max and Min of an array using divide and conquer approach
int *A;
int main (int argc, char *argv[]) {
  if (argc != 2) {
    fprintf (stderr, "Usage: %s <number of the elements in the array>\n", argv[0]);
    exit (EXIT_FAILURE);
  }
  void DandCMaxMin (int i, int j, int Max, int Min);
  int Size = atoi (argv[1]), i, Min, Max;
  A = (int *) malloc (Size * sizeof (int) );

  printf ("\n\tEnter the elements here:");
  for (i = 0; i < Size; i++)  scanf ("%d", A + i);

  printf ("\n\tWitness the elements entered :\t");
  for (i = 0; i < Size; i++)  printf ("%d\t", A[i]);

  Min = Max = A[0];
  DandCMaxMin (0, Size - 1, Max, Min);
  if (DEBUG) {
    for (i = 1; i < Size; i++) {
      if (Min > A[i]) Min = A[i];
      if (Max < A[i]) Max = A[i];
    }
  }

//  printf ("\n\tMin of the array : %d\n\tMax of the array : %d\n", Min, Max);
  return 0;
}

void DandCMaxMin (int i, int j, int Max, int Min) {
    int Mid, Max1, Min1, Max2, Min2;
  if (DEBUG)  printf ("\n\ti : %d\n\tj : %d\n\tMax : %d\n\tMin : %d", i, j, Max, Min);
    if (i == j) //When there is only one element
        Min = Max = A[i];
    else if (i == j - 1) {  //When there are only two elements
            if (A[i] > A[j]) {
                Max = A[i];
                Min = A[j];
            }
            else {
                Max = A[j];
                Min = A[i];
            }
    }
    else {
        Mid = (i + j) / 2;
        DandCMaxMin (i, Mid, Max1, Min1);
        DandCMaxMin (Mid + 1, j,  Max2, Min2);
        Max = Max1 > Max2 ? Max1 : Max2;
        Min = Min1 < Min2 ? Min1 : Min2;
    }
  printf ("\n\tMin of the array : %d\n\tMax of the array : %d\n", Min, Max);
}

//Program : 85 Finding the two largest elements in the array
#include <stdio.h>
#define SIZE    5
int main(void) {
    int a[SIZE], i, Big1, Big2;
    printf("\nEnter the elements into the array here");
    for (i = 0; i < SIZE; i++)  scanf("%d", a + i);
    Big1 = Big2 = a[0];
    for (i = 0; i < SIZE; i++)
        if (Big1 < a[i])    Big1 = a[i];
    for (i = 0; i < SIZE; i++)
        if ( (Big2 < a[i]) && (Big1 != a[i])) Big2 = a[i];
    printf("\nFirst Biggest element in the array is %d", Big1);
    printf("\nSecond Biggest element in the array is %d", Big2);
    return 0;
}

//Program : 86 #defined Value to a Void pointer
#include <stdio.h>
#define VAL 5
int main () {
  void *ptr = VAL;
  printf ("Ptr Value : %d", *(int *)ptr);
  return 0;
}

//Program 87  strlen
int main () {
  char *Str = "Vijay Manohar";
  int i;
  for (i = 0; Str[i]; i++);
  printf ("\nString Length :  %d\n", i);
  return 0;
}

//Program 88 Ragged Array
int main () {
  void **Str;
  int Rows, Cols, i;
  printf ("\n\tHow many Rows do U want: ");
  scanf ("%d", &Rows);
//  printf ("\n\tHow many Cols do U want: ");
//  scanf ("%d", &Cols);
  Str = (void **) malloc (Rows * sizeof (void *));
  for (i = 0; i < Rows; i++) {
    Str[i] = malloc (sizeof (int *));
    printf ("\nEnter the Number here: ");
    scanf ("%d", (int *)Str[i]);
  }

  for (i = 0; i < Rows; i++) {
    printf ("%d\n", *(int *)Str[i]);
  }
  return 0;
}


//Program 89 Returning int

int main () {
  void* foo(void);
  int j = *(int *)foo();
  printf ("j : %d", j);
  return 0;
}

void *foo() {
  int i = 2, *ptr;
  ptr = &i;
  return (void *)ptr;
}

//Program 90 NRPS

#include <math.h>
int main () {
  int StrLen, k, MaxLen;
  void PrintNRPS (int StrLen, int k);
  printf ("\n\tHow many Distinct characters U want in [0 to 9]:");
  scanf ("%d", &k);
  if (k < 0 || k > 9){
    printf ("\nEnter a Correct Number Man!\n");
    return 0;
  }
  MaxLen = k * (k - 1) + 1;
  printf ("\n\tMaximum Length of the String with these characters : %d", MaxLen);
  printf ("\n\tEnter the length of the string:");
  scanf ("%d", &StrLen);
  if (StrLen < 0 || StrLen > MaxLen) {
    printf ("\nEnter a Correct Number Man!\n");
    return 0;
  }
  printf ("\n\tNRPS of length %d with %d distinct characters :", StrLen, k);
  PrintNRPS (StrLen, k);
  return 0;
}

void PrintNRPS (int StrLen, int K) {
  int i, j, k, Count = 0;
  int Power = pow (K, K);
//  for (k = 1; k < Power; k++) {
    for (i = 0; i < K ; i++)
//      if (i == K - 1) for (k = K - 1; k >= 0; k--) {
        for (j = 1; j < K; j++) {
          if (j <= i) continue;
          printf ("%d", i);
          Count ++;
          if (Count == StrLen) {
            putchar ('\n');
            break ;
          }
          else {
            printf ("%d", j);
            Count ++;
            if (Count == StrLen) {
              putchar ('\n');
              break ;
            }
          }
    //  putchar ('\n');
      }
}

//Program 91 Mix of different in a array
int main () {
  char a[5], b[5];
  a[0] = 'V';
  a[1] = 'M';
  a[2] = 'D';
  a[3] = 65;
  a[4] = '\0';
  strcpy (b, a);
  puts (b);
  return 0;
}

//Program 92 isdigit
int main () {
  int a = 1; float b = 'V';
  a = isspace (5);
  printf ("\n%d\n", a);
  return 0;
}

//Program : 93 sizeof signed and unsigned
#include <stdio.h>
int main (void) {
  signed i;
  printf ("%s: sizeof signed i: %d\n", __FUNCTION__, sizeof i);
  return 0;
}

//Program: 94 factorial through main function
#include <stdio.h>
int main (void) {
  static int n = 5, facto = 1, temp = 5;
  while (1) {
    facto *= n;
    n--;
    if (!n) {
      printf ("\n\tFactorial of %d is %d\n", temp, facto);
      return 0;
    }
    main ();
  }
}


//Program: 95 Increamenting the void
#include <stdio.h>

int main (void) {
  void *p;
  char a[4] = "VMD";
  p = a;
  printf (p);
  return 0;
}

//Program: 96 Printing unsigned bits
#include <stdio.h>
int main (void) {
  int j;
  signed int mask = 0;//, i = -1;
  signed int i = -1;
  for (j = 0, mask = 1 << 31; j < 32; j++, mask >>= 1)  printf ("%d", i & mask ? 1 : 0);
  printf ("\n\na\n\n");
  printf ((char *)'a');
  return 0;
}

//Program: 97 Sizeof without sizeof operator

//#define VMD_sizeof(x) ((char *)(x + 1) - (char *)(x))
#define VMD_sizeof(x) (x*)0 + 1
#include <stdio.h>
int main (void) {
  char* x;
  printf ("Sizeof (int): %d", VMD_sizeof (int));
  return 0;
}

//Program: 98 Binary Search
int pos;
int main () {
  int key;
  int a[] = {23, 1, 45, 4, 76, 34, 78, 3, 67, 3};
  void binary_search (int *a, int n, int key);
  void insert (int *a, int n);
  printf ("\n\tWhich element do U want to find:");
  scanf ("%d", &key);
  insert (a, 10);
  binary_search (a, 10, key);
  if (!pos) printf ("\n\tElement couldn't find\n");
  else printf ("\n\tElement exists at position : %d in the array\n", pos);
  return 0;
}

void binary_search (int *a, int n, int key) {
  int low, mid, high;
  low = 0, high = n;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key == a[mid]) {
      pos = mid;
      return;
    }
    else if (key > a[mid])  low = mid + 1;
    else high = mid - 1;
  }
  pos = 0;
}

void insert (int *a, int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
    temp = a[i];
    for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--) {
      a[j + 1] = a[j];
      a[j] = temp;
    }
  }
//  for (i = 0; i < n; i++) printf ("%d\t", a[i]);
}

//Program 99 sizeof and strlen of different strings
int main () {
  char a[45];
  printf ("\n\tEnter text");
  scanf ("%s", a);
  printf (a);
  printf ("sizeof a: %d\t strlen = %d", sizeof a, strlen(a));
  return 0;
}

//Program 100 pointer declaration
int main (void) {
  char* ptr, a = 5;
  printf ("a : %d", a);
  return 0;
}

//Program 101 Offset of a structure member
#define OFFSET_MEMBER(x, y) ((int)((x*)0 -> y))
int main (void) {
  struct a {
    int a;
    char b;
  }c;

  printf ("Offset of c: %u", OFFSET_MEMBER(c, b));
  return 0;
}

//Program 102 Num
#define FOR(i)  for (i = 0; i < 8; i++)
int main (void) {
  int i;
  FOR(i)
    printf ("%d", i);
  return 0;
}

//Program 103
int main (void) {
  int i = 0XA0;
  printf ("%X", i);
  return 0;
}

//Program 104
int main () {
    int n = 45258;
    char i, a[8], j;
  for (i = 0; n > 0; i++) {
    a[i] = n % 10;
    n = n / 10;
    }

  for (j = i - 1; j >= 0; j--) printf ("%d\t", a[j]);
    getchar ();
    return 0;
}

//Program 105
#define ARR_SIZE    15
#define CLEAR_ARR(j)   for (i = 0; i < j; i++) s[i] = '!';
#define PRINT_ARR(j)   for (i = 0; i < 250; i++) \
                                           printf ("%3c", s[i]);
int main (void) {
    unsigned char s[ARR_SIZE], i;
    CLEAR_ARR(ARR_SIZE)
    PRINT_ARR(ARR_SIZE)
    getchar ();
    return 0;
}

//Program 106 Biggest of two numbers. Without using ifs and comparisions
int main (void) {
    int a, b;
    printf ("Enter two numbers : a and b\n");
    scanf ("%d%d", &a, &b);

    ((a / b) && printf ("a is greater than b") || printf ("b is greater than a"));
    getchar ();
    getchar ();
    return 0;
}


//Program 107  Ternary Operator Testing
#ifndef Manu
#       define Manu    1
#endif

int main (void) {
    int x = 0, y;
    y = x ? 5: 6;
    printf ("y = %d, Manu = %d", y, Manu);
    getchar ();
    return 0;
}
*/

#if 0
//Program 108
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define    FRACTION        29
#define    AG_CONST    0.6072529350
#define    FIXED(X)    ((long int)((X) * (1 << FRACTION)))
#define    FLOAT(X)    ((X) / (double)(1 << FRACTION))
#define    DEG2RAD(X)    0.017453 * (X)

#define STEPS           23
typedef long int fixed;   /* signed 3.29 fixed-point */

static fixed Angles[STEPS];

/* creat Angles[] table */
void cordic_init()
{
  int i;
  
  for (i = 0; i < STEPS; ++i) { Angles[i] = FIXED(atan(pow(2, -i))); }
}

/*
 * CORDIC sin() cos() algorithm
 * returns sin(TargetAngle)
 * cos(TargetAngle) is stored in *cos
 */

fixed sincos(fixed TargetAngle, fixed *cos)
{
  fixed X, Y, CurrAngle, NewX;
  fixed *pAngles;
  unsigned char Step;
  Step = 0;
  CurrAngle = 0;
  Y = 0;                       /* AG_CONST * sin(0) */
  X = FIXED(AG_CONST);         /* AG_CONST * cos(0) */
  pAngles = Angles;
  
  do
  {
    NewX = X;
    
    if (TargetAngle < CurrAngle)
    {
      NewX = NewX + (Y >> Step);
      Y = Y - (X >> Step);
      CurrAngle = CurrAngle - *pAngles++;
    }
    else
    {
      NewX = NewX - (Y >> Step);
      Y = Y + (X >> Step);
      CurrAngle = CurrAngle + *pAngles++;
    }
    
    X = NewX;
    ++Step;
  }
  while (Step <= STEPS - 1);
  
  *cos = X; /* cos() return via pointer variable */
  return Y; /* sin() */
}

int main(int argc, char *argv[])
{
  fixed TargetAngle, X, Y;
  
  if (argc != 2)
  {
    printf("usage: cordic1 angle_in_deg\n");
    getch();
    exit(1);
  }
  
  cordic_init();
  double TargetAngleDeg = atof(argv[1]);
  TargetAngle = FIXED(DEG2RAD(TargetAngleDeg));
  Y = sincos(TargetAngle, &X);
  printf("CORDIC: sin(%4.7f)=%7.7f, cos(%7.7f)=%7.7f\n", TargetAngleDeg, FLOAT(Y), TargetAngleDeg, FLOAT(X));
  return (0);
}

//Program 109 long to float
int main()
{
  float f = 1234565; long n = f / 2;
  printf("Float: %1.16f\tlong: %ld", f, n);
  getchar();
  return 0;
}

//Program 110 Ascii Chart
int main(void)
{
  unsigned char i;
  
  for (i = 0; i < 255; i++) { printf("%c = %d\t", i, i); }
  
  getchar();
  return 0;
}


//Program 111 To we have to accept only in pointer
int main(void)
{
  void foo(long *);
  long x = 0;
  foo(&x);
  printf("\t\tX:%ld", x);
  getchar();
  return 0;
}

void foo(long *n)
{
  *n = 123456;
  return n;
}

//Program 112 Extern keyword
#include "test_func.c"

int i = 1;  /* Reference to i, defined below */   //Global Variables can be initialised
void next(void);   /* Function prototype */

void main()
{
  i++;
  printf("%d\n", i);   /* i equals 4 */
  next();
  getchar();
}

//int i = 3; /* Definition of i */

void next(void)
{
  i++;
  printf("%d\n", i);   /* i equals 5 */
  other();
}

#endif

//Program 113: Rotating
int main(char argc, char *argv[])
{
  void rotate(int, char *);
  
  if (argc < 2)
  {
    printf("\nInsufficient arguments\n Usage: basic1.exe <string>");
    return -1;
  }
  
  int length = strlen(argv[1]);
  
  while (length --)
  {
    rotate(length, argv[1]);
    printf("\n%s", argv[1]);
  }
  
  return 0;
}

void rotate(int length, char *str)
{
  char save = *str;
  
  while (-- length)
  {
    *str = *(str + 1)  ;
    printf("%c\t", *str);
    str++;
  }
  
  *str = save;
}
