#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "refer_free.h"

void refer_free_for(int x) {
    int* data;
    int val = 0;
    int i;

    if(x < 10) {
        return;
    }
    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 9;

    free(data);

    for(i = 0; i < 20; i++) {
        if(i > x) {
            val += *data;
        } else {
            val += 37;
        }
        if(i == 10) {
            data = malloc(5*sizeof(int));
            if(!data) {
                return;
            }
            *data = 9;
        }
    }

    free(data);

    printf("%i\n", val);
}

