#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_if_else_int2(int x, int y) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val, m, n;

    m = -1;
    n = 5;

    x = x*m+n;


    if(x < y) {
        ptr = arr;
    }

    if(x > 10) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER: x <= 10 && x >= y */
    }

    printf("x=%i: %i", x, val);
}

int main() {
    uninit_ptr_if_else_int2(-4, 10); /* OK */
    uninit_ptr_if_else_int2(-5, 10); /* DANGER */
    uninit_ptr_if_else_int2(-6, 10); /* OK */

    return 1;
}
