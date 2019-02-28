#include <stdlib.h>
#include <stdio.h>
#include "uninitialized_value.h"

static void initialize_to_zero(int arr[], int length) {
    int i;

    for(i = 0; i < length; i++) {
        arr[i] = 0;
    }
}

void uninit_val_for_pointer(int x) {
    int possibly_uninits[10];
    int* ptr;
    int val = 0, i;

    if(x < 0 || x > 10) {
        return;
    }

    if(x != 10) {
        return;
    }

    ptr = possibly_uninits;
    for(i = 0; i < x; i++, ptr++) {
        *ptr = i + 1;
    }

    ptr = possibly_uninits;
    for(i = 0; i <= 9; i++, ptr++) {
        val += *ptr;
    }

    printf("%i\n", val);
}

