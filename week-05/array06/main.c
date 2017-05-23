#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function which receives a string as parameter, and returns
// the numbers of characters in the string.
// Don't use the strlen() function!
int CountCharacters(char *ptr);

int main()
{
    char astring[] = "Totoro";
    int howmany = CountCharacters(astring);

    printf("There is %d character in %s", howmany, astring);

    return 0;
}

int CountCharacters(char *input_str){
    int len = 0;

    while (*input_str != '\0') {
        input_str++;
        len++;
    }

    return len;
}
