#include <stdio.h>
#include <stdlib.h>

int main() {
    int* data;
    int x = 33;

    data = malloc(5 * sizeof(int));

    if(!data) {
        return -1;
    }

    *data = x;

    printf("%i\n", *data);


    return 1;
}
