#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numbers[] = {5, 6, 7, 8, 9};
    int* number_pointer = &numbers[0]; // ==numbers;
    //TODO:
    // The "number_pointer" should point to the first element of the array called "numbers",
    // than please print its value with it.
    printf("value: %d", *number_pointer);

    return 0;
}

