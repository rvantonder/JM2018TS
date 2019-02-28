#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"

void mem_leak_goto(int x) {
    int* data = 0;
    int val = 0;
    int i = 0;

    if(x > 0) {
        return;
    }

GOTO_LABEL:
    if(i <= x) {
        data = malloc(5*sizeof(int));

        if(!data) {
            return;
        }

        *data = 7698;
        val += *data;
    } else {
        printf("%i\n", val);
    }

    if(i == 0 && data) {
        i++;
        free(data);
        goto GOTO_LABEL;
    }
}

