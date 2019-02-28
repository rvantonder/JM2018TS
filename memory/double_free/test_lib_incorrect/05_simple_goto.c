#include <stdio.h>
#include <stdlib.h>
#include "double_free.h"

void double_free_goto(int x) {
    int* data;
    int i = 0;

    if(x <= 0) {
        return;
    }

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

GOTO_LABEL:
    if(i <= x) {
        free(data);
    } else {
        printf("Data is freed\n");
    }

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

