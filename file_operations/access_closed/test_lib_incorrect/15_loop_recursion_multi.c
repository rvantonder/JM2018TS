#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "access_closed.h"

int access_closed_rec_decr(int x, int i, FILE** file_ptr) {
    if(i <= 1) {
        if(*file_ptr) fclose(*file_ptr);
        *file_ptr = 0;
        return 0;
    }

    return access_closed_rec_multi(x, i-1, file_ptr);
}

int access_closed_rec_multi(int x, int i, FILE** file_ptr) {
    int val;

    if(i > 19 && !*file_ptr) {
        *file_ptr = fopen("file.txt", "r");
        access_closed_rec_decr(x, i, file_ptr);
    }
    if(i == 19) {
        if(*file_ptr) {
            fclose(*file_ptr);
        }
        access_closed_rec_decr(x, i, file_ptr);
    }

    if(i < x && *file_ptr) {
        val = (int) fgetc(*file_ptr);
    } else {
        val = 8;
    }
    if(i == 10 && !*file_ptr) {
        *file_ptr = fopen("file.txt","r");
        if(!*file_ptr) return -1;
    }

    return val + access_closed_rec_decr(x, i, file_ptr);
}

