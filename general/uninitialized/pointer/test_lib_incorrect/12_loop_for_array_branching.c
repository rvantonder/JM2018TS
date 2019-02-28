#include <stdio.h>
#include "uninit_ptr.h"

void uninit_ptr_for_array(int x) {
    int p[20];
    int* arr_allias = p;
    int** ptr = &arr_allias;
    int* uninit;
    int val = 0, i = 0;


    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            ptr = &uninit;
        } else {
            val = **ptr; /* DANGER: x < 19 */
        }
    }

    printf("%i\n", val);
}

