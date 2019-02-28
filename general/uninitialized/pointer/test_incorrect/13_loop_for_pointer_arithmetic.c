#include <stdlib.h>
#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_for_pointer(int x) {
    int* pointers[10];
    int** ptr;
    int source[10];
    int val = 0, i;


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

int main() {
    uninit_ptr_for_pointer(9);

    return 1;
}
