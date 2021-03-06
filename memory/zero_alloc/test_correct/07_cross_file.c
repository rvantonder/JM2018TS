#include "zero_alloc.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void zero_alloc_cross_file(bool a, bool b) {
    size_t size;
    int* data;


    size = sizeof(int) * choose_int(2, 0, a);

    if(b) {
        data = malloc(size + sizeof(int));
    } else {
        data = malloc(size); /* DANGER, if !a & !b */
    }

    if(data) {

    }

    if(data) {
        *data = 34;
        printf("%i\n", *data);
        free(data);
    }
}

int main() {
    zero_alloc_cross_file(true, true);
    zero_alloc_cross_file(true, false);
    zero_alloc_cross_file(false, true);
    return 1;
}
