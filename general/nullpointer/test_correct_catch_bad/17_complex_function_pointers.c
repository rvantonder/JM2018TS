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

void nullpointer_function_pointer(bool a, bool b, void (*f)(void**, void*, void*, bool)) {
    int arr[3] = {1, 2, 3};
    int* ptr;
    int val;

    if(!f || (!a & !b)) {
        return;
    }

    (*f)((void**) &ptr, (void*) arr, 0, a);

    if(b) {
        val = arr[2];
    } else {
        val = ptr[2]; /* DANGER, if !a & !b */
    }

    printf("%i\n", val);
}

int main() {
    nullpointer_function_pointer(true, true, &local_assign_pointer);
    nullpointer_function_pointer(true, false, &local_assign_pointer);
    nullpointer_function_pointer(false, true, &local_assign_pointer);

    return 1;
}
