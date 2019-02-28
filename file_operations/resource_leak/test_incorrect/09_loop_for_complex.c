#include <stdio.h>
#include <stdlib.h>
#include "resource_leak.h"

void res_leak_for_complex(int x) {
    FILE* file;
    int val = 0;
    bool do_close = false;
    bool is_closed = true;
    int i = 0;


    for(;;) {
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
        i++;
        if(i >= 20) {
            break;
        }
    }

    printf("%i\n", val);
}

int main() {
    res_leak_for_complex(9);

    return 1;
}
