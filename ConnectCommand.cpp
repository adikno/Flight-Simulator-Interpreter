//
// Created by michal on 12/12/18.
//

#include "ConnectCommand.h"



void* clientThread(void* arg) {
    ClientParams* params = (ClientParams*) arg;

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    portno = params->getPort();

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(params->getIP().data());
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
        if (params->getInstruction() != "") {
            n = write(sockfd, params->getInstruction().data(), strlen(buffer));
            params->setInstruction("");
            /* Send message to the server */
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
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
                if(!(num0 <=0 && num0 <= 255)){
                    throw 1;
                }
            }
            num1 = stoi(x.at(1));
        } catch (out_of_range &exception1){
            throw "illegal arguments";
        } catch (int x){
            throw "illegal arguments";
        }
        const char *p_data  = x.at(0).data();
        clientParams->setIp(p_data);
        clientParams->setPort(num1);
        pthread_t trid;
        pthread_create(&trid, nullptr, clientThread, &clientParams);

        return 2;

}
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
    return v;
}

