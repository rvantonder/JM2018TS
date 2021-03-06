#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "integer_overflow.h"

static void assign_int(int* dest, int int1, int int2, bool condition) {
    if(condition) {
        *dest = int1;
    } else {
        *dest = int2;
    }
}

void integer_overflow_function_pointer(bool a, bool b, void (*f)(int*, int, int, bool)) {
    int val;

    if(!f || (!a & !b)) {
        return;
    }

    (*f)(&val, INT_MAX / 3 - 1, INT_MAX / 2 - 1, a);

    if(b) {
        printf("%i\n", val * 2 - 15);
    } else {
        printf("%i\n", val * 3 - 37); /* DANGER, if !a & !b */
    }
}

