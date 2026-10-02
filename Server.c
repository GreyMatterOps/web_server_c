#include"Server.h"

int start_server(const char *port)
{
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    printf("1. before getaddrinfo\n");

    int status = getaddrinfo(NULL, port, &hints, &res);

    printf("2. after getaddrinfo\n");

    if (status != 0)
    {
        printf("getaddrinfo failed: %s\n", gai_strerror(status));
        return -1;
    }

    int sockfd = socket(res->ai_family,
                        res->ai_socktype,
                        res->ai_protocol);

    printf("3. after socket\n");

    if (sockfd == -1)
    {
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }

    if (bind(sockfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        perror("bind");
        freeaddrinfo(res);
        close(sockfd);
        return -1;
    }

    printf("4. after bind\n");

    freeaddrinfo(res);

    if (listen(sockfd, 10) == -1)
    {
        perror("listen");
        close(sockfd);
        return -1;
    }

    printf("5. after listen\n");

    return sockfd;
}

int main(void)
{
    printf("A\n");

    int server_fd = start_server("9000");

    printf("B\n");

    printf("server_fd = %d\n", server_fd);

    printf("server started lessgo\n");
    int i =0;
    while (1)
    {
    
    int client_fd = accept(server_fd, NULL, NULL);

    printf("Client connected\n");

    const char *message = "Hello from server!\n";

    send(client_fd, message, strlen(message), 0);

   
    close(client_fd);

    printf("Client fd closed\n");
    }

    return 0;
}