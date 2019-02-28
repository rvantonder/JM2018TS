#include "divide_by_zero.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>

void divide_zero_cross_file(bool a, bool b) {
    int divisor;
    int val;

    if(!a & !b) {
        return;
    }

    divisor = choose_int(2, 0, a);

    if(b) {
        val = 10 / (divisor + 2);
    } else {
        val = 10 / divisor; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    divide_zero_cross_file(true, true);
    divide_zero_cross_file(true, false);
    divide_zero_cross_file(false, true);
    return 1;
}
