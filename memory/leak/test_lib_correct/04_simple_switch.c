#include "memory_leak.h"
#include <stdbool.h>
#include <stdlib.h>

int mem_leak_switch(int x, int y) {
    int* data;
    bool freed = false;
    int val = 0;

    if((x == 10 || x == 5) && x > y) {
        return -1;
    }
    data = malloc(5*sizeof(int));

    if(!data) {
        return -1;
    }

    *data = -1;

    if(x <= y) {
        free(data);
        freed = true;
    }

    switch (x) {
        case 5: {
            if(!freed) val = *data;
            freed = true; /* DANGER: x >= y */
            break;
        }
        case 7: {
            if(!freed) {
                val  = *data + 289;
                free(data);
                freed = true;
            }
            break;
        }
        case 10: {
            if(!freed) {
                val = *data + 36;
                freed = true; /* DANGER: x >= y */
            }
            break;
        }
        case 12: {
            if(!freed) {
                val  = *data + 49807;
                free(data);
            }
            freed = true;
            break;
        }
        default: {
            val  = 7987;
            break;
        }
    }

    if(!freed) {
        free(data);
    }

    return val;
}

