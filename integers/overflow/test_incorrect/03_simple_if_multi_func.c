#include "integer_overflow.h"
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

static int local_choose_int(int int1, int int2, bool condition) {
    if(condition) {
        return int1;
    } else {
        return int2;
    }
}

static int conditional_mult(int val, int mult1, int mult2, bool condition) {
    if(condition) {
        return val * mult1;
    }
    return val * mult2;
}

void integer_overflow_if_else_multi(bool a, bool b) {
    int val;


    val = local_choose_int(INT_MAX / 3 - 1, INT_MAX / 2 - 1, a);

    val = conditional_mult(val, 2, 3, b); /* DANGER, if !a & !b */

    printf("%i\n", val);
}

int main() {
    integer_overflow_if_else_multi(true, true); /* OK */
    integer_overflow_if_else_multi(false, false); /* DANGER */
    integer_overflow_if_else_multi(false, true); /* OK */
    return 1;
}
