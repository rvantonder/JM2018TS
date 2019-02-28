#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_close.h"

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

void double_close_pass_by_reference(bool a, bool b) {
    FILE* file;
    int val;


    val = assign_possibly_closed(&file, !a);

    if(!b) {
        if(file) fclose(file);
    } else {
        val += 687;
    }

    if(a & b) {
        if(file) fclose(file);
    }

    printf("%i\n", val);
}

int main() {
    double_close_pass_by_reference(true, true); /* OK */
    double_close_pass_by_reference(false, false); /* DANGER */
    double_close_pass_by_reference(false, true); /* OK */

    return 1;
}
