#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_USER_NUM 50
#define USER_NAME_LEN 255

typedef struct {
    char name[USER_NAME_LEN];
    char IP_addr[15];
    int Port;
} totoro_user;

typedef struct {
    totoro_user users[50];
    int users_len;
} totoro_users;

totoro_users totoro_user_list;

// functions
void add_user(char *name, char *IP, int port);
void print_active_users();
totoro_user* find_user_by_name(char *user_name);

#endif // USER_H_INCLUDED
