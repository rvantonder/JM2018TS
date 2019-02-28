#include "uninitialized_value.h"

int uninit_val_switch(int x, int y) {
    int possibly_uninit;
    int val;


    if(x < y) {
        possibly_uninit = 1;
    }

    switch (x) {
        case 5: {
            val = 37 * possibly_uninit; /* DANGER: x >= y */
            break;
        }
        case 7: {
            val = -37 * 2;
            break;
        }
        case 10: {
            val = 73 * possibly_uninit; /* DANGER: x >= y */
            break;
        }
        case 12: {
            val = 73 * 5;
            break;
        }
        default: {
            val = 100 * 8;
            break;
        }
    };

    return val;
}

