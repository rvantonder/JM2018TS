#include <stdio.h>
#include <string.h>
#include "string_copy.h"

static char long_string[22] = "";
static char short_string[13] = "";

void string_copy_pseudo_rec1(int x, int y, int i, char* to_print) {


    if(i > 0) {
        return;
    }

    if(x > 10) {
        if(!to_print) {
            to_print = long_string;
        }
    } else {
        to_print = short_string;
    }

    string_copy_pseudo_rec2(x, y, 1,to_print);
}

void string_copy_pseudo_rec2(int x, int y, int i, char* to_print) {
    if(i > 0) {
        if(x < y) {
            strcpy(to_print, "short string");
        } else {
            strcpy(to_print, "this is a long string");
        }
        printf("%s\n", to_print);
    } else {
        string_copy_pseudo_rec1(x, y, 1, to_print);
    }
}

int main() {
    string_copy_pseudo_rec1(10, 10, 0, 0);

    return 1;
}
