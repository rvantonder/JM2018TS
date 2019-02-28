#include <stdio.h>
#include "divide_by_zero.h"

void divide_zero_while_continue(int x) {
    int divisor = 2;
    int val = 0, i = 0;


    while(i < 30) {
        if(i > x) {
            val += 10 / (divisor - 2); /* DANGER: x < 10 */
        } else {
            val += 10 / (divisor + 2);
        }
        if(i == 10) {
            divisor = 4;
            val += 10 / divisor;
        }
        i++;
        if(i < 20) {
            continue;
        }
    }

    printf("val = %i", val);
}

int main() {
    divide_zero_while_continue(10);

    return 1;
}
