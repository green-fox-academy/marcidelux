#include "user.h"
#include <winsock2.h>

void add_user(char *name, int IP, int port)
{
    int index = totoro_user_list.users_len;
    strcpy(totoro_user_list.users[index].name, name);
    totoro_user_list.users[index].IP_addr = IP;
    totoro_user_list.users[index].Port = port;
    totoro_user_list.users_len++;
}

void init_users() {
    totoro_user_list.users_len = 0;
}

void print_active_users()
{
    struct in_addr temp_ip;
    printf("IP\t\tPort\tName\n");
    for (int i = 0; i < totoro_user_list.users_len; i++) {
        temp_ip.s_addr = totoro_user_list.users[i].IP_addr;
        printf("%s\t%d\t%s\n", inet_ntoa(temp_ip), totoro_user_list.users[i].Port, totoro_user_list.users[i].name);
    }
}

totoro_user* find_user_by_name(char *user_name)
{
    totoro_users kaki = totoro_user_list;

    int i = 0;

   // printf("%s\n", user_name);

    while (strcmp(user_name, totoro_user_list.users[i].name) != 0) {
        i++;
        if ( i >= totoro_user_list.users_len) {
            printf("There was no user with the given name!\n");
            return NULL;
        }
    }

    totoro_user *user_ptr = &(totoro_user_list.users[i]);

    return user_ptr;
}

void save_user_to_list(char *name, int user_discovery_port, struct in_addr user_addres)
{
    totoro_user *user_ptr;

    if (find_user_by_name(name) == NULL) {
        printf("%s is already in active user list", name);

    }
}







