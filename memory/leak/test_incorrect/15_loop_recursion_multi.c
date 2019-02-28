#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "memory_leak.h"

int mem_leak_rec_decr(int x, int i, int* data, bool do_free) {
    if(i <= 1) {
        return 0;
    }

    return mem_leak_rec_multi(x, i-1, data, do_free);
}

int mem_leak_rec_multi(int x, int i, int* data, bool do_free) {
    int val;

    if(i <= 1) {
        return 0;
    }


    if(i < x) {
        if(!data) data = malloc(sizeof(int));
        if(!data) return -1;
        *data = i;
        val = *data;
        if(do_free) {
            free(data);
            data = 0;
        }
    } else {
        if(data) {
            val = *data / 2;
        } else {
            val = 8;
        }
    }
    if(i == 10) {
        do_free = true;
    }

    return val + mem_leak_rec_decr(x, i, data, do_free);
}

int main() {
    printf("%i\n", mem_leak_rec_multi(11, 20, 0, false));

    return 1;
}
