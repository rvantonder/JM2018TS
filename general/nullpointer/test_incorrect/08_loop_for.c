#include <stdio.h>
#include "nullpointer.h"

void nullpointer_for(int x) {
    int arr[3] = {1, 2, 3};
    int* ptr = 0;
    int val = 0;
    int i;


    for(i = 0; i < 20; i++) {
        if(i > x) {
            val += *ptr; /* DANGER: x < 10 */
        } else {
            val += arr[0];
        }
        if(i == 10) {
            ptr = arr;
            val += *ptr;
        }
    }

    printf("val = %i", val);
}

int main() {
    nullpointer_for(9);

    return 1;
}
