#include <stdio.h>
#include <stdlib.h>
#include "access_closed.h"

void access_closed_goto(int x) {
    FILE* file = 0;
    int val = 0;
    int i = 0;

    if(x > 0) {
        return;
    }

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

GOTO_LABEL:
    if(i <= x) {
        val += ((int) fgetc(file));
    } else {
        printf("%i\n", val);
    }

    if(i == 0) {
        i++;
        fclose(file);
        goto GOTO_LABEL;
    }
}

int main() {
    access_closed_goto(0);

    return 1;
}
