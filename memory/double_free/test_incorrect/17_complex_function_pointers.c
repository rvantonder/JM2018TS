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

int main() {
    double_free_function_pointer(true, true, &assign_possibly_freed); /* OK */
    double_free_function_pointer(false, false, &assign_possibly_freed); /* DANGER */
    double_free_function_pointer(false, true, &assign_possibly_freed); /* OK */

    return 1;
}
