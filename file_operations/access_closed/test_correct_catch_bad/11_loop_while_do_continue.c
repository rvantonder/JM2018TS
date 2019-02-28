#include <stdio.h>
#include <stdlib.h>
#include "access_closed.h"

void access_closed_do_while_continue(int x) {
    FILE* file;
    int val = 0;
    int i = 0;

    if(x < 10) {
        return;
    }

    file = fopen("file1.txt","r");

    if(!file) {
        return;
    }

    val = (int) fgetc(file);

    fclose(file);

    do {
        if(i == 8) {
            i++;
            continue;
        }
        if(i > x) {
            val += (int) fgetc(file);
        } else {
            val += 24;
        }
        if(i == 10) {
            file = fopen("file2.txt","r");
            if(!file) {
                return;
            }
        }
        i++;
        if(i < 20) {
            continue;
        }
    } while(i < 30);

    fclose(file);

    printf("%i\n", val);
}

int main() {
    access_closed_do_while_continue(10);

    return 1;
}
