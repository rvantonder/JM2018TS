#include "uninitialized_value.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>

void uninit_val_cross_file(bool a, bool b) {
    int* possibly_uninit;
    int init_value = 5;
    int uninit_value;
    int val;


    possibly_uninit = (int*) choose_pointer((void*) &init_value, (void*) &uninit_value, a);

    if(b) {
        val = 10 * 2;
    } else {
        val = 10 * (*possibly_uninit); /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    uninit_val_cross_file(true, true);
    uninit_val_cross_file(true, false);
    uninit_val_cross_file(false, true);
    return 1;
}
