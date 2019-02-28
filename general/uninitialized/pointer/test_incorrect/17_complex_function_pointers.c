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

void uninit_ptr_function_pointer(bool a, bool b, void (*f)(int***, int**, int**, bool)) {
    int arr[3] = {1, 2, 3};
    int* arr_allias = arr;
    int* uninit;
    int** ptr;
    int val;


    (*f)(&ptr, &arr_allias, &uninit, a);

    if(b) {
        val = arr[2];
    } else {
        val = **ptr; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    uninit_ptr_function_pointer(true, true, &local_assign_pointer); /* OK */
    uninit_ptr_function_pointer(false, false, &local_assign_pointer); /* DANGER */
    uninit_ptr_function_pointer(false, true, &local_assign_pointer); /* OK */

    return 1;
}
