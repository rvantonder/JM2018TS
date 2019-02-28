#include <stdio.h>
#include <stdbool.h>
#include "divide_by_zero.h"

static void assign_int(int* dest, int int1, int int2, bool condition) {
    if(condition) {
        *dest = int1;
    } else {
        *dest = int2;
    }
}

void divide_zero_function_pointer(bool a, bool b, void (*f)(int*, int, int, bool)) {
    int divisor;
    int val;


    (*f)(&divisor, 2, 0, a);

    if(b) {
        val = 25 / 4;
    } else {
        val = 91 / divisor; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    divide_zero_function_pointer(true, true, &assign_int); /* OK */
    divide_zero_function_pointer(false, false, &assign_int); /* DANGER */
    divide_zero_function_pointer(false, true, &assign_int); /* OK */

    return 1;
}
