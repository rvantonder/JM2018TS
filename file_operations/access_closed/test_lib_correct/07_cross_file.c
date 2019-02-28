#include "access_closed.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void access_closed_cross_file(bool a, bool b) {
    int val;
    FILE* file;

    if(!a & !b) {
        return;
    }
    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    conditional_close(file, !a, 0);

    if(b) {
        val = 678;
    } else {
        val = (int) fgetc(file);
    }

    if(a) {
        fclose(file);
    }

    printf("%i\n", val);
}

