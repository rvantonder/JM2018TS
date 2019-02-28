#include <stdio.h>
#include <stdbool.h>
#include "divide_by_zero.h"

void divide_zero_if_else(bool a, bool b) {
    int divisor;
    int val;


    if(a) {
        divisor = 1;
    } else {
        divisor = 2;
    }

    if(b) {
        val = 37 / (divisor + 2);
    } else {
        val = 11 / (divisor - 2); /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

