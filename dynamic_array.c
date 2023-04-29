#include "dynamic_array.h"

int* array;
size_t ArrSize = 0;
size_t capacity = 0;

void* init_array(void* array, size_t size){
    ArrSize = size;
    array = malloc(ArrSize * sizeof(array));
    if (array == NULL) {printf("array memory allocation failure"); return NULL;}
    return array;
}

size_t array_length() {return ArrSize;}
size_t array_occupied() {return capacity;}
void array_free(void* array) {free(array);}

int main(void){

array = init_array(array, 10);
for (int i = 0; i < 30; i++){
    array_push(array, i, i);
    printf("%d\n", array[i]);
}

printf("The size of the array is %ld\n", array_length());
printf("Occupied num of elements in array %ld\n", array_occupied());



free(array);

return 0;
}