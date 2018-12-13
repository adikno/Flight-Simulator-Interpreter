//
// Created by michal on 12/12/18.
//

#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include <cstring>

struct Client {
    int port;
    const char *IP;

    Client(int a, const char *b) {
        this->port = a;
        this->IP = b;

    }

    void operator()() const {
        int sockfd, portno, n;
        struct sockaddr_in serv_addr;
        struct hostent *server;

        char buffer[256];



        portno = this->port;

        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        server = gethostbyname(this->IP);
        if (server == NULL) {
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(portno);

        /* Now connect to the server */
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(1);
        }

        /* Now ask for a message from the user, this message
           * will be read by server
        */


        while (buffer != "") {
            printf("Please enter the message: ");
            bzero(buffer, 256);
            fgets(buffer, 255, stdin);
            n = write(sockfd, buffer, strlen(buffer));
        }
        /* Send message to the server */


        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

    }
};