#ifndef SERVER_H
#define SERVER_H
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
struct Server {
    int domain;
    int service;
    int protocol;
    unsigned long interface;
    int port;
    int backlog;
    
    struct sockaddr_in address;

    int sockfd;

    void (*launch)(struct Server *server);
};



struct Server server_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog, void (*launch)(struct Server *server));
#endif