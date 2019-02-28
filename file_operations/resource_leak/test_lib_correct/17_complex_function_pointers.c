#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "resource_leak.h"

static int assign_possibly_closed(FILE** dest, bool close_file) {
    int val;
    FILE* file = fopen("file.txt","r");
    *dest = file;
    if(!file) {
        return -1;
    }
    val = (int) fgetc(file);
    if(close_file) {
        fclose(file);
    }
    return val;
}

void res_leak_function_pointer(bool a, bool b, int (*f)(FILE** dest, bool close_file)) {
    FILE* file;
    int val = 0;

    if(!f || (!a & !b)) {
        return;
    }

    val = (*f)(&file, a);

    if(b && !a && file) {
        val += (int) fgetc(file);
        fclose(file);
    } else {
        val += 687;
    }

    printf("%i\n", val);
}

