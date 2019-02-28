#include <stdio.h>
#include <stdlib.h>
#include "refer_free.h"

void refer_free_while_continue(int x) {
    int* data;
    int val = 0;
    int i = 0;

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    free(data);

    while(i < 30) {
        if(i == 9) {
            i++;
            continue;
        }
        if(i > x) {
            val += *data; /* Dangerous if x < 10 */
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
        i++;
    }

    free(data);

    printf("%i\n", val);
}

int main() {
    refer_free_while_continue(10);

    return 1;
}
