#include <stdio.h>
#include <string.h>
#include "string_copy.h"

void string_copy_while_continue(int x) {
    char long_string[22];
    char short_string[13];
    char* to_print = short_string;
    int i = 0;


    while(i < 30) {
        if(i > x) {
            strcpy(to_print, "this is a long string"); /* DANGER: x < 10 */
        } else {
            strcpy(to_print, "short string");
        }
        if(i == 10) {
            to_print = long_string;
        }
        printf("val = %s\n", to_print);
        i++;
        if(i < 20) {
            continue;
        }
    }
}

int main() {
    string_copy_while_continue(10);

    return 1;
}
