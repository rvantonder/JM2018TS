#include "nullpointer.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef s_NULLPOINTER_REFCOUNT
#define s_NULLPOINTER_REFCOUNT
NRefCont* null_ref_cont_new() {
    NRefCont* new_cont;

    new_cont = malloc(sizeof(NRefCont));

    if(new_cont) {
        new_cont->refc = 1;
        new_cont->p_data = 0;
    }
    return new_cont;
}

void null_ref(NRefCont* cont) {
    if(cont) {
        cont->refc++;
    }
}
void null_unref(NRefCont* cont) {
    if(cont->refc <= 1) {
        if(cont->p_data) {
            cont->p_data = 0;
        }
    } else {
        cont->refc--;
    }
}

void* null_ref_cont_get_pointer(NRefCont* cont) {
    return cont->p_data;
}
void null_ref_cont_set_pointer(NRefCont* cont, void* p) {
    cont->p_data = p;
}
#endif //s_NULLPOINTER_REFCOUNT

int main() {
    NRefCont* cont;
    int arr[3] = {1, 2, 3};
    int val;

    cont = null_ref_cont_new();
    if(!cont) {
        return 1;
    }
    null_ref_cont_set_pointer(cont, arr);

    null_ref(cont);
    null_ref(cont);
    null_unref(cont);
    null_unref(cont);
    null_unref(cont);

    val = *((int*) null_ref_cont_get_pointer(cont));

    printf("%i\n", val);

    free(cont);

    return 1;
}
