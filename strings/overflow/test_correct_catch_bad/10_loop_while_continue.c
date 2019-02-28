#include <stdio.h>
#include <string.h>
#include "string_overflow.h"

void string_overflow_while_continue(int x) {
    char long_string[22] = "this is a long string";
    char short_string[13] = "short string";
    char* to_print = short_string;
    int i = 0;

    if(x < 10) {
        return;
    }

    while(i < 30) {
        if(i > x) {
             to_print[13] = '?';  /* DANGER: x < 10 */
        } else {
             to_print[11] = '?';
        }
        if(i == 10) {
            to_print = long_string;
        }
        printf("val = %s\n", to_print);
        i++;
        if(i < 20) {
            continue;
        }
    }
}

int main() {
    string_overflow_while_continue(10);

    return 1;
}
