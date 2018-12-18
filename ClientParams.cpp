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

using namespace std;

class ClientParams {
    int port;
    char *IP;
    char* instruction;
public:
    ClientParams() {
        string a = "";
        this->instruction= (char *) malloc(a.size());
        const char* b = a.data();
        strcpy(this->instruction, b);
    }

    void setIp(const char* ip) {
        strcpy(this->IP, ip);
    }

    void setPort(int port) {
        this->port = port;
    }

    void setInstruction(const char *instruction) {
        int length = sizeof(instruction)/sizeof(char);
        this->instruction= (char *) malloc(length);
        strcpy(this->instruction, instruction);
    }

    int getPort() const {
        return this->port;
    }

    char* getIP() const {
        return this->IP;
    }

    char* getInstruction() const {
        return this->instruction;
    }
};