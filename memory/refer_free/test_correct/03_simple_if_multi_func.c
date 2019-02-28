#include "refer_free.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void local_conditional_free(int** ptr, bool condition) {
    if(condition) {
        free(*ptr);
    }
}

static int conditional_dereference(int** ptr, int def, bool condition) {
    if(condition) {
        return **ptr;
    }
    return def;
}

void refer_free_if_else_multi(bool a, bool b) {
    int val;
    int* data;
    int** data_ptr = &data;

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 27;

    local_conditional_free(data_ptr, !a);
    val = conditional_dereference(data_ptr, 8, !b); /* DANGER, if !a & !b */
    local_conditional_free(data_ptr, a);

    printf("%i\n", val);
}

int main() {
    refer_free_if_else_multi(true, true);
    refer_free_if_else_multi(true, false);
    refer_free_if_else_multi(false, true);
    return 1;
}
