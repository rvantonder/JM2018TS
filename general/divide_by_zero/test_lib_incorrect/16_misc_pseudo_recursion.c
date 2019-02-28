#include <stdio.h>
#include "divide_by_zero.h"

int divide_zero_pseudo_rec1(int x, int y, int i, int div1, int div2) {
    int divisor;

    if(i > 0) {
        return 37;
    }

    if(x < y) {
        div2 = div1;
    }

    return divide_zero_pseudo_rec2(x, y, 1, div1, div2);
}

int divide_zero_pseudo_rec2(int x, int y, int i, int div1, int div2) {
    if(i <= 0) {
        return 10 / div1 + divide_zero_pseudo_rec1(x, y, 1, div1, div2);
    }

    if(x > 10) {
        divisor = div1;
    } else {
        divisor = div2;
    }

    return 100 / divisor;
}

