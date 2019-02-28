#include <stdio.h>
#include <stdlib.h>
#include "refer_free.h"

void refer_free_if_else_int2(int x, int y) {
    int* data;
    int val, m, n;

    m = -1;
    n = 5;

    x = x*m+n;


    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 27;

    if(x > 10) {
        free(data);
    } else {
        data[3] = -4;
    }

    if(x >= y) {
        val = 78;
    } else {
        val = *data; /* DANGER, if x <= 10 & x >= y */
    }

    if(x <= 10) {
        free(data);
    }

    printf("%i\n", val);
}

int main() {
    refer_free_if_else_int2(-5, 10);
    refer_free_if_else_int2(-5, 11);
    refer_free_if_else_int2(-6, 11);

    return 1;
}
