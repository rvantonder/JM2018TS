#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_close.h"

void double_close_for_array(int x) {
    FILE* file = 0;
    int p[20];
    int val = 0;
    int i;

    if(x != 19) {
        return;
    }

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    val += ((int) fgetc(file));

    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            fclose(file);
        } else {
            fclose(file);
            file = fopen("file.txt","r");

            if(!file) {
                return;
            }
            val += ((int) fgetc(file)) + i;
        }
    }

    printf("%i\n", val);
}

