/**
*   Totoro Chat software
*   Author: Marton Lorinczi
*   2017.06
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Own files to be included
#include "FILE_IO.h"
#include "user.h"
#include "sender.h"

// Define things
#define MENU_PATH "tmp/menu.txt"
#define LOG_PATH "tmp/chatlog.txt"

// Functions in main
void system_setup();
void command_handle(char command);
void clear_screen();

// Global variables
totoro_user users[50];

int main()
{
    //Local variables in Main
    char command;

    system_setup();

    strcpy(users[0].IP_addr, "10.27.6.127");
    strcpy(users[0].name, "Kakimaki");
    users[0].Port = 1549;

    strcpy(users[1].IP_addr, "10.21.01.1");
    strcpy(users[1].name, "Fikakiralyno");
    users[1].Port = 3234;

    strcpy(users[2].IP_addr, "10.21.01.2");
    strcpy(users[2].name, "Nyalherceg");
    users[2].Port = 1888;

    while (1) {

        if (kbhit()) {
            command = _getch();
        }
        command_handle(command);
        command = NULL;

    }

    return 0;
}

void system_setup()
{
    // Print out the menu
    file_print(MENU_PATH);
}

void command_handle(char command)
{
    if (command == 'h') {
        printf("h - Display menu:\n");

        printf("\nNext command: ");
    } else if (command == 'e') {
        printf("e - Exit... Good bye\n");
        exit(0);

    } else if (command == 'n') {
        printf("n - Set user name\n");

        printf("Next command: ");
    } else if (command == 'd') {
        printf("d - Send discovery request:\n");

        printf("\nNext command: ");
    } else if (command == 'l') {
        printf("l - List active users:\n");
        print_active_users(users, 3);
        printf("\nNext command: ");
    } else if (command == 's') {
        printf("s - Save users to file:\n");

        printf("\nNext command: ");
    } else if (command == 'p') {
        printf("h - Print users from file:\n");

        printf("\nNext command: ");
    } else if (command == 'm') {
        printf("h - Send message:\n");

        printf("\nNext command: ");
    } else if (command == 'a') {
        printf("h - Send message to all users:\n");

        printf("\nNext command: ");
    } else if (command == 'c') {
        clear_screen();

    } else if (command == 'x') {
        printf("h - Spamm all to hell:\n");

        printf("\nNext command: ");
    } else if (command == NULL) {

    }
}

void clear_screen() {
    system("@cls||clear");
    file_print(MENU_PATH);
}



















