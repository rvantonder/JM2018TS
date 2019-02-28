#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_for_array(int x) {
    int uninit_value;
    int init_value = 35;
    int* possibly_uninit = &init_value;
    int p[20];
    int val = 0, i = 0;

    if(x < 0 || x > 19) {
        return;
    }


    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            possibly_uninit = &uninit_value;
        } else {
            val += *possibly_uninit; /* DANGER: x < 19 */
        }
    }

    printf("%i\n", val);
}

int main() {
    uninit_val_for_array(19);

    return 1;
}
