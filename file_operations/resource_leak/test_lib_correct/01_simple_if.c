#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "resource_leak.h"

void res_leak_if_else(bool a, bool b) {
    FILE* file;
    int val = 0;

    if(!a & !b) {
        return;
    }

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    if(a) {
        val = (int) fgetc(file);
        fclose(file);
    } else {
        val = ((int) fgetc(file)) * 2;
    }

    if(b & !a) {
        val += (int) fgetc(file);
        fclose(file);
    } else {
        val += 37;
    }

    printf("%i\n", val);
}

