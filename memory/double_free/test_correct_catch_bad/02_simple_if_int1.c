#include <stdio.h>
#include <stdlib.h>
#include "double_free.h"

void double_free_if_else_int1(int x, int y) {
    int* data;

    if(x > 10 && x < y) {
        return;
    }

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

int main() {
    double_free_if_else_int1(10, 10);
    double_free_if_else_int1(10, 11);
    double_free_if_else_int1(11, 11);

    return 1;
}
