#include <stdio.h>
#include <string.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

    //TODO:
    // Print out the two arrays character-by-character
    int length1 = sizeof(char_array)/sizeof(char_array[0]);
    printf("Array1: ");
    for (int i = 0; i < length1; i++) {
        printf("%c", char_array[i]);
    }
    printf("\n");
    int length2 = sizeof(char_array_the_same)/sizeof(char_array_the_same[0]);
    printf("Array2: ");
    for (int i = 0; i < length2; i++) {
        printf("%c", char_array_the_same[i]);
    }

    //TODO:
    // What is the difference between the arrays?

    return 0;
}
