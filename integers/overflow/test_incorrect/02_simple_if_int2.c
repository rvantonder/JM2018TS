#include <stdio.h>
#include <limits.h>
#include "integer_overflow.h"

void integer_overflow_if_else_int2(int x, int y) {
    int val, m, n;

    m = -1;
    n = 5;

    x = x*m+n;


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

int main() {
    integer_overflow_if_else_int2(-4, 10); /* OK */
    integer_overflow_if_else_int2(-5, 10); /* DANGER */
    integer_overflow_if_else_int2(-6, 10); /* OK */

    return 1;
}
