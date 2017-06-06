#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clrscr();
void delay(unsigned int mseconds);

int main()
{
    //int exit = 0;
    char command[255];

    while(1) {
        printf("Todo application\n");
        printf("====================\n");
        printf("-a\tAdds a new task\n");
        printf("-wr\tWrite current todos to file\n");
        printf("-rd\tRead todos from a file\n");
        printf("-l\tLists all the tasks\n");
        printf("-e\tEmpty the list\n");
        printf("-r\tRemoves a task\n");
        printf("-c\tAdd priority to a task\n");
        printf("-lp\tLists all the tasks by priority\n");
        printf("-exit\tExits from Todo\n\n");

        printf("Your command: ");
        scanf("%s", command);
        char command_first[5];
        char command_last[255];

        if (strcmp(strncpy(command_first, command, 2), "-a") == 0) {
            printf("%s\n", command_first);
            strncpy(command_last, command + 2, 255);
            printf("%s", command_last);
            delay(15000);


        } else if (strcmp(command, "-wr") == 0){

        } else if (strcmp(command, "-rd") == 0){

        } else if (strcmp(command, "-l") == 0){clrscr();

        } else if (strcmp(command, "-e") == 0){

        } else if (strcmp(command, "-r") == 0){

        } else if (strcmp(command, "-c") == 0){

        } else if (strcmp(command, "-lp") == 0){

        } else if (strcmp(command, "-exit") == 0){
            exit(0);
        } else {
            printf("!!!!Wrong Command!!!!");
            delay(2000);
        }

        clrscr();

    }
    return 0;
}

void clrscr()
{
    system("@cls||clear");
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
