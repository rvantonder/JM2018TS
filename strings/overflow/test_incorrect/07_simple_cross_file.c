#include "string_overflow.h"
#include "common.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void string_overflow_cross_file(bool a, bool b) {
    char long_string[22] = "this is a long string";
    char short_string[13] = "short string";
    char* to_print;


    to_print = (char*) choose_pointer((void*) long_string, (void*) short_string, a);

    if(b) {
        to_print[11] = '?';
    } else {
        to_print[13] = '?'; /* DANGER if !a */
    }

    printf("%s\n", to_print);
}

int main() {
    string_overflow_cross_file(true, true); /* OK */
    string_overflow_cross_file(false, false); /* DANGER */
    string_overflow_cross_file(false, true); /* OK */
    return 1;
}
