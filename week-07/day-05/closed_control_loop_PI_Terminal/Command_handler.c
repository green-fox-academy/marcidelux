#include "command_handler.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char port_name[50];
int port_index;
char decide[1];
char input;
char write_file_name[100];
char read_file_name[100];
int log_on = 1;

//variables for logging
int port_opened = 0;
char buffer[1];
char temp[100];
int temp_int;
int avarage_array[10];
int i = 0;
time_t curtime;
struct tm *lt;
float avarage;

void command_execution(char *instruction)
{
    if (strcmp(instruction, "l") == 0) {
        list_aviable_ports();
    } else if (strcmp(instruction, "p") == 0) {
        set_port_name();
    } else if (strcmp(instruction, "o") == 0) {
        open_port();
    } else if (strcmp(instruction, "c") == 0) {
        close_port();
    } else if (strcmp(instruction, "w") == 0) {
        set_write_file_name();
    } else if (strcmp(instruction, "s") == 0) {
        logging_temperature();
    } else if (strcmp(instruction, "r") == 0) {
        set_read_file_name();
    } else if (strcmp(instruction, "a") == 0) {
        ;
    }else   if (strcmp(instruction, "e") == 0) {
        exit_program();
    } else {
        printf("Invalid instruction!\n");
        Sleep(1000);
        clear_screen();
        file_print("tmp/menu.txt");
    }
}

void exit_program(){
    printf("program will shut down in:\n");
    for (int i = 3; i >=1; i--) {
        printf("%d..\n",i);
        Sleep(1000);
    }
    exit(0);
}

void list_aviable_ports()
{
    int num_of_ports = comEnumerate();

    printf("\nAviable ports: ");
    for (int i = 0; i < num_of_ports; i++) {
        printf("%s, ", comGetPortName(i));
    }
    printf("\n-> Next command:");
}

void set_port_name()
{
    printf("Which port should be used? ");
    scanf("%s", &port_name);
    port_index = comFindPort(port_name);
    printf("\n-> Next command:");
}


void show_command_list(){

    printf("Clear screen before print commands (y/n)?");
    scanf("%s", decide);

    if(sizeof(decide) > 1) {
        printf("\nError! Type y/n next time.\n");
    } else if (strcmp(decide, "y") == 0) {
        clear_screen();
        file_print("tmp/menu.txt");
    } else if (strcmp(decide, "n") == 0) {
        printf("\n");
        file_print("tmp/menu.txt");
    } else {
        printf("\nError! Type y/n next time.\n");
    }
}

void open_port()
{
    if (port_name[0] == '\0') {
        printf("Invalid port name!");
        printf("\n-> Next command:");
    } else {
        comOpen(port_index, BITRATE);
        port_opened = 1;
        printf("%s has been opened.", port_name);
        printf("\n-> Next command:");
    }
}

void close_port()
{
    if (port_name[0] == '\0') {
        printf("Invalid port name!");
        printf("\n-> Next command:");
    } else {
        comClose(port_index);
        port_opened = 0;
        printf("%s has been closed.", port_name);
        printf("\n-> Next command:");
    }
}

void set_write_file_name()
{
    printf("Give a file name for saving temperature logs, [format->(*.txt)]: ");
    scanf("%s", write_file_name);
    printf("\n-> Next command:");
}

void set_read_file_name()
{
    printf("Give a file name for read log, [format->(*.txt)]: ");
    scanf("%s", read_file_name);
    printf("\n-> Next command:");
}

void logging_temperature()
{
    int sleep = 0;

    if(port_opened == 0) {
        printf("File was not opened!");
        printf("\n-> Next command:");
        return;
    }
/*
    FILE *log;
    log = fopen(write_file_name, "w");

    if (log == NULL) {
        printf("Error opening file!\n");
    }
*/
    while(log_on) {

        if (_kbhit() != 0) {
            input = _getch();
        }

        if(input == 's') {
            printf("\n-> Next command:");
            input = 'q';
            log_on = 0;
        }

        if (comRead(port_index, buffer, 1)) {


            if (buffer[0] != '\n') {
                temp[i] = buffer[0];
                i++;
            } else {
                temp[i] = '\0';
                i = 0;

                /*
                curtime = time(NULL);
                lt = localtime(&curtime);
                fprintf(log, "%d-%d-%d %d:%d:%d\t", lt -> tm_year + 1900, lt -> tm_mon, lt -> tm_mday,
                                                 lt ->tm_hour, lt ->tm_min, lt->tm_sec);
                fputs(temp, log);
                fprintf(log, "\n");
                */
                //printf("RPM: ");
                puts(temp);

                sleep = 1;
            }
        }

        if (sleep == 1) {
            Sleep(50);
            clear_screen();
            sleep = 0;
        }
    }

    //fclose(log);
    log_on = 1;
}


void clear_screen()
{
    system("@cls||clear");
}
