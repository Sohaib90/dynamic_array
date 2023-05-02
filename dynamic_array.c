#include "dynamic_array.h"

size_t array_size(DataType_t type)
{
    size_t array_mem_alloc = 0;
    if (type == ARR_VEC3){
        array_mem_alloc = sizeof(vec3_t);
    } else if (type == ARR_INT){
        array_mem_alloc = sizeof(int);
    } else if (type == ARR_FLOAT){
        array_mem_alloc = sizeof(float);
    }

    return array_mem_alloc;
}

array_t* array_create(size_t size, DataType_t type){
    
    size_t type_mem = array_size(type);
    array_t* array; 
    array->type = type;
    array->size = size;
    array->occupied = 0;
    array->data = malloc(type_mem * size);

    return array;
}

void array_push(array_t* array, size_t index, void* value){
    if (array->size == array->occupied){
        array->size *= 2;
        array->data = realloc(array->data, array->size * array_size(array->type));
        if (array->data == NULL) {printf("array memory reallocation failure"); exit(1);}
    }

    // cast value to appropriate data type
    if (array->type == ARR_VEC3){
        vec3_t* vec = (vec3_t *) value;
        ((vec3_t*)array->data)[index] = *vec;
    } else if (array->type == ARR_INT){
        int* intPtr = (int *) value;
        ((int*)array->data)[index] = *intPtr;
    } else if (array->type == ARR_FLOAT){
        float* val = (float *) value;
        ((float*)array->data)[index] = *val;
    }
    array->occupied++;
}

void array_free(array_t* array) {free(array->data);}