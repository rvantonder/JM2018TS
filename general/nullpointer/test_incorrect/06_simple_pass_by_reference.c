#include <stdio.h>
#include <stdbool.h>
#include "nullpointer.h"

static void local_assign_pointer(void** dest, void* source1, void* source2, bool condition) {
    if(condition) {
        *dest = source1;
    } else {
        *dest = source2;
    }
}

void nullpointer_pass_by_reference(bool a, bool b) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val;


    local_assign_pointer((void**) &ptr, (void*) arr, 0, a);

    if(b) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    nullpointer_pass_by_reference(true, true); /* OK */
    nullpointer_pass_by_reference(false, false); /* DANGER */
    nullpointer_pass_by_reference(false, true); /* OK */

    return 1;
}
