#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_overflow.h"

static char long_string[22] = "";
static char short_string[13] = "";

static void select_string(char** dest, bool condition) {
    if(condition) {
        *dest = long_string;
    } else {
        *dest = short_string;
    }
}

void string_overflow_function_pointer(bool a, bool b, void (*f)(char**, bool)) {
    char* to_print;


    (*f)(&to_print, a);

    if(b) {
        to_print[11] = '?';
    } else {
        to_print[13] = '?'; /* DANGER, if !a & !b */
    }

    printf("%s\n", to_print);
}

int main() {
    string_overflow_function_pointer(true, true, &select_string); /* OK */
    string_overflow_function_pointer(false, false, &select_string); /* DANGER */
    string_overflow_function_pointer(false, true, &select_string); /* OK */

    return 1;
}
