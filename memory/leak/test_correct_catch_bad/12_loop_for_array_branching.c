#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory_leak.h"

void mem_leak_for_array(int x) {
    int* data = 0;
    int p[20];
    int val = 0;
    bool do_free = true;
    int i;

    if(x != 19) {
        return;
    }

    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            do_free = false;
        } else {
            if(!data) data = malloc(sizeof(int));

            if(!data) {
                return;
            }

            *data = 27;
            val += *data + i;
            if(do_free) {
                free(data);
                data = 0;
            }
        }
    }

    printf("%i\n", val);
}

int main() {
    mem_leak_for_array(19);

    return 1;
}
