#include <stdio.h>
#include <limits.h>
#include "integer_overflow.h"

void integer_overflow_goto(int x) {
    int val = INT_MAX / 3 - 1;
    int i;


    i = 0;

GOTO_LABEL:
    if(i <= x) {
        printf("%i\n", val * 3);
    } else {
        printf("%i\n", val);
    }

    val = val * 2;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

int main() {
    integer_overflow_goto(0);

    return 1;
}
