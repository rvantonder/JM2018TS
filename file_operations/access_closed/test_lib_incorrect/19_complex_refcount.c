#include "access_closed.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef s_FILES_AC_REFCOUNT
#define s_FILES_AC_REFCOUNT
void access_closed_cont_init(FileCont* cont) {
    cont->refc = 1;
    cont->file = 0;
}

FileCont* access_closed_cont_new() {
    FileCont* new_cont;

    new_cont = malloc(sizeof(FileCont));

    if(new_cont) {
        access_closed_cont_init(new_cont);
    }
    return new_cont;
}

void access_closed_cont_ref(FileCont* cont) {
    if(cont) {
        cont->refc++;
    }
}
void access_closed_cont_unref(FileCont* cont) {
    if(cont->refc <= 1) {
        if(cont->file) fclose(cont->file);
    } else {
        cont->refc--;
    }
}

FILE* access_closed_cont_get_file(FileCont* cont) {
    return cont->file;
}
void access_closed_cont_set_file(FileCont* cont, FILE* file) {
    cont->file = file;
}
#endif //s_FILES_AC_REFCOUNT

