#include "double_free.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void double_free_cross_file(bool a, bool b) {
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
        if (a) {
            free(data);
        }
    } else {
        free(data); /* DANGER, if !a & !b */
    }
}

int main() {
    double_free_cross_file(true, true);
    double_free_cross_file(true, false);
    double_free_cross_file(false, true);
    return 1;
}
