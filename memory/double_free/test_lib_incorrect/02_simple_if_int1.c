#include <stdio.h>
#include <stdlib.h>
#include "double_free.h"

void double_free_if_else_int1(int x, int y) {
    int* data;


    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    if(x > 10) {
        free(data);
    } else {
        data[3] = -4;
    }

    if(x < y) {
        free(data); /* DANGER, if x <= 10 & x >= y */
    }

    if(x <= 10 && x >= y) {
        free(data);
    }
}

