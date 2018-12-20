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
    string ip;
    string instruction;
public:
    ClientParams() {
        this->instruction = "";
    }

    void setIp(string ip) {
        this->ip = ip;
    }

    void setPort(int port) {
        this->port = port;
    }

    void setInstruction(string instruction) {
        this->instruction = instruction;
    }

    int getPort() const {
        return this->port;
    }

    string getIP() const {
        return this->ip;
    }

    string getInstruction() const {
        return this->instruction;
    }
};