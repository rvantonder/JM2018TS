#include <stdio.h>
#include <stdbool.h>
#include "uninit_ptr.h"

void uninit_ptr_if_else(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val;


    if(a) {
        ptr = arr;
    }

    if(b) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

