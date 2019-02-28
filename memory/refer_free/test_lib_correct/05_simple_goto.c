#include <stdio.h>
#include <stdlib.h>
#include "refer_free.h"

void refer_free_goto(int x) {
    int* data;
    int val;
    int i = 0;

    if(x > 0) {
        return;
    }

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 7698;

GOTO_LABEL:
    if(i <= x) {
        val = *data;
    } else {
        printf("%i\n", val);
    }

    if(i == 0) {
        i++;
        free(data);
        goto GOTO_LABEL;
    }
}

