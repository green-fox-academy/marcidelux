#include <stdio.h>
#include <stdlib.h>
int* resize(int* old_array, int old_size, int new_size);
int* range(int first, int to, int step);
void printArray(int* pointer, int size);
// TODO:
/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int main() {
    int* first_array;
    int* second_array;

    int start = 0;
    int to = 10;
    int step = 2;
    int new_size = 10;
    int size = (to - start) / step;

    first_array = range(start, to, step);
    first_array = resize(first_array, size, new_size);
    printArray(first_array, new_size);

  return 0;
}

int* resize(int* old_array, int old_size, int new_size){
    int* new_array;
    new_array = (int*)realloc(old_array, new_size);

    if(old_size < new_size){
            for(int i = 0; i < (new_size-old_size); i++ ) {
                new_array[old_size+i] = 0;
            }
    }

    return new_array;
}

int* range(int first, int to, int step){
    int* range_array;
    int n = (to - first) / step;

    range_array = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        range_array[i] = first + i * step;
    }

    return range_array;
}

void printArray(int* pointer, int size){
    for(int i = 0; i < size; i++) {
        printf("Number%d: %d\n",(i+1),pointer[i]);
    }
}
