#include <stdio.h>
#include "nullpointer.h"

void nullpointer_for_array(int x) {
    int p[20];
    int* ptr = p;
    int val = 0, i = 0;


    for(i = 0; i < 20; i++) {
        p[i] = 0;
    }
    p[x] = 1;

    for(i = 0; i < 20; i++) {
        if(p[i] == 1) {
            ptr = 0;
        } else {
            val = *ptr; /* DANGER: x < 19 */
        }
    }

    printf("%i\n", val);
}

int main() {
    nullpointer_for_array(19);

    return 1;
}
