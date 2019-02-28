#include <stdio.h>
#include "uninitialized_value.h"

void uninit_val_for_complex(int x) {
    int possibly_uninit;
    int val = 0, i = 0;

    if(x < 10) {
        return;
    }

    for(;;) {
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
        if(i >= 20) {
            break;
        }
    }

    printf("val = %i\n", val);
}

