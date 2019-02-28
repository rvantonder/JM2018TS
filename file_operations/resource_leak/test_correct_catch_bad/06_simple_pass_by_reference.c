#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void res_leak_pass_by_reference(bool a, bool b) {
    FILE* file;
    int val;

    if(!a & !b) {
        return;
    }

    val = assign_possibly_closed(&file, a);

    if(b && !a && file) {
        val += (int) fgetc(file);
        fclose(file);
    } else {
        val += 687;
    }

    printf("%i\n", val);
}

int main() {
    res_leak_pass_by_reference(true, true);
    res_leak_pass_by_reference(true, false);
    res_leak_pass_by_reference(false, true);

    return 1;
}
