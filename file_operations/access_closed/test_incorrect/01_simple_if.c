#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "access_closed.h"

void access_closed_if_else(bool a, bool b) {
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
        val += (int) fgetc(file);
    }

    if(a) {
        fclose(file);
    }

    printf("%i\n", val);
}

int main() {
    access_closed_if_else(true, true); /* OK */
    access_closed_if_else(false, false); /* DANGER */
    access_closed_if_else(false, true); /* OK */

    return 1;
}
