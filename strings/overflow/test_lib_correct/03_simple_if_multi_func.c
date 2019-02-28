#include "string_overflow.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static char* choose_string(char* string1, char* string2, bool condition) {
    if(condition) {
        return string1;
    } else {
        return string2;
    }
}

static void overwrite_char(char* string, int pos1, int pos2, char replacement, bool condition) {
    if(condition) {
        string[pos1] = replacement;
    } else {
        string[pos2] = replacement;
    }
}

void string_overflow_if_else_multi(bool a, bool b) {
    char long_string[] = "this is a long string";
    char short_string[] = "short string";
    char* to_print;

    if(!a & !b) {
        return;
    }

    to_print = choose_string(long_string, short_string, a);

    overwrite_char(to_print, 11, 13, '?', b); /* DANGER, if !a & !b */

    printf("%s\n", to_print);
}

