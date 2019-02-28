#include <stdio.h>
#include "nullpointer.h"

void nullpointer_if_else_int1(int x, int y) {
    int arr[3] = {1, 2, 3};
    int* ptr = 0;
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

int main() {
    nullpointer_if_else_int1(9, 10); /* OK */
    nullpointer_if_else_int1(10, 10); /* DANGER */
    nullpointer_if_else_int1(11, 10); /* OK */

    return 1;
}
