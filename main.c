#include <stdio.h>
#include "dynamic_array.h"

/*

Minimal example on how to create and use a dynamic array

*/

int main(void){

    array_t vec3_array = array_create(10, ARR_VEC3);
    array_t int_array = array_create(30, ARR_INT);

    for (int i=0; i<30; i++){
        vec3_t temp = {i, i+1, i+2};
        array_push(&vec3_array, i, &temp);
        printf("vec3_array[%d]: (%d, %d, %d) \n", i, temp.a, temp.b, temp.c);
    }

    for (int j=0; j<100; j++){
        int value = j;
        array_push(&int_array, j, &value);
        printf("int_array[%d]: %d \n", j, value);
    }

    array_free(&vec3_array);
    array_free(&int_array);
    return 0;
}