#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_if_else_int1(int x, int y) {
    int possibly_uninit;
    int val;

    if(x <= 10 && x >= y) {
        return;
    }

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

