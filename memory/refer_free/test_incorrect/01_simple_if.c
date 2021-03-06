#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "refer_free.h"

void refer_free_if_else(bool a, bool b) {
    int* data;
    int val;


    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    *data = 27;

    if(!a) {
        free(data);
    } else {
        (*data)++;
    }

    if(b) {
        val = 37;
    } else {
        val = *data; /* DANGER, if !a & !b */
    }

    if(a) {
        free(data);
    }

    printf("%i\n", val);
}

int main() {
    refer_free_if_else(true, true); /* OK */
    refer_free_if_else(false, false); /* DANGER */
    refer_free_if_else(false, true); /* OK */

    return 1;
}
