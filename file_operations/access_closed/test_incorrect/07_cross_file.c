#include "access_closed.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void access_closed_cross_file(bool a, bool b) {
    int val;
    FILE* file;

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

int main() {
    access_closed_cross_file(true, true); /* OK */
    access_closed_cross_file(false, false); /* DANGER */
    access_closed_cross_file(false, true); /* OK */
    return 1;
}
