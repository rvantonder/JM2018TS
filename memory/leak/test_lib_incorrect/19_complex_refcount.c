#include "memory_leak.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef s_MEMORY_L_REFCOUNT
#define s_MEMORY_L_REFCOUNT
void mem_leak_cont_init(LRefCont* cont) {
    cont->refc = 1;
    cont->data = 0;
}

LRefCont* mem_leak_cont_new() {
    LRefCont* new_cont;

    new_cont = malloc(sizeof(LRefCont));

    if(new_cont) {
        mem_leak_cont_init(new_cont);
    }
    return new_cont;
}

void mem_leak_cont_ref(LRefCont* cont) {
    if(cont) {
        cont->refc++;
    }
}
void mem_leak_cont_unref(LRefCont* cont) {
    if(cont->refc <= 1) {
        free(cont);
    } else {
        cont->refc--;
    }
}

void* mem_leak_cont_get_pointer(LRefCont* cont) {
    return cont->data;
}
void mem_leak_cont_set_pointer(LRefCont* cont, void* p) {
    cont->data = p;
}
#endif //s_MEMORY_L_REFCOUNT

