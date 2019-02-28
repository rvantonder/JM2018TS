#include "string_copy.h"
#include "common.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void string_copy_cross_file(bool a, bool b) {
    char long_string[22];
    char short_string[13];
    char* to_print;


    to_print = (char*) choose_pointer((void*) long_string, (void*) short_string, a);

    if(b) {
        strcpy(to_print, "short string");
    } else {
        strcpy(to_print, "this is a long string");
    }

    printf("%s\n", to_print);
}

