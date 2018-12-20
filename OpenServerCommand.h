//
// Created by michal on 12/20/18.
//

#ifndef UNTITLED9_OPENDATACOMMAND_H
#define UNTITLED9_OPENDATACOMMAND_H

#include "Command.h"
#include <string.h>
#include <stdlib.h>
#include <thread>
#include "Maps.h"

class OpenServerCommand : public Command{

    int doCommand(vector<string> &x) override;

};
#endif //UNTITLED9_OPENDATACOMMAND_H
