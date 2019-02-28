#include "divide_by_zero.h"

int divide_zero_switch(int x, int y) {
    int divisor;
    int val;


    if(x < y) {
        divisor = 1;
    } else {
        divisor = 2;
    }

    switch (x) {
        case 5: {
            val = 37 / (divisor - 2); /* DANGER: x >= y */
            break;
        }
        case 7: {
            val = -37 / (divisor + 2);
            break;
        }
        case 10: {
            val = 73 / (divisor - 2); /* DANGER: x >= y */
            break;
        }
        case 12: {
            val = 73 / (divisor + 1);
            break;
        }
        default: {
            val = 100 / divisor;
            break;
        }
    };

    return val;
}

