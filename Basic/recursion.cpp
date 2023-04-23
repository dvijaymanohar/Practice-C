/*
 * Recursion Examples
 * Author:   Vijay Manohar .D
 * Date  :   Dec 5 2007
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>

#if 0     
//Program 1: power function
int main (void) {
    unsigned long power (double, int);
    double base;
    int index;
    
    printf ("\tPower function: power (base, index)"); 
    printf ("\n\tEnter the base value here: ");
    scanf ("%lf", &base);
    printf ("\n\tEnter the index value here: ");
    scanf ("%d", &index);
    
    printf ("\n\t%.2lf raised to the %d is %lu", base, index, power (base, index));
    getch ();
    return 0;
}

unsigned long power (double index, int base) {
    if (base == 0) return 1;
    else return index * power (index, (base - 1) );
}


//Program 2: Sum of n numbers
int main (void) {
    long addition (long);
    long n;
    printf ("Enter a number to find sigma n : ");
    scanf ("%ld", &n);
    printf ("\nSum of n numbers: %ld", addition (n));
    getch ();
    return 0;
}

long addition (long n) {
     if (n == 0) return 0;
     return n + addition (n - 1);
}     

//Program 3: Recursively calling main function to print n numbers
int main (void) {
    static int i;
    static char flag = 0;
    
    if (flag++ == 0) {
       printf ("Enter a number to print the numbers downto zero:");
       scanf ("%i", &i);
    }   
    
    if (i == 0) {
       getch ();
       return 0;
    }          
    
    printf ("\t%d", i--);
    main ();
}         

//Program 4: string length with recursion
int main (void) {
    int strlength (char *);
    char *str = "Creator of All";
    printf ("Str length: %d\n", strlength (str));
    system("PAUSE");
    return 0;
}

int strlength (char *str) {
    if (*str == '\0') return 0;
    return 1 + strlength (str + 1);
}                           

//Program 5: gcd of two numbers
int main (void) {
    int a[10];
    int i, noof_val;
    int gcd_res;
    
    int gcd(int, int);
    printf ("How many values (< 10) do U want find gcd : ");
    scanf ("%d", &noof_val);
    
    printf ("\nEnter %d values : \n", noof_val);
    for (i = 0; i < noof_val; i++) scanf ("%d", a + i);
    
    gcd_res = a[0];
    
    for (i = 1; i < noof_val; i++) {
         if (gcd_res > a[i]) gcd_res = gcd(gcd_res, a[i]);
         else gcd_res = gcd(a[i], gcd_res);
    }     
    
    printf ("\nGCD of given numbers is %d\n", gcd_res);
    system("PAUSE");
    return 0;
}
int gcd (int m, int n) {
    if (n == 0) return m;
    return gcd (n, m % n);
}


//Program 6: Factorial of a number
int main (void) {
    int num;
    unsigned long factorial (int);
    printf ("Enter a number to find its factorial : ");
    scanf ("%d", &num);
    printf ("\nFactorial of %d is %ld\n", num, factorial (num));
    system("PAUSE");
    return 0;
}

unsigned long factorial (int n)   {
    if (n == 1) return 1;
    return n * factorial (n - 1);
}                  

//Program 7: Calculating fibinacci numbers

int main (void) {
    int n, i;
    int fibinacci (int n);
    printf ("\nEnter a number n to print n fibinacci numbers:");    
    scanf ("%d", &n);
    for (i = 0; i < n; i++)   printf ("\t%d", fibinacci (i));
    putchar ('\n');
    system("PAUSE");
    return 0;
}

int fibinacci (int n) {
    if (n == 0 || n == 1) return n;
    return fibinacci (n - 1) + fibinacci (n - 2);
}    
        
//Program 8: ncr

int main (void) {
    int n, k;
    int choose(int n, int k);
    printf ("Enter the value of n here: ");
    scanf ("%d", &n);
    printf ("Enter the value of k here: ");
    scanf ("%d", &k);
    printf ("\nNo of combinations selecting k things at a time is : %d", choose (n, k));
    putchar ('\n');
    system("PAUSE");
    return 0;
}
        
int choose(int n, int k)
{
	if (k == 0 || n == k) return(1);
	else return(choose(n-1,k) + choose(n-1,k-1));
}    

//Program 9: Product of elements of an array
int main (void) {
    int arr[10], index;
    
    long product (int a[], int n);
    for (index = 0; index < 10; index++) arr[index] = index;
    printf ("Product of all the elements in the array : %ld", product (arr, 10));
    putchar ('\n');
    system("PAUSE");
    return 0;
}    

long product (int a[], int n)
{
     if (n == 0) return a[n];
     return a[n] * a[n - 1];
}  

//Program 10: String Length

int main (void) {
    char *str = "Vijay Manohar Dogiparthi";
    int strlength (char *);
    printf ("Length of the string: %d", strlength (str));
    putchar ('\n');
    system("PAUSE");
    return 0;
}    

int strlength (char *str) 
{
    if (*str == 0) return 0;
    return 1 + strlength (++str);
}    

#endif

//Program 11: String Copy 
int main (void)
{
    void strcopy (char *, char *);
    char *name, name_copy[15];
    name = "Vijay Manohar";
    printf ("\nEnter a string: ");
    fgets (name_copy, 15, stdin);
    
    printf (name_copy);           
    putchar ('\n');
    system("PAUSE");
    return 0;
}    

void strcopy (char *des, char *src);

#if 0
/*
 *   Program 12: Dynamic Reversal of a string, as soon as the string is entered 
 *   through the keyboard .., without storing the key. 
 */
     
int main (void) {
    void getkey (void);
    printf ("\nEnter some text here:\n");
    getkey ();
    putchar ('\n');
    system("PAUSE");
    return 0;
}       
void getkey (void) {
     char ch;
     while ( (ch = getchar ()) == '\n') return;
     getkey ();
     putchar (ch);
}   
           
//Program 13: Printing a string reversely
int main (void) 
{   
    char *name = "emertxe";    
    void str_reverse (char *);
    putchar ('\n');
    str_reverse (name);
    putchar ('\n');
    system("PAUSE");
    return 0;
}   

void str_reverse (char * str) {
     if (*str == '\0') return;
     str_reverse (str + 1);
     putchar (*str);
}     

//Program 14: Reversing a string
int main (void)
{
    char a[15], temp;
    int start, end, len;  
    printf ("Enter Ur name here: ");      
    gets(a);
    len = strlen (a);
    for (start = 0, end = strlen (a); start < end; start++, end--){
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
    }            
    a[len + 1] = '\0';
//    for (start = 0; start <= len; start++) putchar (a[start]);
    puts (a + 1);  
    putchar ('\n');
    system("PAUSE");
    return 0;
}   
#endif    

