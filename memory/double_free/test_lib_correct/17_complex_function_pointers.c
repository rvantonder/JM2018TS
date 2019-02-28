#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "double_free.h"

static void assign_possibly_freed(int** dest, bool free_data) {
    int* data = malloc(5*sizeof(int));
    *dest = data;
    if(free_data && data) {
        free(data);
    }
}

void double_free_function_pointer(bool a, bool b, void (*f)(int** dest, bool free_data)) {
    int* data;

    if(!f || (!a & !b)) {
        return;
    }

    (*f)(&data, !a);

    if(b) {
        if(a && data) {
            free(data);
        }
    } else {
        if(data) {
            free(data); /* DANGER, if !a & !b */
        }
    }
}

