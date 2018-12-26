

#ifndef UNTITLED9_CONNECTCOMMAND_H
#define UNTITLED9_CONNECTCOMMAND_H

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
#include "Maps.h"
#include "CommandExpression.h"

class ConnectCommand: public Command {
    pthread_t trid;
public:

    int doCommand(vector<string> &x) override;

    const vector<string> split(const string& s, const char& c);

    ~ConnectCommand() {
        pthread_join(trid, nullptr);
    }
};
#endif //UNTITLED9_CONNECTCOMMAND_H
