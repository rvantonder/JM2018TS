#include <stdio.h>
#include "uninitialized_value.h"

int uninit_val_rec(int x, int i, int* ptr1, int* ptr2) {
    int* possibly_uninit;
    int uninit_val;

    if(i <= 1 || !ptr1) {
        return 0;
    }

    if(!ptr2 && ((i < 10 && x > 2) || (i >= 10 && x > 10))) {
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
    return 3 * *possibly_uninit + uninit_val_rec(x, i, ptr1, ptr2);
}

int main() {
    int init_val = 6;
    int uninit_val;
    printf("%i\n", uninit_val_rec(10, 20, &init_val, &uninit_val));
    printf("%i\n", uninit_val_rec(11, 20, &init_val, &init_val));

    return 1;
}
