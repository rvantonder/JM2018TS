#include <stdio.h>
#include <stdlib.h>
#include "double_free.h"

int double_free_pseudo_rec1(int x, int y, int i, int** data_ptr) {
    int data_value = **data_ptr;

    if(i > 0) {
        free(*data_ptr);
        return 37;
    }

    if(x >= y) {
        free(*data_ptr);
    }

    return data_value + double_free_pseudo_rec2(x, y, 1, data_ptr);
}

int double_free_pseudo_rec2(int x, int y, int i, int** data_ptr) {
    if(i > 0) {
        if(x <= 10) {
            free(*data_ptr);
        } else if(x > 10 && x < y) {
            free(*data_ptr);
        }
        return -1;
    }

    return 5 + double_free_pseudo_rec1(x, y, 1, data_ptr);
}

