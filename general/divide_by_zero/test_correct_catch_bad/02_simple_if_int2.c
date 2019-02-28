#include <stdio.h>
#include "divide_by_zero.h"

void divide_zero_if_else_int2(int x, int y) {
    int divisor;
    int val, m, n;

    m = -1;
    n = 5;

    x = x*m+n;

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

int main() {
    divide_zero_if_else_int2(-4, 11);
    divide_zero_if_else_int2(-5, 11);
    divide_zero_if_else_int2(-6, 11);

    return 1;
}
