#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_for(int x) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val = 0;
    int i;

    if(x < 10) {
        return;
    }

    for(i = 0; i < 20; i++) {
        if(i > x) {
            val += *ptr; /* DANGER: x < 10 */
        } else {
            val += arr[0];
        }
        if(i == 10) {
            ptr = arr;
            val += *ptr;
        }
    }

    printf("val = %i", val);
}

int main() {
    uninit_ptr_for(10);

    return 1;
}
