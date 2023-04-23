
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if 0
/** Bit patterns */

#define NO_OF_BITS  10

void print_array(int *a, int size)
{
  int i;
  
  if ((NULL == a) || 0 == size) { return; }
  
  putchar('\n');
  
  for (i = 0; i < size; i++)
  {
    printf("%d", a[i]);
  }
}

int generate_bit_patterns(int *a, int n)
{
  if (n < 1) { print_array(a, NO_OF_BITS); }
  
  a[n - 1] = 0;
  generate_bit_patterns(a, n);
  a[n - 1] = 1;
  generate_bit_patterns(a, n);
}

int main(int argc, char *argv [])
{
  int a[NO_OF_BITS];
  memset(a, 0, sizeof(a));
  print_array(a, NO_OF_BITS);
  generate_bit_patterns(a, NO_OF_BITS);
  return 0;
}


#include <stdio.h>
#include <time.h>

typedef unsigned int uint32;

void delay(int milliseconds)
{
  long pause;
  clock_t now, then;
  pause = milliseconds * (CLOCKS_PER_SEC / 1000);
  now = then = clock();
  
  while ((now - then) < pause)
  {
    now = clock();
  }
}

uint32 simian_rand_lfsr(const uint32 cpu_id)
{
  uint32 rand_num = 0;
  static uint32 lfsr_apps0 = 0x01;
  static uint32 lfsr_apps1 = 0x02;
  static uint32 lfsr_apps2 = 0x04;
  static uint32 lfsr_apps3 = 0x08;
  static uint32 lfsr_apps4 = 0x10;
  static uint32 lfsr_apps5 = 0x20;
  static uint32 lfsr_apps6 = 0x40;
  static uint32 lfsr_apps7 = 0x80;
  static uint32 lfsr_apps8 = 0x0100;
  
  switch (cpu_id)
  {
    case 0:
      {
        lfsr_apps0 = (lfsr_apps0 >> 1) ^ (-(lfsr_apps0 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps0;
      }
      break;
      
    case 1:
      {
        lfsr_apps1 = (lfsr_apps1 >> 1) ^ (-(lfsr_apps1 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps1;
      }
      break;
      
    case 2:
      {
        lfsr_apps2 = (lfsr_apps2 >> 1) ^ (-(lfsr_apps2 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps2;
      }
      break;
      
    case 3:
      {
        lfsr_apps3 = (lfsr_apps3 >> 1) ^ (-(lfsr_apps3 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps3;
      }
      break;
      
    case 4:
      {
        lfsr_apps4 = (lfsr_apps4 >> 1) ^ (-(lfsr_apps4 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps4;
      }
      break;
      
    case 5:
      {
        lfsr_apps5 = (lfsr_apps5 >> 1) ^ (-(lfsr_apps5 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps5;
      }
      break;
      
    case 6:
      {
        lfsr_apps6 = (lfsr_apps6 >> 1) ^ (-(lfsr_apps6 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps6;
      }
      break;
      
    case 7:
      {
        lfsr_apps7 = (lfsr_apps7 >> 1) ^ (-(lfsr_apps7 & 1u) & 0xD0000001u);
        rand_num = lfsr_apps7;
      }
      break;
      
    default:
      rand_num = 0xdeadbeef;
      break;
  }
  
  return rand_num;
}

int main(int argc, int *argv[])
{
  while (1)
  {
    printf("\nRandom nummber generated: %u\n", simian_rand_lfsr() % 100);
    delay(1000);
  }
  
  return 0;
}

// Function call with an address

#include "stdio.h"
#include <stdlib.h>

void foo()
{
  printf("Function foo called\n");
}

int main(int argc, char *argv[])
{
  void (*func)(void) = &foo;
  func();
  printf("Back to main func\n");
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

void go(unsigned int addr)
{
  printf("Function foo called\n");
  (&addr)[-1] = addr;
}

int sub()
{
  static int i;
  
  if (i++ < 10) { printf("Hello %d\n", i); }
  else { exit(0); }
  
  go((unsigned int)sub);
}

int main()
{
  sub();
}



// A C/C++ program for splitting a string using strtok()
#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "Geeks for Geeks";
  // Returns first token
  char *token = strtok(str, " ");
  
  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
  
  return 0;
}



// Print 1-100 without using loops
#include <stdio.h>

int main(int argc, char *argv[])
{
  static int i = 1;
  
  if (i <= 100)
  {
    printf("%d\t", i++);
    main(0, NULL);
  }
  
  return 0;
}

// Binary search

static int binary_search(int arr[], unsigned int l, unsigned int r, int x)
{
  unsigned int mid = l + (r - l) / 2;
  
  if (r >= 1)
  {
    if (x == arr[mid]) { return mid; }
    
    if (arr[mid] > x) { return binary_search(arr, l, mid - 1, x); }
    
    return binary_search(arr, mid + 1, r, x);
  }
  
  return -1;
}

int main(void)
{
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;
  int result = binary_search(arr, 0, n - 1, x);
  (result == -1) ? printf("Element is not present in array")
  : printf("Element is present at index %d",
           result);
  return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a[] = {10, 20, 30, 40};
  int b[] = {1, 7, 11, 17, 28};
  int delta = 0, temp = 0;
  int close_a_element = 0, close_b_element = 0;
  int x  = 0; // To hold the given number
  int i, j; // Indeces to traverse throuh the arrays a and b
  unsigned int len_a = sizeof(a) / sizeof(a[0]);
  unsigned int len_b = sizeof(b) / sizeof(b[0]);
  x = 33;//atoi(argv[1]);
  delta = (x - (a[0] + b[0]));
  
  for (i = 0; i < len_a; i++)
  {
    for (j = 0; j < len_b; j++)
    {
      temp = (x - (a[i] + b[j]));
      
      if (temp < 0) { temp = -temp; }
      
      if (delta > temp)
      {
        printf("Delta: %d\n", delta);
        delta = temp;
        close_a_element = a[i];
        close_b_element = b[j];
      }
    }
  }
  
  printf("Closest A element: %d\nClosest B element: %d\n", close_a_element, close_b_element);
  return 0;
}


#if 0
#include <stdio.h>

typedef struct
{
  int a;
  int b;
} sample_struct;

int main()
{
  sample_struct a;
  sample_struct *ptr = &a;
  return printf("sizeof sample_struct: %u\n", sizeof(*ptr));
}
#endif

#include <stdio.h>
#define MY_SIZEOF(x) ((x *)0 + 1)

int main(int argc, char *argv[])
{
  int *ptr = (int *)0;
  printf("size of int: %u\n", ++ptr);
  return 0;
}
#endif

//Program to extract the individual ints in a 64 bit number
#include <stdio.h>
#include <stdint.h>

union
{
  uint64_t num;
  
  struct
  {
    uint32_t num1;
    uint32_t num2;
  };
} converter;

int main(int argc, const char **argv)
{
  uint64_t value = 0x1524362589962545;
  converter.num = value;
  printf("Lower 32 bit value: 0x%p\n", converter.num1);
  printf("Higher 32 bit value: 0x%p\n", converter.num2);
  value = (((uint64_t)(1) << 32) - 1);
  printf("Value: 0x%llx\n", value);
  value = 0x0fffffffffffffff;
  printf("Value: 0x%llx\n", value);
  return 0;
}

