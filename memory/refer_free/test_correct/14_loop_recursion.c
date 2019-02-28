#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "refer_free.h"

int refer_free_rec(int x, int i, int** data_ptr) {
    int val;


    if(i <= 1) {
        return 0;
    }

    if(i < 20 && i > x && *data_ptr) {
        val = **data_ptr;
    } else {
        val = 8;
    }
    if(i == 10) {
        free(*data_ptr);
    }

    return val + refer_free_rec(x, i-1, data_ptr);
}

int main() {
    int* data = malloc(sizeof(int));
    if(!data) {
        return -1;
    }
    *data = 3;
    printf("%i\n", refer_free_rec(9, 20, &data));
    free(data);

    return 1;
}
