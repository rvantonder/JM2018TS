#include <stdio.h>
#include "uninit_ptr.h"

int uninit_ptr_rec(int x, int i, int** ptr1, int** ptr2) {
    int** ptr;
    int* uninit;

    if(i <= 1 || !ptr1) {
        return 0;
    }

    if(!ptr2 && ((i < 10 && x > 2) || (i >= 10 && x > 10))) {
         return uninit_ptr_rec(x, i-1, ptr1, ptr1);
    }
    if(!ptr2) {
        ptr2 = &uninit;
    }

    if(i < x) {
        ptr = ptr2;
    } else {
        ptr = ptr1;
    }
    if(i == 10) {
        return **ptr + uninit_ptr_rec(x, i-1, ptr1, ptr1);
    }
    return **ptr + uninit_ptr_rec(x, i-1, ptr1, ptr2);
}

