#include <stdio.h>
#include <stdlib.h>


/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */
void PrintoutWithPointer(void *ptr);

int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';

    int *numberPtr = &number;
    float *PiPtr = &Pi;
    char *letterPtr = &letter;

    printf("Memory adress with pointer: %p\n", numberPtr);
    printf("Memory adress without pointer: %p\n", &number);

    printf("Memory adress with pointer: %p\n", PiPtr);
    printf("Memory adress without pointer: %p\n", &Pi);

    printf("Memory adress with pointer: %p\n", letterPtr);
    printf("Memory adress without pointer: %p\n", &letter);


    return 0;
}


