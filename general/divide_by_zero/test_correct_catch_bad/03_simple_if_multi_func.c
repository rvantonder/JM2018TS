#include "divide_by_zero.h"
#include <stdbool.h>
#include <stdio.h>

static int choose_divisor(int div1, int div2, bool condition) {
    if(condition) {
        return div1;
    } else {
        return div2;
    }
}

static int conditional_divide(int val, int div1, int div2, bool condition) {
    if(condition) {
        return val / div1;
    }
    return val / div2;
}

void divide_zero_if_else_multi(bool a, bool b) {
    int divisor;
    int val;

    if(!a & !b) {
        return;
    }

    divisor = choose_divisor(5, 0, a);

    val = conditional_divide(25, divisor+2, divisor, b); /* DANGER, if !a & !b */

    printf("%i\n", val);
}

int main() {
    divide_zero_if_else_multi(true, true);
    divide_zero_if_else_multi(true, false);
    divide_zero_if_else_multi(false, true);
    return 1;
}
