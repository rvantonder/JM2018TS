#include "integer_overflow.h"
#include <limits.h>
#include <stdio.h>

void integer_overflow_switch(int x, int y) {
    int val;

    if((x == 10 || x == 5) && x >= y) {
        return;
    }

    if(x < y) {
        val = INT_MAX / 4 - 1;
    } else {
        val = INT_MAX / 2 - 1;
    }

    switch (x) {
        case 5: {
            val = val * 3; /* DANGER: x >= y */
            break;
        }
        case 7: {
            val = -val;
            break;
        }
        case 10: {
            val = val * 4; /* DANGER: x >= y */
            break;
        }
        case 12: {
            val = 2 * val;
            break;
        }
        default: {
           val = -2 * val;
            break;
        }
    };

    printf("%i\n", val);
}

