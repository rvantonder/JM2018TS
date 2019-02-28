#include <stdio.h>
#include <stdlib.h>
#include "double_close.h"

void double_close_goto(int x) {
    FILE* file = 0;
    int val = 0;
    int i = 0;

    if(i > x) {
        return;
    }


    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    val += (int) fgetc(file);

GOTO_LABEL:
    if(i <= x) {
        fclose(file);
    } else {
        printf("%i\n", val);
    }

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

int main() {
    double_close_goto(0);

    return 1;
}
