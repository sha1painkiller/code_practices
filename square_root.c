/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

double square_root(int seed, int precision) {
    double base = 0;
    int i = 0, j;
    double inc = 1;
    
    while (i * i <= seed) 
        i++;
    base = (double) (i - 1);
    
    for (i = 0; i < precision; i++) {
        inc = inc / 10;
        j = 0;
        while ((base + inc * j) * (base + inc * j) <= seed) 
            j++;
        base = base + inc * (j - 1);
    }
    
    return base;
}

void main (void) {
    int seed = 6735439;
    int precision = 5; //the prevision of decimals
    double result;
    
    result = square_root(seed, precision);
    
    printf ("square root of %d is %5.5f\n", seed, result);

}
