//
// Created by michal on 12/18/18.
//

#ifndef UNTITLED9_CONNECTCOMMAND_H
#define UNTITLED9_CONNECTCOMMAND_H
#include "Command.h"
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
#include "ClientThread.h"

class ConnectCommand: public Command{


public:
    int doCommand(vector<string> x) override;
    const vector<string> split(const string& s, const char& c);

};
#endif //UNTITLED9_CONNECTCOMMAND_H
