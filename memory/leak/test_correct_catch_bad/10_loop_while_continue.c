#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"

void mem_leak_while_continue(int x) {
    int* data;
    int val = 0;
    bool do_free = false;
    bool is_freed = true;
    int i = 0;

    if(x < 10) {
        return;
    }

    while(i < 30) {
        if(i == 9) {
            i++;
            continue;
        }
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
        i++;
    }

    printf("%i\n", val);
}

int main() {
    mem_leak_while_continue(10);

    return 1;
}
