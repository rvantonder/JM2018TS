#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "double_free.h"

int double_free_rec(int x, int i, int** data_ptr, bool* is_freed) {
    int n_freed = 0;

    if(i <= 1) {
        return 0;
    }

    if(x > 10 && *is_freed) {
        return -1;
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

    return 1 + n_freed + double_free_rec(x, i-1, data_ptr, is_freed);
}

