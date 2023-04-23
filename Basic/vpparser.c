
/***
 *  - Include all the imp tokens
 *  - Prepare a C header file
 *  - Preare a C header file with C structure
 */


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//#define ENABLE_LOG

#ifdef ENABLE_LOG
  #define MSG_LOG  printf
#else
  #define MSG_LOG(...)
#endif

#ifndef true
  #define true 1
#endif

#ifndef false
  #define false !(true)
#endif

enum PARSER_VECTOR_NAMES
{
  VECTOR_A,
  VECTOR_B,
  VECTOR_C,
  VECTOR_RESULT,
  VECTOR_NONE,
};

enum PARSER_SUBSTRINGS
{
  A_LENGTH,
  B_LENGTH,
  SHIFT_VALUE,
  COMMAND,
  SUBSTRING_NONE,
};

enum ERR_CODES
{
  EC_SUCCESS,
  EC_INVALID_ARGS,
  EC_NONE,
};
static char *read_line(FILE *fp)
{
  int line_len_max = 128;
  char *line_buffer = NULL;
  
  if (fp == NULL)
  {
    printf("Error: fp pointer is NULL.\n");
    exit(EXIT_FAILURE);
  }
  
  line_len_max = 128;
  line_buffer = (char *)malloc(sizeof(char) * line_len_max);
  
  if (line_buffer == NULL)
  {
    printf("Error allocating memory for line buffer.");
    exit(1);
  }
  
  char ch = getc(fp);
  int count = 0;
  
  while ((ch != '\n') && (ch != EOF))
  {
    if (count == line_len_max)
    {
      line_len_max += 128;
      line_buffer = realloc(line_buffer, line_len_max);
      
      if (line_buffer == NULL)
      {
        printf("Error reallocating space for line buffer.");
        exit(1);
      }
    }
    
    line_buffer[count] = ch;
    count++;
    ch = getc(fp);
  }
  
  line_buffer[count] = '\0';
  realloc(line_buffer, count + 1);
  return line_buffer;
}

static bool parse_for_vector(const char *const str, int *const vec)
{
  bool res = true;
  
  if (!strcmp(str, "#A operand"))
  {
    *vec = VECTOR_A;
  }
  else if (!strcmp(str, "#B operand"))
  {
    *vec = VECTOR_B;
  }
  else if (!strcmp(str, "#C operand"))
  {
    *vec = VECTOR_C;
  }
  else if (!strcmp(str, "#Check result"))
  {
    *vec = VECTOR_RESULT;
  }
  else
  {
    res = false;
  }
  
  return res;
}

static int parse_for_field(const char *const str, char **subfield)
{
  char *temp1 = NULL, **temp2;
  *subfield = NULL;
  
  if (NULL == str)
  {
    return EC_INVALID_ARGS;
  }
  
  temp1 = (char *) str;
  temp2 = &temp1;
  
  while ('\n' != *temp1)
  {
    if (' ' == *temp1)
    {
      *temp1 = '\0';
      break;
    }
    
    temp1++;
  }
  
  printf("Temp2: %s\n", *temp2);
  *subfield = *temp2;
  return EC_SUCCESS;
}

static int extract_num(const char *str, long *const val)
{
  char *p = (char *) str;
  long num = 0;
  
  if (NULL == str || NULL == val)
  {
    return EC_INVALID_ARGS;
  }
  
  while (*p)   // While there are more characters to process...
  {
    if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
    {
      num = num * 10 + strtol(p, &p, 10); // Read number;
    }
    else
    {
      // Otherwise, move on to the next character.
      p++;
    }
  }
  
  *val = num;
  return EC_SUCCESS;
}

static int  parse_for_substring(const char *const line, char **substr, int *const vec)
{
  *vec = SUBSTRING_NONE;
  *substr = NULL;
  
  if (NULL == line || NULL == vec)
  {
    return EC_INVALID_ARGS;
  }
  
  if ((*substr = strstr(line, "PKCP_A_LENGTH")) != NULL)
  {
    *vec = A_LENGTH;
  }
  else if ((*substr = strstr(line, "PKCP_B_LENGTH")) != NULL)
  {
    *vec = B_LENGTH;
  }
  else if ((*substr = strstr(line, "PKCP_SHIFT_VALUE")) != NULL)
  {
    *vec = SHIFT_VALUE;
  }
  else if ((*substr = strstr(line, "PKCP_COMMAND")) != NULL)
  {
    *vec = COMMAND;
  }
  else
  {
    *vec = SUBSTRING_NONE;
  }
  
  return EC_SUCCESS;
}

static long read_data(FILE *fp)
{
  char *line = NULL;
  long num = 0;
  
  if (NULL == fp)
  {
    return 0;
  }
  
  while (!feof(fp))
  {
    line = read_line(fp);
    
    if (strstr(line, "Data") != NULL)
    {
      char *p = line;
      
      while (*p)   // While there are more characters to process...
      {
        if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
        {
          num = num * 10 + strtol(p, &p, 10); // Read number;
        }
        else
        {
          // Otherwise, move on to the next character.
          p++;
        }
      }
      
      free(line);
      break;
    }
  }
  
  free(line);
  return num;
}

#if 0
static long read_data2(FILE *fp)
{
  char *line = NULL;
  long byte_amount = 0;
  unsigned long count = 0;
  
  if (NULL == fp)
  {
    return 0;
  }
  
  long curr_fp0 = ftell(fp), curr_fp1 = 0;
  
  do
  {
    line = read_line(fp);
    
    if (is_token(line))
    {
      printf("%s\n", line);
      curr_fp1 = ftell(fp);
      byte_amount = curr_fp1 - curr_fp0;
      fseek(fp, -curr_fp0, SEEK_CUR);
      char ch;
      putchar('\n');
      
      while ((ch = fgetc(fp)) != EOF || count < byte_amount)
      {
        count++;
        printf("%c", ch);
      }
      
      fseek(fp, -curr_fp0, SEEK_CUR);
      break;
    }
    
    free(line);
  }
  while (!feof(fp));
  
  return byte_amount;
}

static void display_line(FILE *fp)
{
  if (NULL == fp)
  {
    printf("File pointer is NULL\n");
    exit(EXIT_FAILURE);
  }
  
  while (!feof(fp))
  {
    char *line = read_line(fp);
    puts(line);
    free(line);
  }
  
  fclose(fp);
}
#endif

static enum PARSER_VECTOR_NAMES get_vector_name(const char *const str)
{
  if (!strcmp(str, "#A operand"))
  {
    return VECTOR_A;
  }
  else if (!strcmp(str, "#B operand"))
  {
    return VECTOR_B;
  }
  else if (!strcmp(str, "#Check result"))
  {
    return VECTOR_RESULT;
  }
  
  return VECTOR_NONE;
}

static void print_vector_name(const char *const str)
{
  enum PARSER_VECTOR_NAMES vector = get_vector_name(str);
  
  switch (vector)
  {
    case VECTOR_A:
      printf("char a[] = { \n");
      break;
      
    case VECTOR_B:
      printf("char b[] = { \n");
      break;
      
    case VECTOR_RESULT:
      printf("char resul[] = { \n");
      break;
      
    default:
      break;
  }
}

static void prepare_vector(FILE *input_fp, const unsigned int bytes_to_read)
{
  char ch;
  long count = 0, chars_to_read = (((bytes_to_read / 4)  * 8) + (bytes_to_read / 4));
  long curr_fp0 = ftell(input_fp), curr_fp1 = 0;
  char vector_data[chars_to_read];
  short i = 0, j = 0;
  
  while ((ch = fgetc(input_fp)) != EOF && count < chars_to_read)
  {
    count++;
    vector_data[i] = ch;
    //printf("%c", vector_data[i]);
    i++;
  }
  
  curr_fp1 = ftell(input_fp);
  /** Replace the FP to where it was to continue with the other vectors */
  fseek(input_fp, -(curr_fp1 - curr_fp0), SEEK_CUR);
#if 0
  
  for (i = 0; i < chars_to_read; i++)
  {
    printf("%c", vector_data[i]);
  }
  
#endif
#if 1
  i = 0;
  j = 8;
  
  for (i = 0; i < chars_to_read; i = i + 9)
  {
    for (j = 7; j >= 0; j = j - 2)
    {
      printf("    0x%c%c,", vector_data[(j + i) - 1], vector_data[j + i]);
    }
    
    putchar('\n');
  }
  
#endif
}

int main(int argc, char const *argv[])
{
  FILE *input_fp = NULL, *output_fp = NULL;
  char *input_file_extension = NULL;
  char *output_filename = NULL;
  
  /** Check the usage of the invocation of this application */
  if (2 != argc)
  {
    printf("Usage: ./vp2c input.vp\n");
    exit(EXIT_FAILURE);
  }
  
  /** Check for the extension of the input vector file */
  input_file_extension = strrchr(argv[1], '.');
  
  if ((NULL == input_file_extension) || (strcmp(input_file_extension, ".vp")))
  {
    printf("Only .vp files are allowed\n");
    exit(EXIT_FAILURE);
  }
  
  /** Check whethre the input vector file is available for reading */
  input_fp = fopen(argv[1], "r");
  
  if (NULL == input_fp)
  {
    printf("%s cannot be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  
  /** Steps to create the output file
   *  Create the output filename on the name of the input file
   *
   */
  output_filename = malloc(strlen(argv[1]) + 1);
  
  /** If memory allocation failed */
  if (NULL == output_filename)
  {
    printf("%s: Could not allocate memory\n", __FUNCTION__);
    fclose(input_fp);
    exit(EXIT_FAILURE);
  }
  
  /** Copy the name of input vp file */
  strcpy(output_filename, argv[1]);
  input_file_extension = strrchr(output_filename, '.');
  
  /** Knock out the extension from the filename */
  if (NULL != input_file_extension)
  {
    *input_file_extension = '\0';
  }
  
  char *output_file_name = (char *) malloc(strlen(output_filename) + 3);
  strcpy(output_file_name, output_filename);
  free(output_filename);
  strcat(output_file_name, ".h");
  /** Open the output file for writing */
  output_fp = fopen(output_file_name, "w");
  
  if (NULL == output_fp)
  {
    printf("%s cannot be opened for writing\n", output_file_name);
    free(output_file_name);
    /** Close the input vp file, which was opened for parsing*/
    fclose(input_fp);
    exit(EXIT_FAILURE);
  }
  
  MSG_LOG("%s opened to make a C header\n", output_file_name);
  free(output_file_name);
  
  while (!feof(input_fp))
  {
    /** Start reading data from the vp file. */
    char *line = read_line(input_fp);
    
    if (NULL != line)
    {
      int vec = (int) VECTOR_NONE;
      char *substr = NULL;
      
      if (parse_for_vector(line, &vec))
      {
        printf("/* %s */\n", line);
        int bytes_to_read = read_data(input_fp);
        //printf("No of bytes to read: %u\n", bytes_to_read);
        print_vector_name(line);
        prepare_vector(input_fp, bytes_to_read);
        puts("};\n");
      }
      else if (EC_SUCCESS == parse_for_substring(line, &substr, &vec))
      {
        if (SUBSTRING_NONE != vec)
        {
          long value = 0;
          //printf("Substring: %s\n", substr);
          char *subfield = NULL;
          
          if (!parse_for_field(substr, &subfield))
          {
            printf("Subfield: %s\n", subfield);
          }
          
          //extract_num(substr, &value);
          //printf("Value in the string: %ld\n", value);
#if 0
          char *temp1 = NULL, *temp2 = NULL;
          temp1 = temp2 = *substr;
          
          while ('\n' != *temp2)
          {
            if (' ' == *temp2)
            {
              *temp2 = '\0';
              break;
            }
            
            temp2++;
          }
          
          switch (vec)
          {
            case A_LENGTH:
              break;
              
            case B_LENGTH:
              break;
              
            case SHIFT_VALUE:
              break;
              
            case COMMAND:
              break;
              
            default:
              break;
          };
          
#endif
        }
        
        free(line);
      }
    }
  }
  
  fclose(input_fp);
  printf("%s executed successfully\n", argv[0]);
  return 0;
}


