#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_for(int x) {
    int possibly_uninit;
    int val = 0;
    int i;

    if(x < 10) {
        return;
    }

    for(i = 0; i < 20; i++) {
        if(i > x) {
            val += 10 * (possibly_uninit - 2); /* DANGER: x < 10 */
        } else {
            val += 10 * 4;
        }
        if(i == 10) {
            possibly_uninit = 4;
            val += 10 * possibly_uninit;
        }
    }

    printf("val = %i\n", val);
}

int main() {
    uninit_val_for(10);

    return 1;
}
