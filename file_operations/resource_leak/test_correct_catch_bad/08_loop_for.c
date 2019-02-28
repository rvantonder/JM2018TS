#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "resource_leak.h"

void res_leak_for(int x) {
    FILE* file;
    int val = 0;
    bool do_close = false;
    bool is_closed = true;
    int i;

    if(x < 10) {
        return;
    }

    for(i = 0; i < 20; i++) {
        if(i > x && is_closed) {
            file = fopen("file.txt","r");
            if(!file) {
                return;
            }
            val += (int) fgetc(file) * 2;
            if(do_close) {
                fclose(file);
                is_closed = true;
            } else {
                is_closed = false;
            }
        } else {
            if(!is_closed) {
                val += (int) fgetc(file);
            } else {
                val += 37;
            }
        }
        if(i == 10) {
            do_close = true;
        }
    }

    printf("%i\n", val);
}

int main() {
    res_leak_for(10);

    return 1;
}
