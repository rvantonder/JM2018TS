#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_goto(int x) {
    int arr[3] = {1, 2, 3};
    int* arr_allias = arr;
    int** ptr = &arr_allias;
    int* uninit;
    int val, i;

    if(x > 0) {
        return;
    }

    val = *(*(ptr) + 1);
    i = 0;

GOTO_LABEL:
    if(i <= x) {
        val += **ptr;
    } else {
        printf("%i\n", val);
    }

    ptr = &uninit;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

int main() {
    uninit_ptr_goto(0);

    return 1;
}
