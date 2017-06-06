#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *stresttest;
    char buff[255];
    int number;

    stresttest = fopen("totorotest.txt", "w+");

    if (stresttest == NULL) {
        printf("Error!");
        exit(1);
    }

    printf("Give me a number: ");
    scanf("%d", &number);

    fprintf(stresttest, "%d", number);

    fclose(stresttest);
    return 0;
}

