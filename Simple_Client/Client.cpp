#include"local.h"

int main(int argc, char *args[]){
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sock_obj;
    socklen_t sock_len = sizeof(struct sockaddr_in);
    sock_obj.sin_family = AF_INET;
    sock_obj.sin_addr.s_addr = inet_addr(SERVER_HOST);
    sock_obj.sin_port = htons(SERVER_PORT);

    operate(sock_fd, &sock_obj, sock_len);

    return 0;
}