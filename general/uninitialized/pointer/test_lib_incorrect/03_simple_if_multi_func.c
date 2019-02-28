#include "uninit_ptr.h"
#include <stdbool.h>
#include <stdio.h>

static int** choose_pointer_local(int** source1, int** source2, bool condition) {
    if(condition) {
        return source1;
    } else {
        return source2;
    }
}

static int int_dereference_choice_local(int** source1, int** source2, bool condition) {
    if(condition) {
        return **source1;
    }
    return **source2;
}

void uninit_ptr_if_else_multi(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* arr_allias = arr;
    int** ptr;
    int* uninit;
    int val;


    ptr = choose_pointer_local(&arr_allias, &uninit, a);

    val = int_dereference_choice_local(&arr_allias, ptr, b); /* DANGER, if !a & !b */

    printf("%i\n", val);
}

