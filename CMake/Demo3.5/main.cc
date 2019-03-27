#include <stdio.h>
#include <stdlib.h>
#include "inc/MathFunctions.h"
#include "inc/fun.h"

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    double result1 = function(base,exponent);
    printf("%g ^ %d is %g\n", base, exponent, result1);
    return 0;
}
