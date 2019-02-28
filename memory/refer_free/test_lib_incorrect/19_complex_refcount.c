#include "refer_free.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef s_MEMORY_RF_REFCOUNT
#define s_MEMORY_RF_REFCOUNT
void refer_free_cont_init(RRefCont* cont) {
    cont->refc = 1;
    cont->data = 0;
}

RRefCont* refer_free_cont_new() {
    RRefCont* new_cont;

    new_cont = malloc(sizeof(RRefCont));

    if(new_cont) {
        refer_free_cont_init(new_cont);
    }
    return new_cont;
}

void refer_free_cont_ref(RRefCont* cont) {
    if(cont) {
        cont->refc++;
    }
}
void refer_free_cont_unref(RRefCont* cont) {
    if(cont->refc <= 1) {
        free(cont);
    } else {
        cont->refc--;
    }
}

void* refer_free_cont_get_pointer(RRefCont* cont) {
    return cont->data;
}
void refer_free_cont_set_pointer(RRefCont* cont, void* p) {
    cont->data = p;
}
#endif //s_MEMORY_RF_REFCOUNT

