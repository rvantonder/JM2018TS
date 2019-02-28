#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[3] = {1, 2, 3};
    int* ptr;

    ptr = arr;

    printf("%i\n", *ptr + arr[2]);

    return 1;
}
