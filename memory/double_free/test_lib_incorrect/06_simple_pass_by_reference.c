#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_free.h"

static void assign_possibly_freed(int** dest, bool free_data) {
    int* data = malloc(5*sizeof(int));
    *dest = data;
    if(free_data && data) {
        free(data);
    }
}

void double_free_pass_by_reference(bool a, bool b) {
    int* data;


    assign_possibly_freed(&data, !a);
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

