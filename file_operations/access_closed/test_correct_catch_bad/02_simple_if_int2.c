#include <stdio.h>
#include <stdlib.h>
#include "access_closed.h"

void access_closed_if_else_int2(int x, int y) {
    FILE* file;
    int val = 0;
    int m, n;

    m = -1;
    n = 5;

    x = x*m+n;

    if(x > 10 && x < y) {
        return;
    }

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    if(x <= 10) {
        val = ((int) fgetc(file)) * 2;
    } else {
        val = (int) fgetc(file);
        fclose(file);
    }

    if(x >= y) {
        val += 10;
    } else {
        val = ((int) fgetc(file)) * 2;
    }

    if(x <= 10) {
        fclose(file);
    }

    printf("%i\n", val);
}

int main() {
    access_closed_if_else_int2(-5, 10);
    access_closed_if_else_int2(-5, 11);
    access_closed_if_else_int2(-6, 11);

    return 1;
}
