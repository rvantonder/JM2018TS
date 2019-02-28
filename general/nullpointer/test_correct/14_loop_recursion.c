#include <stdio.h>
#include "nullpointer.h"

int nullpointer_rec(int x, int i, int* ptr1, int* ptr2) {
    int* ptr;
    int val = 0;

    if(i <= 1) {
        return 0;
    }

    if(!ptr1 || !ptr2) { /* Signal the tools that these can be null (for -DNO_MAIN) */
        val++;
    }


    if(i < x) {
        ptr = ptr2;
    } else {
        ptr = ptr1;
    }
    if(i == 10) {
        return *ptr + nullpointer_rec(x, i-1, ptr1, ptr1);
    }
    return val + *ptr + nullpointer_rec(x, i-1, ptr1, ptr2);
}

int main() {
    int arr[3] = {1, 2, 3};
    printf("%i\n", nullpointer_rec(10, 20, arr, 0));
    printf("%i\n", nullpointer_rec(11, 20, arr, arr+1));

    return 1;
}
