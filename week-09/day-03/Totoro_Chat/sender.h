#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#define MESSAGE_LEN 1024

#include <winsock2.h>

void send_message_to_user(char *temp_message);
void send_broadcast_message();
void send_message_to_discovery(char *partner_ip, int partner_discovery_port);

//inside functions
void handle_error(const char *error_string);
void connect_to_server(SOCKET *client_sock, char *server_ip, int server_port);
int send_message(SOCKET *socket, char *msg);


#endif // SENDER_H_INCLUDED
