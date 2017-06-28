#include "user.h"

void print_active_users(totoro_user *users, int users_length)
{
    printf("IP\t\tPort\tName\n");
    for (int i = 0; i < users_length; i++) {
        printf("%s\t%d\t%s\n", users[i].IP_addr, users[i].Port, users[i].name);
    }
}

totoro_user* find_user_by_name(totoro_user *users, int users_length, char *user_name)
{
    users_length--;
    int i = 0;

    while (strcmp(user_name, users[i].name) != 0) {
        i++;
        if ( i > users_length) {
            printf("There was no user with the given name!\n");
            return NULL;
        }
    }

    totoro_user *user_ptr = &users[i];
    return user_ptr;
}
