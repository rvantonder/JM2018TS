#include <stdio.h>
#include <stdlib.h>
#include "double_close.h"

void double_close_do_while_continue(int x) {
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
            fclose(file);
            file = fopen("file1.txt","r");
            if(!file) {
                return;
            }
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

