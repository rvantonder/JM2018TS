#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_overflow.h"

void string_overflow_if_else(bool a, bool b) {
    char long_string[] = "this is a long string";
    char short_string[] = "short string";
    char* to_print;


    if(a) {
        to_print = long_string;
    } else {
        to_print = short_string;
    }

    if(b) {
        to_print[11] = '?';
    } else {
        to_print[13] = '?';
    }

    printf("%s\n", to_print);
}

