#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_copy.h"

static char long_string[22] = "";
static char short_string[13] = "";

static void select_string(char** dest, bool condition) {
    if(condition) {
        *dest = long_string;
    } else {
        *dest = short_string;
    }
}

void string_copy_function_pointer(bool a, bool b, void (*f)(char**, bool)) {
    char* to_print;


    (*f)(&to_print, a);

    if(b) {
        strcpy(to_print, "short string");
    } else {
        strcpy(to_print, "this is a long string"); /* DANGER, if !a & !b */
    }

    printf("%s\n", to_print);
}

int main() {
    string_copy_function_pointer(true, true, &select_string); /* OK */
    string_copy_function_pointer(false, false, &select_string); /* DANGER */
    string_copy_function_pointer(false, true, &select_string); /* OK */

    return 1;
}
