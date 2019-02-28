#include "zero_alloc.h"
#include <stdlib.h>
#include <stdio.h>

void zero_alloc_switch(int x, int y) {
    size_t size;
    int* data;

    if((x == 10 || x == 5) && x > y) {
        return;
    }

    if(x <= y) {
        size = 2 * sizeof(int);
    } else {
        size = 0;
    }

    switch (x) {
        case 5: {
            data = malloc(size * 2); /* DANGER: x >= y */
            break;
        }
        case 7: {
            data = malloc(size + sizeof(int));
            break;
        }
        case 10: {
            data = malloc(size * 3); /* DANGER: x >= y */
            break;
        }
        case 12: {
            data = malloc(size + 3 * sizeof(int));
            break;
        }
        default: {
            data = malloc(size + 5 * sizeof(int));
            break;
        }
    };

    if(data) {
        *data = 34;
        printf("%i\n", *data);
        free(data);
    }
}

