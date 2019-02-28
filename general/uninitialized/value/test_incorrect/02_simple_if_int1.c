#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_if_else_int1(int x, int y) {
    int possibly_uninit;
    int val;


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
    uninit_val_if_else_int1(9, 10); /* OK */
    uninit_val_if_else_int1(10, 10); /* DANGER */
    uninit_val_if_else_int1(11, 10); /* OK */

    return 1;
}
