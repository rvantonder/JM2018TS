#include <stdio.h>
#include <stdlib.h>

int main() {
    int* data;
    int x;

    x = 1;

    data = malloc(x * sizeof(int));

    if(!data) {
        return -1;
    }

    *data = x;

    printf("%i\n", *data);

    free(data);

    return 1;
}
