#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_if_else_int2(int x, int y) {
    int possibly_uninit;
    int val, m, n;

    m = -1;
    n = 5;

    x = x*m+n;


    if(x < y) {
        possibly_uninit = 1;
    }

    if(x > 10) {
        val = 37 * 2;
    } else {
        val = 11 * possibly_uninit; /* DANGER, if x <= 10 & x >= y */
    }

    printf("x=%i: %i", x, val);
}

int main() {
    uninit_val_if_else_int2(-4, 11);
    uninit_val_if_else_int2(-5, 11);
    uninit_val_if_else_int2(-6, 11);

    return 1;
}
