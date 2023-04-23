
#ifdef MACNAME
  /*  tokens added if MACNAME is defined */
  #if TEST <=10
    /* tokens added if MACNAME is defined and TEST <= 10 */
  #else
    /* tokens added if MACNAME is defined and TEST >  10 */
  #endif
#else
  /*  tokens added if MACNAME is not defined */
#endif



--------------------------------------------------------------------- -
#if defined
*

#if defined(TEST1) || defined(TEST2)

Note:
If a macro is not defined, a value of 0(zero) is assigned to it. In the following example, TEST must be a macro identifier:

#if TEST >= 1
  printf("i = %d\n", i);
  printf("array[i] = %d\n", array[i]);
#elif TEST < 0
  printf("array subscript out of bounds \n");
#endif
  = ---------------------------------------------------------------------- -
#ifdef
    
    The following example defines MAX_LEN to be 75 if EXTENDED is defined for the preprocessor. Otherwise, MAX_LEN is defined to be 50.
    
#ifdef EXTENDED
  #define MAX_LEN 75
#else
  #define MAX_LEN 50
#endif
    
      -------------------------------------------------------------- -
      
      
#if defined(TARGET1)
  #define SIZEOF_INT 16
  #ifdef PHASE2
    #define MAX_PHASE 2
  #else
    #define MAX_PHASE 8
  #endif
#elif defined(TARGET2)
  #define SIZEOF_INT 32
  #define MAX_PHASE 16
#else
  #define SIZEOF_INT 32
  #define MAX_PHASE 32
#endif
      
    The following program contains preprocessor conditional compilation directives :
    
      /**
       ** This example contains preprocessor
       ** conditional compilation directives.
       **/
      
#include <stdio.h>
      
      int main(void)
  {
    static int array[ ] = { 1, 2, 3, 4, 5 };
    int i;
    
    for (i = 0; i <= 4; i++)
    {
      array[i] *= 2;
#if TEST >= 1
      printf("i = %d\n", i);
      printf("array[i] = %d\n",
             array[i]);
#endif
    }
    
    return (0);
  }

----------------------------------------------------------------------- -
#line

Example of the #line Directive

You can use #line control directives to make the compiler provide more meaningful error messages. The following program uses #line control directives to give each function an easily recognizable line number:

/**
 ** This example illustrates #line directives.
 **/

#include <stdio.h>
#define LINE200 200

int main(void)
{
  func_1();
  func_2();
}

#line 100
func_1()
{
  printf("Func_1 - the current line number is %d\n", _ _LINE_ _);
}

#line LINE200
func_2()
{
  printf("Func_2 - the current line number is %d\n", _ _LINE_ _);
}

This program produces the following output:

Func_1 - the current line number is 102
Func_2 - the current line number is 202
--------------------------------------------------------------------------- -
#null

#ifdef MINVAL
  #
#else
  #define MINVAL 1
#endif
---------------------------------------------------------------------- -
Pragma Directives(#pragma)

A pragma is an implementation - defined instruction to the compiler. It has the general form:

.--------------------.
V                    |
    >> -#--pragma-- +------ +----character_sequence - +--new - line-------> <
    '-STDC-'
    
    
    
    where character_sequence is a series of characters giving a specific compiler instruction and arguments, if any. The token STDC indicates a standard pragma; consequently, no macro substitution takes place on the directive. The new - line character must terminate a pragma directive.

The character_sequence on a pragma is subject to macro substitutions. For example,
    
#define
    XX_ISO_DATA
    isolated_call(LG_ISO_DATA)
    // ...
#pragma XX_ISO_DATA
    
    More than one pragma construct can be specified on a single #pragma directive. The compiler ignores unrecognized pragmas.
    ------------------------------------------------------------------------------- -
    
    For example, the directive
    
#define BUFFER_SIZE 255
    
#if BUFFER_SIZE < 256
  #error "BUFFER_SIZE is too small."
#endif
    
    generates the error message:
    
    BUFFER_SIZE is too small.
    ----------------------------------------------------------------------------------
    
# Operator
    
    The #(single number sign) operator converts a parameter of a function - like macro into a character string literal. For example, if macro ABC is defined using the following directive:
    
#define ABC(x)   #x
    
    all subsequent invocations of the macro ABC would be expanded into a character string literal containing the argument passed to ABC. For example:
    Invocation  Result of Macro Expansion
    ABC(1)  "1"
      ABC(Hello there)  "Hello there"
      
      The # operator should not be confused with the null directive.
      
    Use the # operator in a function - like macro definition according to the following rules:
    
      *A parameter following # operator in a function - like macro is converted into a character string literal containing the argument passed to the macro.
      * White - space characters that appear before or after the argument passed to the macro are deleted.
      * Multiple white - space characters imbedded within the argument passed to the macro are replaced by a single space character.
      * If the argument passed to the macro contains a string literal and if a \(backslash) character appears within the literal, a second \ character is inserted before the original \ when the macro is expanded.
        * If the argument passed to the macro contains a " (double quotation mark) character, a \ character is inserted before the " when the macro is expanded.
        * The conversion of an argument into a string literal occurs before macro expansion on that argument.
        * If more than one ## operator or # operator appears in the replacement list of a macro definition, the order of evaluation of the operators is not defined.
        * If the result of the macro expansion is not a valid character string literal, the behavior is undefined.
        
        Example of the # Operator
        
    The following examples demonstrate the use of the # operator:
    
#define STR(x)        #x
#define XSTR(x)       STR(x)
#define ONE           1
    
    
        Invocation  Result of Macro Expansion
        STR(\n "\n" '\n')   "\n \"\\n\" '\\n'"
        STR(ONE)  "ONE"
        XSTR(ONE)   "1"
        XSTR("hello")   "\"hello\""
        ------------------------------------------------------------------------------------ -
        
        Examples of the ## Operator
        
    The following examples demonstrate the use of the ## operator:
    
#define ArgArg(x, y)          x##y
#define ArgText(x)            x##TEXT
#define TextArg(x)            TEXT##x
#define TextText              TEXT##text
#define Jitter                1
#define bug                   2
#define Jitterbug             3
    
    
        Invocation  Result of Macro Expansion
        ArgArg(lady, bug)   "ladybug"
        ArgText(con)  "conTEXT"
        TextArg(book)   "TEXTbook"
        TextText  "TEXTtext"
        ArgArg(Jitter, bug)   3
        
        ------------------------------------------------------------------------
        
#include <stdio.h>
        
    #define   message_for(a, b)  \
    printf(#a      and     #b ": We love you!\n")
        
        int main(void)
  {
    message_for(Carole, Debra);
    return 0;
  }

-----------------------------------------------------------------------------

