#include <stdio.h>
#include <string.h>
#include "string_copy.h"

static char long_string[22] = "";
static char short_string[13] = "";

void string_copy_rec_decr(int x, int i, char* to_print) {
    if(i <= 1) {
        printf("%s\n", to_print);
        return;
    }

    string_copy_rec_multi(x, i-1, to_print);
}

void string_copy_rec_multi(int x, int i, char* to_print) {

    if(i > x) {
        strcpy(to_print, "this is a long string");
    } else {
        strcpy(to_print, "short string");
    }

    if(i == 10) {
        to_print = short_string;
    }
    string_copy_rec_decr(x, i, to_print);
}



int main() {
    string_copy_rec_multi(10, 20, long_string);

    return 1;
}
