#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "resource_leak.h"

int res_leak_rec(int x, int i, FILE** file_ptr, bool do_close) {
    int val;

    if(!do_close && x > 10) {
        return -1;
    }

    if(i <= 1) {
        return 0;
    }

    if(i < x) {
        *file_ptr = fopen("file.txt","r");
        if(!*file_ptr) return -1;
        val = ((int) fgetc(*file_ptr));
        if(do_close) {
            fclose(*file_ptr);
            *file_ptr = 0;
        }
    } else {
        if(*file_ptr) {
            val = ((int) fgetc(*file_ptr)) / 2;
        } else {
            val = 8;
        }
    }
    if(i == 10) {
        do_close = true;
    }

    return val + res_leak_rec(x, i-1, file_ptr, do_close);
}

