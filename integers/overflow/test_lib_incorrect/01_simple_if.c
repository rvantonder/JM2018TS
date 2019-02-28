#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "integer_overflow.h"

void integer_overflow_if_else(bool a, bool b) {
    int val;


    if(a) {
        val = INT_MAX / 3 - 1;
    } else {
        val = INT_MAX / 2 - 1;
    }

    if(b) {
        val = val * 2;
    } else {
        val = val * 3; /* DANGER if !a */
    }

    printf("%i\n", val);
}

