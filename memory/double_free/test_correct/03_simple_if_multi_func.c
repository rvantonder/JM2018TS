#include "double_free.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void local_conditional_free(int** ptr, bool condition) {
    if(condition) {
        free(*ptr);
    }
}

void double_free_if_else_multi(bool a, bool b) {
    int* data;
    int** data_ptr = &data;

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    local_conditional_free(data_ptr, a & b);
    local_conditional_free(data_ptr, !b);
    local_conditional_free(data_ptr, !a); /* DANGER, if !a & !b */
}

int main() {
    double_free_if_else_multi(true, true);
    double_free_if_else_multi(true, false);
    double_free_if_else_multi(false, true);
    return 1;
}
