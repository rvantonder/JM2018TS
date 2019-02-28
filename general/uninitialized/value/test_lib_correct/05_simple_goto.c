#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_goto(int x) {
    int val, i;
    int possibly_uninit = 1;
    int uninit_value;
    int* val_ptr = &possibly_uninit;

    if(x > 0) {
        return;
    }

    val = 37 * *val_ptr;
    i = 0;

GOTO_LABEL:
    if(i <= x) {
        val += *val_ptr;
    } else {
        printf("%i\n", val);
    }

    val_ptr = &uninit_value;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

