#include <stdio.h>
#include <stdlib.h>
#include "zero_alloc.h"

void zero_alloc_while_continue(int x) {
    int* data;
    size_t size = 0;
    int i = 0;

    if(x < 10) {
        return;
    }

    while(i < 30) {
        if(i == 9) {
            i++;
            continue;
        }
        if(i > x) {
            data = malloc(size); /* DANGER: x < 10 */
        } else {
            data = malloc(size + sizeof(int));
        }

        if(data) {
            *data = i;
            printf("%i\n", *data);
            free(data);
        }

        if(i == 10) {
            size += sizeof(int);
        }
        i++;
    }
}

int main() {
    zero_alloc_while_continue(10);

    return 1;
}
