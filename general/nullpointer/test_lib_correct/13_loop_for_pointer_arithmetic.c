#include <stdlib.h>
#include <stdio.h>
#include "nullpointer.h"

static void initialize_to_null(int* ptr_arr[], int length) {
    int i;

    for(i = 0; i < length; i++) {
        ptr_arr[i] = 0;
    }
}

void nullpointer_for_pointer(int x) {
    int* pointers[10];
    int** ptr;
    int source[10];
    int val = 0, i;

    if(x != 10) {
        return;
    }

    initialize_to_null(pointers, 10);

    for(i = 0, ptr = pointers; i < x; i++, ptr++) {
        *(ptr) = source + i;
    }

    for(i = 0, ptr = pointers; i <= 9; i++, ptr++) {
        **(ptr) = i;
    }

    for(i = 0, ptr = pointers; i <= 9; i++, ptr++) {
        val += **(ptr);
    }

    printf("%i\n", val);
}

