#include "dynamic_array.h"

array_t array_create(size_t size, DataType_t type){
    size_t array_mem_alloc = 0;
    if (type == ARR_VEC3){
        array_mem_alloc = sizeof(vec3_t) * size;
    } else if (type == ARR_INT){
        array_mem_alloc = sizeof(int) * size;
    } else if (type == ARR_FLOAT){
        array_mem_alloc = sizeof(float) * size;
    }

    array_t array = {
        .type = type,
        .size = size,
        .occupied = 0,
        .data = malloc(array_mem_alloc)
    };
    
    return array;
}

void array_push(array_t array, size_t index, void* value){
    if (array.size == array.occupied){
        array.size *= 2;
        array.data = realloc(array.data, array.size * sizeof(array.type));
        if (array.data == NULL) {printf("array memory reallocation failure"); exit(1);}
    }

    // cast value to appropriate data type
    if (array.type == ARR_VEC3){
        vec3_t* vec = (vec3_t *) value;
        vec3_t in_vec = *vec;
        ((vec3_t*)array.data)[index] = in_vec;
    } else if (array.type == ARR_INT){
        int* intPtr = (int *) value;
        int in_int = *intPtr;
        ((int*)array.data)[index] = in_int;
    } else if (array.type == ARR_FLOAT){
        float* val = (float *) value;
        float in_float = *val;
        ((float*)array.data)[index] = in_float;
    }
    array.occupied++;
}

void array_free(array_t* array) {free(array->data);}