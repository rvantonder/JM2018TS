#include <stdio.h>
#include <stdlib.h>

int main() {
    int* data;

    data = malloc(sizeof(int));


    if(!data) {
        return -1;
    }

    *data = 37;

    printf("%i\n", *data);

    free(data);

    return 1;
}
