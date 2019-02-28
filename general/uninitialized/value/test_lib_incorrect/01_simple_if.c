#include <stdio.h>
#include <stdbool.h>
#include "uninitialized_value.h"

void uninit_val_if_else(bool a, bool b) {
    int possibly_uninit;
    int val;


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

