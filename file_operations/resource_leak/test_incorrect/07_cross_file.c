#include "resource_leak.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void res_leak_cross_file(bool a, bool b) {
    int val;
    FILE* file;

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    conditional_close(file, a, 0);

    if(b & !a) {
        val = (int) fgetc(file);
        fclose(file);
    } else {
        val = 678;
    }

    printf("%i\n", val);
}

int main() {
    res_leak_cross_file(true, true); /* OK */
    res_leak_cross_file(false, false); /* DANGER */
    res_leak_cross_file(false, true); /* OK */
    return 1;
}
