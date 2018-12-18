//
// Created by michal on 12/18/18.
//

#include "ClientThread.h"
/*
void* ClientThread::clientThread(void* arg) {
    ClientParams* params = (ClientParams*) arg;

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    portno = params->getPort();

    // Create a socket point
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(params->getIP());
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Now connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Now ask for a message from the user, this message
    //will be read by server
    while (true) {
        if (params->getInstruction() != "") {
            n = write(sockfd, params->getInstruction(), strlen(buffer));
            params->setInstruction("");
            // Send message to the server
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    }
}
*/