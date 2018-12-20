

#ifndef UNTITLED9_CONDITIONPARSER_H
#define UNTITLED9_CONDITIONPARSER_H

#include "BooleanExpression.cpp"
#include "Command.h"
#include "queue"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include "Expression.h"
#include "Number.h"
#include <map>
#include <unordered_map>
#include <list>
#include "ParamsCommand.cpp"


extern map<string, Command*> commands;
extern map<string, double> symbolTable;

class ConditionParser: public Command {
private:
    Command *command;
protected:
    map<string,Command*> commands;
    list<ParamsCommand*> innerCommands;

public:
     ConditionParser(map<string,Command*> &commands, list<ParamsCommand*> &innerCommands) :
     commands(commands), innerCommands(innerCommands){}

     int doCommand(vector<string> &x) {
         command->doCommand(x);
     }


};
#endif //UNTITLED9_CONDITIONPARSER_H
