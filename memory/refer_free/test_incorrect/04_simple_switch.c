#include "refer_free.h"
#include <stdlib.h>

int refer_free_switch(int x, int y) {
    int* data;
    int val;

    data = malloc(5*sizeof(int));

    if(!data) {
        return -1;
    }

    *data = -1;

    if(x > y) {
        free(data);
    }

    switch (x) {
        case 5: {
            val = *data; /* DANGER: x >= y */
            break;
        }
        case 7: {
            val  = 289;
            break;
        }
        case 10: {
            val = *data + 36; /* DANGER: x >= y */
            break;
        }
        case 12: {
            val  = 49807;
            break;
        }
        default: {
            val  = 7987;
            break;
        }
    }

    if(x <= y) {
        free(data);
    }

    return val;
}

int main() {
    refer_free_switch(5, 10); /* OK */
    refer_free_switch(10, 9); /* DANGER */
    refer_free_switch(11, 10); /* OK */
    refer_free_switch(7, 5); /* OK */

    return 1;
}
