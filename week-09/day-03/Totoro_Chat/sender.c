#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"
#include "sender.h"

#define DATA_BUFFER_SIZE    1024

void handle_error(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}

void wsa_init()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
		handle_error("WSAStartup() ");
}

void connect_to_server(SOCKET *client_sock, char *server_ip, int server_port)
{
	// Creating client socket
	(*client_sock) = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	if (client_sock < 0)
		handle_error("socket() ");

	// Creating server address
	struct sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(server_port);
	addr_in.sin_addr.s_addr = inet_addr(server_ip);

	// Connecting the client socket to the server
	int connect_retval = connect(*client_sock, (struct sockaddr *)&addr_in, sizeof(addr_in));
	if (connect_retval < 0)
		handle_error("connect() ");

	printf("Connected to %s:%d\n", server_ip, server_port);
}

int send_message(SOCKET *socket, char *msg)
{
	// Get the message from the user
	if (strlen(msg) > DATA_BUFFER_SIZE) {
        handle_error("send() ");
        //return 0;
	}
	//printf("\nEnter the message to send: ");
	//gets(msg);

	// Send the message to the servers
	int sent_bytes = send(*socket, msg, strlen(msg), 0);
	if (sent_bytes < 0)
		handle_error("send() ");

	return sent_bytes;
}

void send_message_to_user(char *temp_message, totoro_user *temp_user)
{
	// Initialize the WSA
	wsa_init();

	// Connect to server
	SOCKET client_socket;
	connect_to_server(&client_socket, temp_user->IP_addr, temp_user->Port);

	// Local variables used in the do-while loop
	int sent_bytes;
	int received_bytes;
	char recv_buff[DATA_BUFFER_SIZE];

		// Send data to the server
    sent_bytes = send_message(&client_socket, temp_message);

	printf("Closing the socket...\n");
	closesocket(client_socket);
	printf("Cleaning up memory...\n");
	WSACleanup();

}
