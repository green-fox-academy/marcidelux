/**
*   Totoro Chat software
*   Author: Marton Lorinczi
*   2017.06
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <process.h>

// Own files to be included
#include "FILE_IO.h"
#include "user.h"
#include "sender.h"
#include "broadcast_listener.h"
#include "discovery_listener.h"

// Define things
#define MENU_PATH "tmp/menu.txt"
#define LOG_PATH "tmp/chatlog.txt"

// Functions in main
void system_setup();
void command_handle(char command);
void clear_screen();

// Global variables
WSADATA wsaData;
totoro_user users[50];
int users_len = 0;

int main()
{
    //Local variables in Main
    char command;

    system_setup();

    // Initialize the WSA

    init_users();
    add_user("Pista", 0xff02f2ff , 8765);
    add_user("Kata", 0x0002f2ff , 6666);
    add_user("Zoli", 0x43FF22ff , 5656);

    printf("\n");
    print_active_users();

    totoro_user* user_ptr = find_user_by_name("Kaki");

    if (user_ptr != NULL) {
        struct in_addr temp_ip;
        temp_ip.s_addr = user_ptr -> IP_addr;
        printf("name: %s, IP: %s, PORT: %d\n", user_ptr -> name, inet_ntoa(temp_ip), user_ptr -> Port);
    } else {
        printf("pointer is NULL");
    }

    while (1) {

        if (kbhit()) {
            command = _getch();
        }
        command_handle(command);
        command = 0;

    }

    return 0;
}

void system_setup()
{
    // Print out the menu
    file_print(MENU_PATH);

    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
    }

    _beginthread(broadcast_server, 0, NULL);
   // _beginthread(discovery_server, 0, NULL);
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
        send_broadcast_message(&wsaData);
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
        send_message_to_user("Zoli halobalo");
        printf("\nNext command: ");

    } else if (command == 'a') {
        printf("h - Send message to all users:\n");

        printf("\nNext command: ");

    } else if (command == 'c') {
        clear_screen();

    } else if (command == 'x') {
        printf("h - Spamm all to hell:\n");

        printf("\nNext command: ");
    } else if (command == 0) {

    }
}

void clear_screen() {
    system("@cls||clear");
    file_print(MENU_PATH);
}













