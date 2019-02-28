#include <stdio.h>
#include "uninit_ptr.h"

int uninit_ptr_rec_decr(int x, int i, int** ptr1, int** ptr2) {
    if(i <= 1) {
        return 0;
    }

    return uninit_ptr_rec_multi(x, i-1, ptr1, ptr2);
}

int uninit_ptr_rec_multi(int x, int i, int** ptr1, int** ptr2) {
    int** ptr;
    int* uninit;

    if(!ptr1) {
        return -1;
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
        ptr2 = ptr1;
    }

    return **ptr + uninit_ptr_rec_decr(x, i, ptr1, ptr2);
}



int main() {
    int arr[3] = {1, 2, 3};
    int* arr_allias = arr;
    int* uninit;
    printf("%i", uninit_ptr_rec_multi(10, 20, &arr_allias, &uninit));

    return 1;
}
