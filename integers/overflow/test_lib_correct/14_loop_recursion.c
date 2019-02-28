#include <stdio.h>
#include <limits.h>
#include "integer_overflow.h"

void integer_overflow_rec(int x, int i, int val) {
    if(i <= 1) {
        printf("%i\n", val);
        return;
    }

    if(x > 10) {
        printf("%i\n", val);
        return;
    }

    if(i < x) {
        val += 10;
    } else {
        val += 1;
    }

    if(i == 10) {
        printf("%i\n", val);
        val = INT_MAX - 10;
    }
    integer_overflow_rec(x, i-1, val);
}

