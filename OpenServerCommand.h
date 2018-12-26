
#ifndef UNTITLED9_OPENDATACOMMAND_H
#define UNTITLED9_OPENDATACOMMAND_H

#include "Command.h"
#include <string.h>
#include <stdlib.h>
#include <thread>
#include "Maps.h"

class OpenServerCommand : public Command{
    pthread_t trid;
public:
    OpenServerCommand(){}
    int doCommand(vector<string> &x) override;

    ~OpenServerCommand() {
        pthread_join(trid, nullptr);
    }

};
#endif //UNTITLED9_OPENDATACOMMAND_H
