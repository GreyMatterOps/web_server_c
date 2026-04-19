#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include "Server.h"
void launch(struct Server *server){
    printf("4\n");
    char buffer[30000];
    while(1)
    {
        printf("5\n");
        
        printf("===== WAITING FOR CONNECTION =====\n");
        
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int new_socket = accept(
            server->sockfd,
            (struct sockaddr*)&client_addr,
            &client_len
        );

        if (new_socket < 0) {
            perror("accept failed");
            continue;
        }   

        int bytes = read(new_socket,buffer,sizeof(buffer)-1);
        if(bytes<0){
            perror("read failed");
            return;
        }
        buffer[bytes]='\0';
        
        printf("%s\n",buffer);
        
        const char *body = "<html><body><h1>Hello, World!</h1></body></html>";

        char response[1024];
        sprintf(response,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %ld\r\n"
            "Connection: close\r\n"
            "\r\n"
            "%s",
            strlen(body), body
        );

        write(new_socket, response, strlen(response));
        close(new_socket);
    }
}
int main(){
    printf("1\n");
    struct Server server=server_constructor(AF_INET,SOCK_STREAM,0,INADDR_ANY,8081,10,launch);
    printf("2\n");
    server.launch(&server);
}