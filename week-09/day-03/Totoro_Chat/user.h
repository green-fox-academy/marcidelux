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

// functions
void print_active_users(totoro_user *users, int users_length);
totoro_user* find_user_by_name(totoro_user *users, int users_length, char *user_name);

#endif // USER_H_INCLUDED
