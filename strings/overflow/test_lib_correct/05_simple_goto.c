#include <stdio.h>
#include <string.h>
#include "string_overflow.h"

void string_overflow_goto(int x) {
    char short_string[] = "Short string";
    char to_print_text[] = "Default string content";
    char* to_print = to_print_text;
    int i;

    if(x > 0) {
        return;
    }

    i = 0;

GOTO_LABEL:
    if(i <= x) {
        to_print[15] = '?';
    } else {
        printf("%s\n", to_print);
    }

    to_print = short_string;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

