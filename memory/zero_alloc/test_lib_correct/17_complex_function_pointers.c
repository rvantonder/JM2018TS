#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "zero_alloc.h"

static void assign_size(size_t* size, size_t size1, size_t size2, bool use_first) {
    if(use_first) {
        *size = size1;
    } else {
        *size = size2;
    }
}

void zero_alloc_function_pointer(bool a, bool b, void (*f)(size_t* size, size_t size1, size_t size2, bool use_first)) {
    int* data;
    size_t size;

    if(!f || (!a & !b)) {
        return;
    }

    (*f)(&size, sizeof(int) * 2, sizeof(int), a);

    if(b) {
        data = malloc(size);
    } else {
        data = malloc(size - sizeof(int)); /* DANGER, if !a & !b */
    }

    if(data) {
        *data = 34;
        printf("%i\n", *data);
        free(data);
    }
}

