#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "double_close.h"

int double_close_rec_decr(int x, int i, FILE** file_ptr) {
    if(i <= 1) {
        if(*file_ptr) fclose(*file_ptr);
        *file_ptr = 0;
        return 0;
    }

    return double_close_rec_multi(x, i-1, file_ptr);
}

int double_close_rec_multi(int x, int i, FILE** file_ptr) {
    int val;


    if(i > 19 && !*file_ptr) {
        *file_ptr = fopen("file.txt", "r");
        return double_close_rec_decr(x, i, file_ptr);
    }
    if(i == 19) {
        if(*file_ptr) {
            fclose(*file_ptr);
        }
        return double_close_rec_decr(x, i, file_ptr);
    }

    if(i < x) {
        fclose(*file_ptr);
        *file_ptr = fopen("file.txt","r");
        if(!*file_ptr) {
            return -1;
        }
        val = (int) fgetc(*file_ptr);
    } else {
        val = 8;
    }
    if(i == 10 && !*file_ptr) {
        *file_ptr = fopen("file.txt","r");
        if(!*file_ptr) {
            return -1;
        }
    }

    return val + double_close_rec_decr(x, i, file_ptr);
}

int main() {
    FILE* file = 0;
    printf("%i\n", double_close_rec_multi(11, 20, &file));

    return 1;
}
