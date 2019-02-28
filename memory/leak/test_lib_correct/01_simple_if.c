#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory_leak.h"

void mem_leak_if_else(bool a, bool b) {
    int* data;
    int val = 0;

    if(!a & !b) {
        return;
    }

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 27;

    if(a) {
        val = *data;
        free(data);
    } else {
        (*data)++;
    }

    if(b & !a) {
        val = *data;
        free(data);
    } else {
        val += 37;
    }

    printf("%i\n", val);
}

