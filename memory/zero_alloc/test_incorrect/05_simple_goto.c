#include <stdio.h>
#include <stdlib.h>
#include "zero_alloc.h"

void zero_alloc_goto(int x) {
    int* data;
    size_t size = sizeof(int);
    int i = 0;


GOTO_LABEL:
    if(i <= x) {
        data = malloc(size);
        if(data) {
            *data = i;
            printf("%i\n", *data);
            free(data);
        }
    }

    if(i == 0) {
        i++;
        size -= sizeof(int);
        goto GOTO_LABEL;
    }
}

int main() {
    zero_alloc_goto(1);

    return 1;
}
