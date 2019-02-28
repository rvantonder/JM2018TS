#include <stdio.h>
#include "nullpointer.h"

void nullpointer_goto(int x) {
    int arr[3] = {1, 2, 3};
    int* ptr = arr;
    int val, i;


    val = *(ptr+1);
    i = 0;

GOTO_LABEL:
    if(i <= x) {
        val += *ptr;
    } else {
        printf("%i\n", val);
    }

    ptr = 0;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

int main() {
    nullpointer_goto(0);

    return 1;
}
