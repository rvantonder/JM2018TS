#include <stdio.h>
#include "divide_by_zero.h"

void divide_zero_if_else_int1(int x, int y) {
    int divisor;
    int val;

    if(x <= 10 && x >= y) {
        return;
    }

    if(x < y) {
        divisor = 1;
    } else {
        divisor = 2;
    }

    if(x > 10) {
        val = 37 / (divisor + 2);
    } else {
        val = 11 / (divisor - 2); /* DANGER, if x <= 10 & x >= y */
    }

    printf("x=%i: %i", x, val);
}

