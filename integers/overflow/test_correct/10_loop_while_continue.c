#include <stdio.h>
#include <limits.h>
#include "integer_overflow.h"

void integer_overflow_while_continue(int x) {
    int val = INT_MAX - 20;
    int i = 0;


    while(i < 30) {
        if(i > x) {
             printf("%i\n", val * 3); /* DANGER: x < 10 */
        } else {
             printf("%i\n", val * 2);
        }
        if(i == 10) {
            val = INT_MAX / 3 - 1;
        }
        i++;
        if(i < 20) {
            continue;
        }
    }
}

int main() {
    integer_overflow_while_continue(10);

    return 1;
}
