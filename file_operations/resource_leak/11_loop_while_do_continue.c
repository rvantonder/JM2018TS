#include <stdio.h>
#include <stdlib.h>
#include "resource_leak.h"

void res_leak_do_while_continue(int x) {
    FILE* file;
    int val = 0;
    bool do_close = false;
    bool is_closed = true;
    int i = 0;

#ifdef CATCH_BAD_PARAM
    if(x < 10) {
        return;
    }
#endif

    do {
        if(i == 8) {
            i++;
            continue;
        }
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
        if(i < 20) {
            continue;
        }
    } while(i < 30);

    printf("%i\n", val);
}

#ifndef NO_MAIN
int main() {
#ifdef NO_BUG
    res_leak_do_while_continue(10);
#else
    res_leak_do_while_continue(9);
#endif

    return 1;
}
#endif
