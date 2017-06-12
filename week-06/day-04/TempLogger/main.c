#include <stdio.h>
#include <stdlib.h>
#include "command_handle.h"

int main()
{
    print_menu();
    char command[1];

    while (1) {
        scanf("%s", command);
        command_execution(command);
    }

    return 0;
}
