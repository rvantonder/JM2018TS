#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "resource_leak.h"

void res_leak_for_array(int x) {
    FILE* file = 0;
    int p[20];
    int val = 0;
    bool do_close = true;
    int i;


    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            do_close = false;
        } else {
            if(!file) file = fopen("file.txt","r");

            if(!file) {
                return;
            }

            val += ((int) fgetc(file)) + i;
            if(do_close) {
                fclose(file);
                file = 0;
            }
        }
    }

    printf("%i\n", val);
}

int main() {
    res_leak_for_array(19);

    return 1;
}
