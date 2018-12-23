
#ifndef UNTITLED9_EQUALCOMMAND_H
#define UNTITLED9_EQUALCOMMAND_H


#include <map>
#include <cstring>
#include <sstream>
#include "Command.h"
#include "ShuntingYard.h"


class EqualsCommand : public Command {

public:

    int doCommand(vector<string> &x);

};


#endif //UNTITLED9_EQUALCOMMAND_H
