#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file;

    file = fopen("file.txt","r");

    if(!file) {
        return;
    }

    printf("%i\n", (int) fgetc(file));


    return 1;
}
