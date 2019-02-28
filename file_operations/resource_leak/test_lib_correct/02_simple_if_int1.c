#include <stdio.h>
#include <stdlib.h>
#include "resource_leak.h"

void res_leak_if_else_int1(int x, int y) {
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
        val = ((int) fgetc(file));
        fclose(file);
    } else {
        val = ((int) fgetc(file))*2;
    }

    if(x >= y) {
        if(x > 10) {
            val = ((int) fgetc(file)) * 2;
            fclose(file);
        }
    } else {
        val += 10;
    }

    printf("%i\n", val);
}

