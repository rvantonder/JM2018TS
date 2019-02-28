#include "integer_overflow.h"
#include "common.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

void integer_overflow_cross_file(bool a, bool b) {
    int val;

    if(!a & !b) {
        return;
    }

    val = choose_int(2, INT_MAX / 3 - 1, INT_MAX / 2 - 1);

    if(b) {
        val = val * 2;
    } else {
        val = val * 3; /* DANGER if !a */
    }

    printf("%i\n", val);
}

