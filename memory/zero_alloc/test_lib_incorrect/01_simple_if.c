#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "zero_alloc.h"

void zero_alloc_if_else(bool a, bool b) {
    size_t size;
    int* data;


    if(a) {
        size = 5 * sizeof(int);
    } else {
        size = 0;
    }

    if(b) {
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

