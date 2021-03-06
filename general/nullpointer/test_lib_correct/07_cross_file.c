#include "nullpointer.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>

void nullpointer_cross_file(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* ptr = 0;
    int val;

    if(!a & !b) {
        return;
    }

    ptr = (int*)choose_pointer((void*)(arr+1), 0, a);

    if(b) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

