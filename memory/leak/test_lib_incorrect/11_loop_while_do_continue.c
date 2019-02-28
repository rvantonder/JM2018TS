#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"

void mem_leak_do_while_continue(int x) {
    int* data;
    int val = 0;
    bool do_free = false;
    bool is_freed = true;
    int i = 0;


    do {
        if(i == 8) {
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
    } while(i < 30);

    printf("%i\n", val);
}

