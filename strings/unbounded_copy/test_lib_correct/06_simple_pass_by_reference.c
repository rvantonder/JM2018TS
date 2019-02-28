#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_copy.h"

static void choose_string(char** destination, char* string1, char* string2, bool condition) {
    if(condition) {
        *destination = string1;
    } else {
        *destination = string2;
    }
}

void string_copy_pass_by_reference(bool a, bool b) {
    char long_string[22];
    char short_string[13];
    char* to_print;

    if(!a & !b) {
        return;
    }

    choose_string(&to_print, long_string, short_string, a);

    if(b) {
        strcpy(to_print, "short string");
    } else {
        strcpy(to_print, "this is a long string");
    }

    printf("%s\n", to_print);
}

