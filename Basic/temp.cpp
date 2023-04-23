#include <stdio.h>
int main (void)
{
    unsigned char ch ;
    for (ch = 0; ch < 255; ch++) printf ("%c = %d\t", ch, ch);
    getchar ();
    return 0;
}    
                   
