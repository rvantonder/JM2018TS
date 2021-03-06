#include "string_overflow.h"
#include <string.h>
#include <stdio.h>

void string_overflow_switch(int x, int y) {
    char long_string[22] = "this is a long string";
    char short_string[13] = "short string";
    char* to_print;


    if(x < y) {
        to_print = long_string;
    } else {
        to_print = short_string;
    }

    switch (x) {
        case 5: {
            to_print[13] = '?'; /* DANGER: x >= y */
            break;
        }
        case 7: {
            to_print[11] = '?';
            break;
        }
        case 10: {
            to_print[15] = '?'; /* DANGER: x >= y */
            break;
        }
        case 12: {
            to_print[8] = '?';
            break;
        }
        default: {
            to_print[0] = '?';
            break;
        }
    };

    printf("%s\n", to_print);
}

int main() {
    string_overflow_switch(5, 10); /* OK */
    string_overflow_switch(10, 10); /* DANGER */
    string_overflow_switch(11, 10); /* OK */
    string_overflow_switch(7, 5); /* OK */

    return 1;
}
