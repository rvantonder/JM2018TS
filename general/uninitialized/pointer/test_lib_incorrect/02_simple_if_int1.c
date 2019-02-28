#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_if_else_int1(int x, int y) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val;


    if(x < y) {
        ptr = arr;
    }

    if(x > 10) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER, if x <= 10 & x >= y */
    }

    printf("x=%i: %i", x, val);
}

