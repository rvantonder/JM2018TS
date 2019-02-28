#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "refer_free.h"

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

void refer_free_pass_by_reference(bool a, bool b) {
    int* data;
    int val = -1;


    assign_possibly_freed(&data, !a);
    if(b) {
        val = 687;
    } else {
        if(data) {
            val = *data; /* DANGER, if !a & !b */
        }
    }

    if(a && data) {
        free(data);
    }

    printf("%i\n", val);
}

