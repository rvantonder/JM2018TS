#include "uninit_ptr.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef s_UNINITIALIZED_P_REFCOUNT
#define s_UNINITIALIZED_P_REFCOUNT
void init_uninit_ref_cont(URefCont* cont) {
    cont->refc = 1;
    cont->data_ptr = &(cont->data);
}

URefCont* uninit_ref_cont_new() {
    URefCont* new_cont;

    new_cont = malloc(sizeof(URefCont));

    if(new_cont) {
        init_uninit_ref_cont(new_cont);
    }
    return new_cont;
}

void uninit_ref(URefCont* cont) {
    if(cont) {
        cont->refc++;
    }
}
void uninit_unref(URefCont* cont) {
    if(cont->refc <= 1) {
        cont->data_ptr = &(cont->uninit);
    } else {
        cont->refc--;
    }
}

void* uninit_ref_cont_get_pointer(URefCont* cont) {
    return *(cont->data_ptr);
}
void uninit_ref_cont_set_pointer(URefCont* cont, void* p) {
    cont->data = p;
}
#endif //s_UNINITIALIZED_P_REFCOUNT

