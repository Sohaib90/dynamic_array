#include "dynamic_array.h"

vec3_t* array;
size_t ArrSize = 0;
size_t capacity = 0;

size_t array_length() {return ArrSize;}
size_t array_occupied() {return capacity;}
void array_free(void* array) {free(array);}

int main(void){

    init_array(array, 10);
    for (int i = 0; i < 2048; i++){
        vec3_t temp_vec = {i, i*2, i*3};
        array_push(array, temp_vec, i);
        printf("vec[%d]: (%d, %d, %d)\n", i, array[i].a, array[i].b, array[i].c);
        // printf("The value is %d\n", array[i]);
    }

    printf("The size of the array is %ld\n", array_length());
    printf("Occupied num of elements in array %ld\n", array_occupied());

    free(array);
    return 0;
}