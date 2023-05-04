#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
    
typedef struct 
{
    float x, y, z;

} vec3;

typedef struct 
{
    float x, y;
} vec2;

typedef struct 
{
    vec2 points[3];
} triangle;

typedef enum {
    ARR_INT,
    ARR_VEC3,
    ARR_VEC2,
    ARR_FLOAT,
    ARR_TRIANGLE,
} DataType_t;

typedef struct {
    DataType_t type;
    size_t size;
    size_t occupied;
    void* data;
} array_t;

size_t array_size(DataType_t type);
array_t array_create(size_t size, DataType_t type);
void array_push(array_t* array, size_t index, void* value);
void array_free(array_t* array);

#endif