#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// TODO: Include needed header files
#include "another_file.h"

int main() {
    // Set the default state of the variable
    an_example_number = 10;

    // Create variables
    char str[] = "Multiple file inclusion example project string";
    int number = 2;

    // Manipulate numbers
    StringManipulator(str);
    IntegerManipulator(&number);

    // See the results
    printf("Result of StringManipulator(): %s\n", str);
    printf("Result of IntegerManipulator(): %d\n", number);

    return 0;
}
