
#include "ConnectCommand.h"


/**
 * this function in charge of open socket and bind to the flight simulator
 * @param arg  - holding port num and string of IP
 *
 */
void* clientThread(void* arg) {
    int portno = clientParams.port;
    string ip = clientParams.ip;

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.data());
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
    while (true) {
        if (clientParams.instruction != "") {
            if(clientParams.instruction == "quit"){
                close(sockfd);
                pthread_exit(nullptr);
            }
            pthread_mutex_lock(&mutexIns);
            if(::send(sockfd, clientParams.instruction.data(), strlen(clientParams.instruction.data()),0) <0){
                perror("ERROR writing to socket");
                exit(1);
            }
            //n = write(sockfd, clientParams.instruction.data(), strlen(clientParams.instruction.data()));
            clientParams.instruction = "";
            pthread_mutex_unlock(&mutexIns);
        }
    }

}

int ConnectCommand:: doCommand(vector<string> &x){

        int num0 , num1;
        vector<string> ve = split(x.at(0), '.');
        if(ve.size() !=4){
            throw "illegal arguments";
        }


        try {
            for (int i = 0; i <4 ; ++i) {
                num0 = stoi(ve[i]);
                if(!(num0 >=0 && num0 <= 255)){
                    throw 1;
                }
            }
            num1 = stoi(x.at(1));
        } catch (out_of_range &exception1){
            throw "illegal arguments";
        } catch (int x){
            throw "illegal arguments";
        }
        clientParams.ip =  x.at(0);
        clientParams.port = num1;

        pthread_create(&trid, nullptr, clientThread, nullptr);
        return 2;
}
/**
 * this function split the line of the IP
 * @param s - the IP string
 * @param c char of .
 * @return vector of string
 */
const vector<string> ConnectCommand:: split(const string& s, const char& c) {
    string buff{""};
    vector<string> v;
    for(auto n:s) {
        if(n != c) {
            buff += n;
        }
        else {
            v.push_back(buff);
            buff="";
        }
    }
    v.push_back(buff);
    return v;
}

