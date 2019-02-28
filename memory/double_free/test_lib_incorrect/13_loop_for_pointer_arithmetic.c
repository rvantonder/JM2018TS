#include <stdlib.h>
#include <stdio.h>
#include "double_free.h"

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

void double_free_for_pointer(int x) {
    int* pointers[10];


    initialize_array(pointers, 10);
    free_array(pointers, 10);
    initialize_array(pointers, x);
    free_array(pointers, 10);
}

