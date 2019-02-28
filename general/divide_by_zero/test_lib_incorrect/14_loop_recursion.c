#include <stdio.h>
#include "divide_by_zero.h"

int divide_zero_rec(int x, int i, int div1, int div2) {
    int divisor;

    if(i <= 1 || div1 == 0) {
        return 0;
    }


    if(i < x) {
        divisor = div2;
    } else {
        divisor = div1;
    }
    if(i == 10) {
        div2 = div1;
    }
    return divide_zero_rec(x, i-1, div1, div2) + 100 / divisor;
}

