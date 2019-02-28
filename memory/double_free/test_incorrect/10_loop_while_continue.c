#include <stdio.h>
#include <stdlib.h>
#include "double_free.h"

void double_free_while_continue(int x) {
    int* data;
    bool is_freed;
    int n_freed = 30;
    int i = 0;

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    free(data);
    is_freed = true;

    while(i < 30) {
        if(i == 9) {
            i++;
            continue;
        }
        if(i == 10) {
            data = malloc(5*sizeof(int));
            if(!data) {
                return;
            }
            is_freed = false;
        }
        if(i > x && is_freed) { /* should be !is_freed */
            free(data); /* DANGER: x < 10 */
            data = malloc(5*sizeof(int));
            if(!data) {
                return;
            }
            is_freed = false;
        } else {
            n_freed--;
        }
        i++;
    }

    if(!is_freed) {
        free(data);
        n_freed--;
    }

    printf("Times freed = %i", n_freed);
}

int main() {
    double_free_while_continue(9);

    return 1;
}
