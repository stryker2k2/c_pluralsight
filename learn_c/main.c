#include <stdio.h>

#ifndef __cplusplus
typedef char bool;
#define true 1
#define false 0
#endif

bool c2f = false;
double c = 0;
double f = 86;


void apples_set(int value);
int apples_get();

void oranges_set(int value);
int oranges_get();

int main()
{
    if (c2f)        //C to F
    {
        f = c * 9/5 + 32;
        printf("%.2f C = %.2f F\n", c, f);
    }

    else            //F to C
    {
        c = (f - 32) * 5/9;
        printf("%.2f F = %.2f C\n", f, c);
    }
    
    apples_set(5);
    oranges_set(10);

    printf("apples = %d\noranges = %d\n", apples_get(), oranges_get());


    return 0;
}



// Compile with: 
// c:\> gcc -o program.exe *.c
// *OR*
// c:\> gcc -o program.exe main.c first.c second.c third.c fourth.c