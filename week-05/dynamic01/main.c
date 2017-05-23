#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pointer = NULL;

    // TODO:
    // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
    // Please delete the array before the program exits
    int len = 5;
    pointer = (int*) calloc(len, sizeof(int));

    for (int i = 0; i < len; i++) {
        pointer[i] = i;
    }

    for (int i = 0; i < len; i++) {
        printf("%d, ", *pointer);
        pointer++;
    }

    free(pointer);

    return 0;
}


