#include "double_free.h"
#include <stdlib.h>

void double_free_switch(int x, int y) {
    int* data;

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    if(x > y) {
        free(data);
    }

    switch (x) {
        case 5: {
            free(data); /* DANGER: x >= y */
            break;
        }
        case 7: {
            if(x <= y) free(data);
            break;
        }
        case 10: {
            free(data); /* DANGER: x >= y */
            break;
        }
        case 12: {
            if(x <= y) free(data);
            break;
        }
        default: {
            if(x <= y) free(data);
            break;
        }
    };
}

int main() {
    double_free_switch(5, 11);
    double_free_switch(10, 11);
    double_free_switch(11, 10);
    double_free_switch(7, 5);

    return 1;
}
