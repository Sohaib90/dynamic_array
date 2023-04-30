# dynamic_array
Implementation of a dynamic array in c 

This repository contains a naive implementation of a dynamic array in C
The feature implementation that are completed up till now are: 

1. We have two macros `init_array(array, size)` for generality of array initialization and `array_push(array, index, value)` for pushing elements into the array. `array_push(array, index, value)` has also been implemented keeping generality in mind. (TODO: testing with different `types` for robustness and proof of concept.)
2. array_occupied(): returns the number of indexes occupied in the array
3. array_length(): returns the length of the array
4. array_free(void * array): releases the memory allocated to the dynamic array 
   (important to use it after done using the dynamic array) 
