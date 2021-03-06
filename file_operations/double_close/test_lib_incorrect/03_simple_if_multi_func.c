#include "double_close.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void conditional_close(FILE** ptr, bool condition) {
    if(condition) {
        fclose(*ptr);
    }
}

static int conditional_fgetc(FILE** ptr, int def, bool condition) {
    if(condition) {
        return fgetc(*ptr);
    }
    return def;
}

void double_close_if_else_multi(bool a, bool b) {
    int val;
    FILE* file;
    FILE** file_ptr = &file;

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    conditional_close(file_ptr, !a);
    val = conditional_fgetc(file_ptr, 897, b & a);
    conditional_close(file_ptr, !b);
    conditional_close(file_ptr, a & b);

    printf("%i\n", val);
}

