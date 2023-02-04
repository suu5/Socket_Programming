#include"local.h"

void operate(int sock_fd, const void *obj, socklen_t sock_len){
    bool jump = false;
    const sockaddr *sock_obj = (sockaddr *)obj;
    if(connect(sock_fd, sock_obj, sock_len) != 0){
        printf("Connection fail\n");
        return;
    }
    while(true){
        printf("------------------------\n");
        char read_buffer[BUFFER_SIZE];
        if(read(sock_fd, read_buffer, BUFFER_SIZE) > 0){
            printf("Message from server:\n");
            printf("%s\n", read_buffer);
        }
        printf("Input the number which represents an operation\n");
        printf("1.Sent a message to server\n");
        printf("other:Close the connection\n");
        char choice = '0';
        scanf("%c", &choice);
        while(getchar() != '\n');
        switch(choice){
            case '1':{
                char write_buffer[BUFFER_SIZE];
                printf("Input the message you want to send\n");
                scanf("%[^\n]", write_buffer);
                while(getchar() != '\n');
                send(sock_fd, write_buffer, sock_len, 0);
                printf("The message you have sent is:\n%s\n", write_buffer);
                break;
            }
            default:{
                close(sock_fd);
                printf("Close the connection\n");
                jump = true;
            }
        }
        if(jump) break;
    }
}