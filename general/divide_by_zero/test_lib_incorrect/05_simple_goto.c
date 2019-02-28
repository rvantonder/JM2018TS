#include <stdio.h>
#include "divide_by_zero.h"

void divide_zero_goto(int x) {
    int val, i;
    int divisor = 1;


    val = 37 / 3;
    i = 0;

GOTO_LABEL:
    if(i <= x) {
        val += 10 / (divisor + 1);
    } else {
        printf("%i\n", val);
    }

    divisor -= 2;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

