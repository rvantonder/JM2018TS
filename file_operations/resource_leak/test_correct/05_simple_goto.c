#include <stdio.h>
#include <stdlib.h>
#include "resource_leak.h"

void res_leak_goto(int x) {
    FILE* file = 0;
    int val = 0;
    int i = 0;


GOTO_LABEL:
    if(i <= x) {
        file = fopen("file.txt","r");

        if(!file) {
            return;
        }

        val += ((int) fgetc(file));
    } else {
        printf("%i\n", val);
    }

    if(i == 0) {
        i++;
        if(file) fclose(file);
        goto GOTO_LABEL;
    }
}

int main() {
    res_leak_goto(0);

    return 1;
}
