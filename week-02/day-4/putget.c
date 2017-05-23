#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer2[255];   // Buffer variable for user input
    //TODO:
    // Get the user's name with gets
    printf("Name?\n");
    gets(buffer2);
    //TODO:
    // Print it out with puts
    printf("Your name is:");
    puts(buffer2);
    //TODO:
    // Get the user's pet name with getch
    printf("Your dogs name?");
    gets(buffer2);
    //TODO:
    // Print it out
    printf("Your dogs name is:");
    puts(buffer2);

    return 0;
}
