#include <stdio.h>
#include <string.h>
#include "string_copy.h"

void string_copy_goto(int x) {
    char short_string[] = "Short string";
    char* to_print = "Default string content";
    int i;

    if(x > 0) {
        return;
    }

    i = 0;

GOTO_LABEL:
    if(i <= x) {
        strcpy(to_print, "this is a long string");
    } else {
        printf("%s\n", to_print);
    }

    to_print = short_string;

    if(i == 0) {
        i++;
        goto GOTO_LABEL;
    }
}

int main() {
    string_copy_goto(0);

    return 1;
}
