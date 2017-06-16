#include <stdio.h>
#include <stdlib.h>
#include "Command_handler.h"


int main()
{
    file_print("tmp/menu.txt");
    char command[1];

    while (1) {
        scanf("%s", command);
        command_execution(command);
    }

    return 0;
}
