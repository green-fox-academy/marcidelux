#include <stdio.h>
#include <stdlib.h>
int* Range(int first, int to, int step);
void printArray(int* pointer, int size);
/** TODO:
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

 int SIZEOFARRAY;

int main() {

    int* numbers;
    int first = 5;
    int to = 10;
    int step = 2;

    numbers = Range(first, to, step);

    printArray(numbers, SIZEOFARRAY);

    free(numbers);
    return 0;
}


int* Range(int first, int to, int step){

    SIZEOFARRAY = 0;
    for (int i = first; i < to; i += step){
        SIZEOFARRAY++;
    }
    printf("%d", SIZEOFARRAY);

    int* range_array = (int*)calloc(SIZEOFARRAY, sizeof(int));
    int cntr = 0;

    for(int i = first; i < to; i += step) {
        range_array[cntr] = i;
        cntr++;
    }

    return range_array;
}

void printArray(int* pointer, int size){
    for(int i = 0; i < size; i++) {
        printf("Number%d: %d\n",(i+1),pointer[i]);
    }
}
