#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#define MESSAGE_LEN 1024

#include <winsock2.h>

void send_message_to_user(char *temp_message, totoro_user *users,int users_len);
void send_broadcast_message();

//inside functions
void handle_error(const char *error_string);
void wsa_init();
void connect_to_server(SOCKET *client_sock, char *server_ip, int server_port);
int send_message(SOCKET *socket, char *msg);


#endif // SENDER_H_INCLUDED
