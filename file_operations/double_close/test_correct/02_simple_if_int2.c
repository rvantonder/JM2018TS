#include <stdio.h>
#include <stdlib.h>
#include "double_close.h"

void double_close_if_else_int2(int x, int y) {
    FILE* file;
    int val = 0;
    int m, n;

    m = -1;
    n = 5;

    x = x*m+n;


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
        val += 37;
    } else {
        fclose(file);
    }

    if(x <= 10 && x >= y) {
        fclose(file);
    }

    printf("%i\n", val);
}

int main() {
    double_close_if_else_int2(-5, 10);
    double_close_if_else_int2(-5, 11);
    double_close_if_else_int2(-6, 11);

    return 1;
}
