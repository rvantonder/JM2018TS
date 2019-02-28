#include <stdio.h>
#include <stdlib.h>
#include "zero_alloc.h"

void zero_alloc_for_array(int x) {
    int* data;
    size_t size;
    int p[20];
    int i;


    size = sizeof(int);

    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            size -= sizeof(int);
        } else {
            data = malloc(size); /* DANGER: x < 19 */
            if(!data) {
                break;
            }
            *data = i;
            printf("%i\n", *data);
            free(data);
        }
    }
}

int main() {
    zero_alloc_for_array(10);

    return 1;
}
