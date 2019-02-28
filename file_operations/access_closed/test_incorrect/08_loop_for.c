#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "access_closed.h"

void access_closed_for(int x) {
    FILE* file;
    int val = 0;
    int i;


    file = fopen("file1.txt","r");

    if(!file) {
        return;
    }

    val = (int) fgetc(file);

    fclose(file);

    for(i = 0; i < 20; i++) {
        if(i > x) {
            val += (int) fgetc(file);
        } else {
            val += 24;
        }
        if(i == 10) {
            file = fopen("file2.txt","r");
            if(!file) {
                return;
            }
        }
    }

    fclose(file);

    printf("%i\n", val);
}

int main() {
    access_closed_for(9);

    return 1;
}
