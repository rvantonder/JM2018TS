#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_free.h"

void double_free_if_else(bool a, bool b) {
    int* data;


    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    if(!a) {
        free(data);
    }

    if(b) {
        if(a) {
            free(data);
        }
    } else {
        free(data); /* DANGER, if !a & !b */
    }
}

int main() {
    double_free_if_else(true, true); /* OK */
    double_free_if_else(false, false); /* DANGER */
    double_free_if_else(false, true); /* OK */

    return 1;
}
