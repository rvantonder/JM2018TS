#include <stdio.h>
#include <stdlib.h>
#include "double_close.h"

void double_close_for_complex(int x) {
    FILE* file;
    int val = 0;
    int i = 0;


    file = fopen("file1.txt","r");

    if(!file) {
        return;
    }

    val = (int) fgetc(file);

    fclose(file);

    for(;;) {
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
        if(i >= 20) {
            break;
        }
    }

    fclose(file);

    printf("%i\n", val);
}

int main() {
    double_close_for_complex(10);

    return 1;
}
