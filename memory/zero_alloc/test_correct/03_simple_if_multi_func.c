#include "zero_alloc.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static size_t choose_size(int size1, int size2, bool return_first) {
    if(return_first) {
        return size1;
    }
    return size2;
}

static void* malloc_conditional_size(size_t size1, size_t size2, bool use_first) {
    if(use_first) {
        return malloc(size1);
    } else {
        return malloc(size2);
    }
}

void zero_alloc_if_else_multi(bool a, bool b) {
    size_t size;
    int* data;


    size = choose_size(sizeof(int), 0, a);
    data = (int*) malloc_conditional_size(size + sizeof(int), size * 3, b); /* DANGER, if !a & !b */

    if(data) {
        *data = 34;
        printf("%i\n", *data);
        free(data);
    }
}

int main() {
    zero_alloc_if_else_multi(true, true);
    zero_alloc_if_else_multi(true, false);
    zero_alloc_if_else_multi(false, true);
    return 1;
}
