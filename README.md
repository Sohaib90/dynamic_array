# dynamic_array
Implementation of a dynamic array in c 

This repository contains a very basic implementation of a dynamic array in C
The feature implementation that are completed up till now are: 

1. The `DataType_t` enum is implemented to represent the capability of dynamic array to handle multiple data types. For your own data types, you can customize the source code.

2. `array_t` is a `struct type` that represents the dynamic array. It hold the information for the array's `type`, `size`, `occupancy` and the actual `data` of the array.

3. `array_size(DataType_t)` returns the right size of the data type in bytes.

4. `array_create(...)` returns an `array_t` type dynamic array initialized using `malloc()`

5. `array_push(...)` is the crux of the dynamic array implementation. It checks if the `array.size == array.occupied` and proceeds to expand memory in case the array is out of memory to insert a new element. This expansion is performed by calling `realloc()`

6. `array_free()` as the name suggests, deallocates the memory on the heap which was created using `malloc()` in `array_create(...)`

**Note**: Any addition, fixes or bugs are welcomed wholeheartedly. 

## **Usage**
The following code depicts and minimal implementation of a dynamic `int` array using `array_t`

```c
#include "dynamic_array.h"

int main(void){

    array_t int_array = array_create(30, ARR_INT);

    for (int j=0; j<100; j++){
        int value = j; // created just to distinguish between index and value
        array_push(&int_array, j, &value);
        printf("int_array[%d]: %d \n", j, value);
    }

    array_free(&int_array);
    return 0;
}
```

The following snippet shows how to create a dynamic array for `int`, `vec3_t` and `float` types

```c
#include "dynamic_array.h"

int main(void){

    array_t vec3_array = array_create(10, ARR_VEC3);
    array_t int_array = array_create(30, ARR_INT);
    array_t float_array = array_create(2, ARR_FLOAT);

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
```

### **TODO:**

1. Extend dynamic array to delete an element from the array. 