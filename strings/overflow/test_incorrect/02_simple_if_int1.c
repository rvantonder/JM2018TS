#include <stdio.h>
#include <string.h>
#include "string_overflow.h"

void string_overflow_if_else_int1(int x, int y) {
    char long_string[] = "this is a long string";
    char short_string[] = "short string";
    char* to_print;


    if(x < y) {
        to_print = long_string;
    } else {
        to_print = short_string;
    }

    if(x > 10) {
        to_print[11] = '?';
    } else {
        to_print[13] = '?'; /* DANGER if x <= 10 & x >= y */
    }

    printf("%s\n", to_print);
}

int main() {
    string_overflow_if_else_int1(9, 10); /* OK */
    string_overflow_if_else_int1(10, 10); /* DANGER */
    string_overflow_if_else_int1(11, 10); /* OK */

    return 1;
}
