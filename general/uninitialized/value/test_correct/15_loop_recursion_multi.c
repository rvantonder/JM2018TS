#include <stdio.h>
#include "uninitialized_value.h"

int uninit_val_rec_decr(int x, int i, int* ptr1, int* ptr2) {
    if(i <= 1) {
        return 0;
    }

    return uninit_val_rec_multi(x, i-1, ptr1, ptr2);
}

int uninit_val_rec_multi(int x, int i, int* ptr1, int* ptr2) {
    int* possibly_uninit;
    int uninit_val;

    if(i <= 1 || !ptr1) {
        return 0;
    }

    if(!ptr2) {
        ptr2 = &uninit_val;
    }

    if(i < x) {
        possibly_uninit = ptr2;
    } else {
        possibly_uninit = ptr1;
    }
    if(i == 10) {
        *ptr2 = *ptr1;
    }
    return 3 * *possibly_uninit + uninit_val_rec_decr(x, i, ptr1, ptr2);
}

int main() {
    int init_val = 6;
    int uninit_val;
    printf("%i", uninit_val_rec_multi(10, 20, &init_val, &uninit_val));

    return 1;
}
