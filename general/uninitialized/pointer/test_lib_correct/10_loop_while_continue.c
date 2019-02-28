#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_while_continue(int x) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val = 0, i = 0;

    if(x < 10) {
        return;
    }

    while(i < 30) {
        if(i > x) {
            val += *ptr; /* DANGER: x < 10 */
        } else {
            val += arr[0];
        }
        if(i == 10) {
            ptr = arr;
            val += *ptr;
        }
        i++;
        if(i < 20) {
            continue;
        }
    }

    printf("val = %i", val);
}

