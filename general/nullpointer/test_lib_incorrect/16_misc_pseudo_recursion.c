#include <stdio.h>
#include "nullpointer.h"

int nullpointer_pseudo_rec1(int x, int y, int i, int* ptr1, int* ptr2) {
    int val = 0;

    if(!ptr1 || !ptr2) { /* Signal the tools that these can be null (for -DNO_MAIN) */
        val++;
    }


    if(i > 0) {
        return 37;
    }

    if(x < y) {
        ptr2 = ptr1;
    }

    return val + nullpointer_pseudo_rec2(x, y, 1, ptr1, ptr2);
}

int nullpointer_pseudo_rec2(int x, int y, int i, int* ptr1, int* ptr2) {
    int* ptr;

    if(i <= 0) {
        return *ptr1 + nullpointer_pseudo_rec1(x, y, 1, ptr1, ptr2);
    }

    if(x > 10) {
        ptr = ptr1;
    } else {
        ptr = ptr2;
    }

    return *ptr;
}

