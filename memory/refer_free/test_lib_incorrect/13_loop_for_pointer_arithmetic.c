#include <stdlib.h>
#include <stdio.h>
#include "refer_free.h"

static void initialize_array(int* ptr_arr[], int length) {
    int i;

    for(i = 0; i < length; i++) {
        ptr_arr[i] = malloc(sizeof(int));
        if(ptr_arr[i]) *ptr_arr[i] = i;
    }
}

static void free_array(int* ptr_arr[], int length) {
    int i;

    for(i = 0; i < length; i++) {
        if(ptr_arr[i]) free(ptr_arr[i]);
    }
}

void refer_free_for_pointer(int x) {
    int* pointers[10];
    int** ptr;
    int source[10];
    int val = 0, i;


    initialize_array(pointers, 10);
    free_array(pointers, 10);
    initialize_array(pointers, x);
    ptr = pointers;
    for(int i = 0; i < 10; i++, ptr++) {
        val += **ptr;
    }

    free_array(pointers, x);
    printf("%i\n", val);
}

