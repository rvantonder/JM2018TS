#include "access_closed.h"
#include <stdbool.h>
#include <stdlib.h>

int access_closed_switch(int x, int y) {
    FILE* file;
    bool closed = false;
    int val = 0;

    file = fopen("file.txt","r");

    if(!file) {
        return -1;
    }

    if(x > y) {
        fclose(file);
        closed = true;
    }

    switch (x) {
        case 5: {
            val = ((int) fgetc(file)); /* DANGER: x >= y */
            break;
        }
        case 7: {
            if(!closed) {
                val  = ((int) fgetc(file)) + 289;
            } else {
                val = 5687;
            }
            break;
        }
        case 10: {
            val = ((int) fgetc(file)) + 36; /* DANGER: x >= y */
            break;
        }
        case 12: {
            if(!closed) {
                val  = ((int) fgetc(file)) + 49807;
            } else {
                val = 576;
            }
            break;
        }
        default: {
            val  = 7987;
            break;
        }
    }

    if(!closed) {
        fclose(file);
    }

    return val;
}

