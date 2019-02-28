#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "double_free.h"

int double_free_rec_decr(int x, int i, int** data_ptr, bool* is_freed) {
    if(i <= 1) {
        return 0;
    }

    return double_free_rec_multi(x, i-1, data_ptr, is_freed);
}

int double_free_rec_multi(int x, int i, int** data_ptr, bool* is_freed) {
    int n_freed = 0;

    if(i <= 1) {
        return 0;
    }


    if(i < 20 && i < x) {
        free(*data_ptr); /* DANGER: x > 10 */
        *data_ptr = malloc(5*sizeof(int));
        if(!data_ptr) {
            *is_freed = true;
            return 0;
        }
        *is_freed = false;
    } else {
        n_freed--;
    }
    if(i == 10 && *is_freed) {
        *data_ptr = malloc(5*sizeof(int));
        if(!(*data_ptr)) {
            *is_freed = true;
            return 0;
        }
        *is_freed = false;
    }

    return 1 + n_freed + double_free_rec_decr(x, i, data_ptr, is_freed);
}

int main() {
    int* data = malloc(sizeof(int));
    int** data_ptr = &data;
    free(data);
    bool is_freed = true;
    printf("%i\n", double_free_rec_multi(11, 20, data_ptr, &is_freed));
    if(!is_freed) {
        free(data);
        is_freed = true;
    }

    return 1;
}
