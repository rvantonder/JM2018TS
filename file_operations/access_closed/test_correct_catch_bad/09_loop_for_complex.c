#include <stdio.h>
#include <stdlib.h>
#include "access_closed.h"

void access_closed_for_complex(int x) {
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

    for(;;) {
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
        if(i >= 20) {
            break;
        }
    }

    fclose(file);

    printf("%i\n", val);
}

int main() {
    access_closed_for_complex(10);

    return 1;
}
