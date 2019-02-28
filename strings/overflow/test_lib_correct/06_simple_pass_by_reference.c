#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_overflow.h"

static void choose_string(char** destination, char* string1, char* string2, bool condition) {
    if(condition) {
        *destination = string1;
    } else {
        *destination = string2;
    }
}

void string_overflow_pass_by_reference(bool a, bool b) {
    char long_string[22] = "this is a long string";
    char short_string[13] = "short string";
    char* to_print;

    if(!a & !b) {
        return;
    }

    choose_string(&to_print, long_string, short_string, a);

    if(b) {
        to_print[11] = '?';
    } else {
        to_print[13] = '?'; /* DANGER if !a */
    }

    printf("%s\n", to_print);
}

