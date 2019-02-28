#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_do_while_continue(int x) {
    int possibly_uninit;
    int val = 0, i = 0;


    do {
        if(i > x) {
            val += 10 * (possibly_uninit - 2); /* DANGER: x < 10 */
        } else {
            val += 10 * 4;
        }
        if(i == 10) {
            possibly_uninit = 4;
            val += 10 * possibly_uninit;
        }
        i++;
        if(i < 20) {
            continue;
        }
    } while(i < 30);

    printf("val = %i", val);
}

int main() {
    uninit_val_do_while_continue(9);

    return 1;
}
