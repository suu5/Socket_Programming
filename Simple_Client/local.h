#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define SERVER_HOST "127.0.0.1"
#define SERVER_PORT 1234
#define BUFFER_SIZE 1024

void operate(int sock_fd, const void *sock_obj, socklen_t sock_len);