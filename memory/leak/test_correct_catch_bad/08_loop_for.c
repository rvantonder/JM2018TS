#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "memory_leak.h"

void mem_leak_for(int x) {
    int* data;
    int val = 0;
    bool do_free = false;
    bool is_freed = true;
    int i;

    if(x < 10) {
        return;
    }

    for(i = 0; i < 20; i++) {
        if(i > x && is_freed) {
            data = malloc(5*sizeof(int));
            if(!data) {
                return;
            }
            *data = i;
            val += *data * 2;
            if(do_free) {
                free(data);
                is_freed = true;
            } else {
                is_freed = false;
            }
        } else {
            if(!is_freed) {
                val += *data;
            } else {
                val += 37;
            }
        }
        if(i == 10) {
            do_free = true;
        }
    }

    printf("%i\n", val);
}

int main() {
    mem_leak_for(10);

    return 1;
}
