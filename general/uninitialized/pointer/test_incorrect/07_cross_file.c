#include "uninit_ptr.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>

void uninit_ptr_cross_file(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* arr_allias = arr;
    int** ptr;
    int* uninit;
    int val;


    ptr = (int**)choose_pointer((void*) &arr_allias, (void*) &uninit, a);

    if(b) {
        val = arr[2];
    } else {
        val = **ptr; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    uninit_ptr_cross_file(true, true); /* OK */
    uninit_ptr_cross_file(false, false); /* DANGER */
    uninit_ptr_cross_file(false, true); /* OK */
    return 1;
}
