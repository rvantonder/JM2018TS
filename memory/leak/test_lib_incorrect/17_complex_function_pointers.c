#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "memory_leak.h"

static void assign_possibly_freed(int** dest, bool free_data) {
    int* data = malloc(5*sizeof(int));
    *dest = data;
    if(!data) {
        return;
    }
    if(free_data) {
        free(data);
    } else {
        *data = 67982;
    }
}

void mem_leak_function_pointer(bool a, bool b, void (*f)(int** dest, bool free_data)) {
    int* data;
    int val = 0;


    (*f)(&data, a);
    if(b && !a && data) {
        val = *data;
        free(data);
    } else {
        val = 687;
    }

    printf("%i\n", val);
}

