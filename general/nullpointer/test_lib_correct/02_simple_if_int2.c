#include <stdio.h>
#include "nullpointer.h"

void nullpointer_if_else_int2(int x, int y) {
    int arr[3] = {1, 2, 3};
    int* ptr = 0;
    int val, m, n;

    m = -1;
    n = 5;

    x = x*m+n;

    if(x <= 10 && x >= y) {
        return;
    }

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

