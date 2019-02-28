#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory_leak.h"

static void assign_possibly_freed(int** dest, bool free_data) {
    int* data = malloc(5*sizeof(int));
    *dest = data;
    if(!data) {
        return;
    }
    *data = 6;
    if(free_data) {
        free(data);
    }
}

void mem_leak_pass_by_reference(bool a, bool b) {
    int* data;
    int val = -1;

    if(!a & !b) {
        return;
    }

    assign_possibly_freed(&data, a);
    if(b && !a && data) {
        val = *data;
        free(data);
    } else {
        val = 687;
    }

    printf("%i\n", val);
}

