#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 1234;
    int* number_pointer = &number;
    //TODO:
    // print the value of number using the "number_pointer"
    printf("Value with pointer: %d", *number_pointer);

    return 0;
}