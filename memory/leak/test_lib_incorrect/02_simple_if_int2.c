#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"

void mem_leak_if_else_int2(int x, int y) {
    int* data;
    int val = 0;
    int m, n;

    m = -1;
    n = 5;

    x = x*m+n;


    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 27;

    if(x <= 10) {
        val = *data;
        free(data);
    } else {
        (*data)++;
    }

    if(x >= y) {
        if(x > 10) {
            val = *data * 2;
            free(data);
        }
    } else {
        val += 10;
    }

    printf("%i\n", val);
}

