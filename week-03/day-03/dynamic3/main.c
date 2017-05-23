#include <stdio.h>
#include <stdlib.h>
int* range(int first, int to, int step);
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

int main() {

    int* numbers;
    int first = 0;
    int to = 10;
    int step = 2;
    int size = (to - first) / step;

    numbers = range(first, to, step);

    printArray(numbers, size);

    return 0;
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

