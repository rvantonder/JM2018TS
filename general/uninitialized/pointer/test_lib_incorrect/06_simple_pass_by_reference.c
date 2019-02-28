#include <stdio.h>
#include <stdbool.h>
#include "uninit_ptr.h"

static void local_assign_pointer(int*** dest, int** source1, int** source2, bool condition) {
    if(condition) {
        *dest = source1;
    } else {
        *dest = source2;
    }
}

void uninit_ptr_pass_by_reference(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* arr_allias = arr;
    int** ptr;
    int* uninit;
    int val;


    local_assign_pointer(&ptr, &arr_allias, &uninit, a);

    if(b) {
        val = arr[2];
    } else {
        val = **ptr; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

