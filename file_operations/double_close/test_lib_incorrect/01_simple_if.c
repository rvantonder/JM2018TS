#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_close.h"

void double_close_if_else(bool a, bool b) {
    FILE* file;
    int val = 0;


    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    if(a) {
        val = ((int) fgetc(file)) * 2;
    } else {
        val = (int) fgetc(file);
        fclose(file);
    }

    if(b) {
        val += 37;
    } else {
        fclose(file);
    }

    if(a & b) {
        fclose(file);
    }

    printf("%i\n", val);
}

