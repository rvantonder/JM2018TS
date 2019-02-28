#include <stdio.h>
#include <stdlib.h>
#include "zero_alloc.h"

void zero_alloc_if_else_int1(int x, int y) {
    size_t size;
    int* data;


    if(x <= 10) {
        size = 5 * sizeof(int);
    } else {
        size = 0;
    }

    if(x >= y) {
        size += 3 * sizeof(int);
    } else {
        size = size * 5;
    }

    data = malloc(size); /* DANGER, if !a & !b */

    if(data) {
        *data = 34;
        printf("%i\n", *data);
        free(data);
    }
}

