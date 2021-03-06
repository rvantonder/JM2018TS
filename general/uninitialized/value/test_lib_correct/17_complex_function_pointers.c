#include <stdio.h>
#include <stdbool.h>
#include "uninitialized_value.h"

static void assign_int_ptr(int** dest, int* ptr1, int* ptr2, bool condition) {
    if(condition) {
        *dest = ptr1;
    } else {
        *dest = ptr2;
    }
}

void uninit_val_function_pointer(bool a, bool b, void (*f)(int**, int*, int*, bool)) {
    int* possibly_uninit;
    int uninit_val;
    int init_val = 7;
    int val;

    /* To be used if NO_BUG is defined */
    /* and tool warns about possible dangerous input */
    if(!f || (!a & !b)) {
        return;
    }

    (*f)(&possibly_uninit, &init_val, &uninit_val, a);

    if(b) {
        val = 25 * 4;
    } else {
        val = 91 * (*possibly_uninit); /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

