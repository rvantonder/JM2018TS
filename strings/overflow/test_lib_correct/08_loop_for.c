#include <stdio.h>
#include <string.h>
#include "string_overflow.h"

void string_overflow_for(int x) {
    char long_string[22] = "this is a long string";
    char short_string[5] = "1234";
    char* to_print = short_string;
    int i;

    if(x < 10) {
        return;
    }

    for(i = 0; i < 20; i++) {
        if(i > x) {
             to_print[i] = '?';  /* DANGER: x < 10 */
        } else {
             to_print[3] = '?';
        }
        if(i == 10) {
            to_print = long_string;
        }
        printf("val = %s\n", to_print);
    }
}

