#include "memory_leak.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void mem_leak_cross_file(bool a, bool b) {
    int val;
    int* data;

    data = malloc(5*sizeof(int));

    if(!data) {
        return;
    }

    conditional_free((void*) data, !a, 0);

    if(b & a) {
        val = *data;
        free(data);
    } else {
        val = 678;
    }

    printf("%i\n", val);
}

int main() {
    mem_leak_cross_file(true, true); /* OK */
    mem_leak_cross_file(false, false); /* DANGER */
    mem_leak_cross_file(false, true); /* OK */
    return 1;
}
