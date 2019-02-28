#include <stdio.h>
#include <stdlib.h>
#include "access_closed.h"

int access_closed_pseudo_rec1(int x, int y, int i, FILE** file_ptr) {
    int val;

    if(!*file_ptr) {
        return -1;
    }

    val = ((int) fgetc(*file_ptr));

    if(i > 0) {
        fclose(*file_ptr);
        return 37;
    }

    if(x < y) {
        fclose(*file_ptr);
    } else {
        fgetc(*file_ptr);
    }

    return val + access_closed_pseudo_rec2(x, y, 1, file_ptr);
}

int access_closed_pseudo_rec2(int x, int y, int i, FILE** file_ptr) {
    int val = 78;
    if(i > 0) {
        if(x < 10) {
            val -= ((int) fgetc(*file_ptr));
        } else {
            val += 2;
        }

        if(x >= y) {
            fclose(*file_ptr);
            *file_ptr = 0;
        }
        return val;
    }

    return 5 + access_closed_pseudo_rec1(x, y, 1, file_ptr);
}

int main() {
    FILE* file = fopen("file.txt", "r");
    printf("%i\n", access_closed_pseudo_rec1(9, 10, 0, &file));
    file = fopen("file.txt", "r");
    printf("%i\n", access_closed_pseudo_rec1(11, 10, 0, &file));

    return 1;
}
