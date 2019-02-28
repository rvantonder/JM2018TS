#include "string_copy.h"
#include <string.h>
#include <stdio.h>

void string_copy_switch(int x, int y) {
    char long_string[22];
    char short_string[13];
    char long_string_input[] = "this is a long string";
    char short_string_input[] = "short string";
    char* to_print;


    if(x < y) {
        to_print = long_string;
    } else {
        to_print = short_string;
    }

    switch (x) {
        case 5: {
            strcpy(to_print, long_string_input); /* DANGER: x >= y */
            break;
        }
        case 7: {
            strcpy(to_print, short_string_input);
            break;
        }
        case 10: {
            strcpy(to_print, long_string_input); /* DANGER: x >= y */
            break;
        }
        case 12: {
            strcpy(to_print, short_string_input);
            break;
        }
        default: {
            strcpy(to_print, short_string_input);
            break;
        }
    };

    printf("%s\n", to_print);
}

