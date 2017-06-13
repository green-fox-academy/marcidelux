#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_IO.h"

void print_menu ()
{
    FILE *f;
    char row[255];

    if ((f = fopen("tmp/menu.txt","r")) == NULL) {
       printf("Error! opening file");
       exit(1);
    }

    while (fgets(row, sizeof(row), f) != NULL) {
        printf("%s", row);
    }

    fclose(f);
}
