#include <stdio.h>
#include <limits.h>
#include "integer_overflow.h"

void integer_overflow_if_else_int1(int x, int y) {
    int val;

    if(x <= 10 && x >= y) {
        return;
    }

    if(x < y) {
        val = INT_MAX / 3 - 1;
    } else {
        val = INT_MAX / 2 - 1;
    }

    if(x > 10) {
        val = val * 2;
    } else {
        val = val * 3; /* DANGER if x <= 10 & x >= y */
    }

    printf("%i\n", val);
}

