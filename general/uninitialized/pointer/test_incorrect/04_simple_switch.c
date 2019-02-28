#include "uninit_ptr.h"

int uninit_ptr_switch(int x, int y) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val;


    if(x < y) {
        ptr = arr;
    }

    switch (x) {
        case 5: {
            val = *(ptr+2); /* DANGER: x >= y */
            break;
        }
        case 7: {
            val = arr[0] + 5;
            break;
        }
        case 10: {
            val = *ptr; /* DANGER: x >= y */
            break;
        }
        case 12: {
            val = arr[2] + 5;
            break;
        }
        default: {
            val = arr[1];
            break;
        }
    };

    return val;
}

int main() {
    uninit_ptr_switch(5, 10); /* OK */
    uninit_ptr_switch(10, 10); /* DANGER */
    uninit_ptr_switch(11, 10); /* OK */
    uninit_ptr_switch(7, 5); /* OK */

    return 1;
}
