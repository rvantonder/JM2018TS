#include <stdio.h>
#include <string.h>
#include "string_copy.h"

void string_copy_if_else_int1(int x, int y) {
    char long_string[22];
    char short_string[13];
    char* to_print;

    if(x <= 10 && x >= y) {
        return;
    }

    if(x < y) {
        to_print = long_string;
    } else {
        to_print = short_string;
    }

    if(x > 10) {
        strcpy(to_print, "short string");
    } else {
        strcpy(to_print, "this is a long string"); /* DANGER if x <= 10 & x >= y */
    }

    printf("%s\n", to_print);
}

