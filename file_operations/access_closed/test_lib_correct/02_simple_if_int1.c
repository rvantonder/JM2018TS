#include <stdio.h>
#include <stdlib.h>
#include "access_closed.h"

void access_closed_if_else_int1(int x, int y) {
    int val = 0;
    FILE* file;

    if(x > 10 && x < y) {
        return;
    }

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    if(x <= 10) {
        val = ((int) fgetc(file)) * 2;
    } else {
        val = (int) fgetc(file);
        fclose(file);
    }

    if(x >= y) {
        val += 10;
    } else {
        val = ((int) fgetc(file)) * 2;
    }

    if(x <= 10) {
        fclose(file);
    }

    printf("%i\n", val);
}

