#include "double_close.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void double_close_cross_file(bool a, bool b) {
    int val;
    FILE* file;

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    val = (int) fgetc(file);

    conditional_close(file, !a, 0);

    if(b) {
        val = 678;
    } else {
        fclose(file);
    }

    if(a & b) {
        fclose(file);
    }

    printf("%i\n", val);
}

int main() {
    double_close_cross_file(true, true); /* OK */
    double_close_cross_file(false, false); /* DANGER */
    double_close_cross_file(false, true); /* OK */
    return 1;
}
