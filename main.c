#include <stdio.h>
#include "dynamic_array.h"

/*

Minimal example on how to create and use a dynamic array

*/

int main(void){

    array_t vec3_array = array_create(10, ARR_VEC3);
    array_t int_array = array_create(30, ARR_INT);
    array_t float_array = array_create(2, ARR_FLOAT);

    for (int i=0; i<30; i++){
        vec3 temp = {i, i+1, i+2};
        array_push(&vec3_array, i, &temp);
        printf("vec3_array[%d]: (%f, %f, %f) \n", i, temp.x, temp.y, temp.z);
    }

    for (int j=0; j<100; j++){
        int value = j;
        array_push(&int_array, j, &value);
        printf("int_array[%d]: %d \n", j, value);
    }

    for (int k=0; k<100; k++){
        float value = k + 0.1f;
        array_push(&float_array, k, &value);
        printf("float_array[%d]: %f \n", k, value);
    }

    array_free(&vec3_array);
    array_free(&int_array);
    array_free(&float_array);
    return 0;
}