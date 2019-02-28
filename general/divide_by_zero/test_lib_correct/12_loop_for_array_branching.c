#include <stdio.h>
#include "divide_by_zero.h"

void divide_zero_for_array(int x) {
    int divisor = 2;
    int p[20];
    int val = 0, i = 0;

    if(x < 0 || x > 19) {
        return;
    }

    if(x != 19) {
        return;
    }

    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            divisor -= 2;
        } else {
            val = 10 / divisor; /* DANGER: x < 19 */
        }
    }

    printf("%i\n", val);
}

