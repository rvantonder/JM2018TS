#include <stdio.h>
#include <stdbool.h>
#include "uninit_ptr.h"

void uninit_ptr_if_else(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val;


    if(a) {
        ptr = arr;
    }

    if(b) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    uninit_ptr_if_else(true, true); /* OK */
    uninit_ptr_if_else(false, false); /* DANGER */
    uninit_ptr_if_else(false, true); /* OK */

    return 1;
}
