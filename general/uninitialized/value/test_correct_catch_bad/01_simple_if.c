#include <stdio.h>
#include <stdbool.h>
#include "uninitialized_value.h"

void uninit_val_if_else(bool a, bool b) {
    int possibly_uninit;
    int val;

    if(!a & !b) {
        return;
    }

    if(a) {
        possibly_uninit = 1;
    }

    if(b) {
        val = 37 * 2;
    } else {
        val = 11 * possibly_uninit; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    uninit_val_if_else(true, true);
    uninit_val_if_else(true, false);
    uninit_val_if_else(false, true);

    return 1;
}
