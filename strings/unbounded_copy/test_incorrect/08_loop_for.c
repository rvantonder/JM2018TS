#include <stdio.h>
#include <string.h>
#include "string_copy.h"

void string_copy_for(int x) {
    char long_string[22];
    char short_string[13];
    char* to_print = short_string;
    int i;


    for(i = 0; i < 20; i++) {
        if(i > x) {
            strcpy(to_print, "this is a long string"); /* DANGER: x < 10 */
        } else {
            strcpy(to_print, "short string");
        }
        if(i == 10) {
            to_print = long_string;
        }
        printf("val = %s\n", to_print);
    }
}

int main() {
    string_copy_for(9);

    return 1;
}
