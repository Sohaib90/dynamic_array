#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdio.h>
#include <stdlib.h>

#define array_push(array, value, index)                                  \
    if (capacity == ArrSize){                                            \
        ArrSize *= 2;                                                    \
        array =                                                          \
        realloc(array, ArrSize * sizeof(*(array)));                      \
        if (realloc == NULL) {printf("Reallocation failed\n"); exit(1);} \
        array[index] = value;                                            \
        capacity++;                                                      \
    }                                                                    \
    else {                                                               \
    array[index] = value;                                                \
        capacity++;                                                      \
    }                                                                    \

extern int* array;
extern size_t ArrSize;
extern size_t capacity;

size_t array_length();
size_t array_occupied();
void array_free(void* array);


#endif