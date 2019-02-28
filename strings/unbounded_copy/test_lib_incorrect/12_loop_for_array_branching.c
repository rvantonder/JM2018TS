#include <stdio.h>
#include <string.h>
#include "string_copy.h"

void string_copy_for_array(int x) {
    int p[20];
    char long_string[22];
    char short_string[13];
    char* to_print = long_string;
    int i = 0;

    if(x < 0 || x > 19) {
        return;
    }


    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            to_print = short_string;
        } else {
            strcpy(to_print, "this is a long string"); /* DANGER: x < 19 */
        }
    }

    printf("%s\n", to_print);
}

