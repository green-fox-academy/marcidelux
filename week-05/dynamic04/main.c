#include <stdio.h>
#include <stdlib.h>
int* resize(int* old_array, int old_size, int new_size);
void printArray(int* pointer, int size);
// TODO:
/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int main() {

    int len1 = 5;
    int newlen = 10;
    int *first_array = (int*)calloc(len1, sizeof(int));

    for (int i = 0; i < len1; i++) {
        first_array[i] = i;
    }

    printArray(first_array, len1);
    resize(first_array, 5, 10);
    printf("\nAfter\n");
    printArray(first_array, newlen);

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


void printArray(int* pointer, int size){
    for(int i = 0; i < size; i++) {
        printf("Number%d: %d\n",(i+1),pointer[i]);
    }
}
