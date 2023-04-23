/*
//Program: 1 File Copy Program
#include <stdio.h>
int main (int argc, char *argv[], char *envp[]) {
    FILE *fp1, *fp2;
    if (argc != 3) {
       printf ("\tInvalid no of arguments\nUsage: %s <file1> <file2>", *argv[0]);
       getchar ();
       return -1;
    }

    if ( (fp1 = fopen (argv[1], "r")) == NULL) {
       printf ("Unable to open the file : %s \n", argv[1]);
       getchar ();
       return -1;
    }

    if ( (fp2 = fopen (argv[2], "w")) == NULL) {
       printf ("Unable to open the file : %s \n", argv[2]);
       getchar ();
       return -1;
    }

    while (!feof (fp1)) putc (getc(fp1), fp2);
    getchar ();
    return 0;
}

//cat/type, cp, Program that prints its own file,

*/
//Program 2: See the code

#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{
  FILE *fp;
  
  if ((fp = fopen(argv[1], "w")) == NULL)
  {
    perror("");