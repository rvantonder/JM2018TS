#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_do_while_continue(int x) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val = 0, i = 0;


    do {
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
    } while(i < 30);

    printf("val = %i", val);
}

int main() {
    uninit_ptr_do_while_continue(10);

    return 1;
}
