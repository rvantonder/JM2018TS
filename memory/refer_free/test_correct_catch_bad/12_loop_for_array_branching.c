#include <stdio.h>
#include <stdlib.h>
#include "refer_free.h"

void refer_free_for_array(int x) {
    int* data;
    int p[20];
    int val = 0;
    int i;

    if(x != 19) {
        return;
    }

    data = malloc(sizeof(int));

    if(!data) {
        return;
    }

    *data = 27;

    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            free(data);
        } else {
            val += *data; /* DANGER: x < 19 */
            *data = i;
        }
    }

    printf("%i\n", val);
}

int main() {
    refer_free_for_array(19);

    return 1;
}
