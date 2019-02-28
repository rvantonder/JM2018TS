#include <stdio.h>
#include "uninit_ptr.h"

int uninit_ptr_pseudo_rec1(int x, int y, int i, int** ptr1, int** ptr2) {
    int* uninit;
    if(!ptr2 && x <= 10 && x >= y) {
        return 0;
    }
    if(!ptr2) {
        ptr2 = &uninit;
    }

    if(i > 0) {
        return 37;
    }

    if(x < y) {
        ptr2 = ptr1;
    }

    return uninit_ptr_pseudo_rec2(x, y, 1, ptr1, ptr2);
}

int uninit_ptr_pseudo_rec2(int x, int y, int i, int** ptr1, int** ptr2) {
    int** ptr;

    if(i > 0) {
        return **ptr1 + uninit_ptr_pseudo_rec1(x, y, 1, ptr1, ptr2);
    }

    if(x > 10) {
        ptr = ptr1;
    } else {
        ptr = ptr2;
    }

    return **ptr;
}

