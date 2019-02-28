#include "refer_free.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void refer_free_cross_file(bool a, bool b) {
    int val;
    int* data;

    if(!a & !b) {
        return;
    }
    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    conditional_free((void*) data, !a, 0);

    if(b) {
        val = 678;
    } else {
        val = *data; /* DANGER, if !a & !b */
    }

    if(a) {
        free(data);
    }

    printf("%i\n", val);
}

int main() {
    refer_free_cross_file(true, true);
    refer_free_cross_file(true, false);
    refer_free_cross_file(false, true);
    return 1;
}
